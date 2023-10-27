#include <GLFW/glfw3.h>
#include <webgpu/webgpu.h>
#include <iostream>

int main(int, char**) {
    // Create descriptor
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = nullptr;

    // Create instance using descriptor
    WGPUInstance instance = wgpuCreateInstance(&desc);
    if (!instance) {
        std::cerr << "Could not initialize WebGPU!" << std::endl;
        return 1;
    }

    glfwInit();
    if (!glfwInit()) {
        std::cerr << "Could not initialize GLFW!" << std::endl;
        return 1;
    }
    // Create the window
    GLFWwindow* window = glfwCreateWindow(800, 600, "WebGPU Playground", NULL, NULL);
    if (!window) {
        std::cerr << "Could not open window!" << std::endl;
        glfwTerminate();
        return 1;
    }

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Check whether the user clicked on the close button (and any other
        // mouse/key event, which we don't use so far)
        glfwPollEvents();
    }

    // Destroy lifecycle
    // Clean up WebGPU instances
    wgpuInstanceRelease(instance);
    // Destroy window
    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}