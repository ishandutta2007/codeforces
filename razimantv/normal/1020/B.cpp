#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> next_vertex(N), final_vertex(N, -1);
  for (int i = 0; i < N; ++i) {
    std::cin >> next_vertex[i];
    next_vertex[i]--;
  }

  for (int i = 0; i < N; ++i) {
    if (final_vertex[i] != -1) continue;

    std::vector<int> path;
    int vertex = i;
    for (; final_vertex[vertex] == -1; vertex = next_vertex[vertex]) {
      path.push_back(vertex);
      final_vertex[vertex] = -2;
    }

    if (final_vertex[vertex] == -2) {
      int temp;
      do {
        temp = path.back();
        path.pop_back();
        final_vertex[temp] = temp;
      } while (temp != vertex);
    }

    for (auto u : path) {
      final_vertex[u] = final_vertex[vertex];
    }
  }

  for (auto u : final_vertex) {
    std::cout << u + 1 << std::endl;
  }
  return 0;
}