#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

const int LIM = 400;

bool process_largesets(const std::vector<std::vector<int>>& sets,
                       const std::vector<int>& largesets, int maxval) {
  std::vector<bool> seen(maxval, false);
  for (int Si : largesets) {
    for (int x : sets[Si]) seen[x] = true;

    for (int Sj = 0; Sj < sets.size(); ++Sj) {
      if (Sj >= Si and sets[Sj].size() >= LIM) continue;

      int common = 0;
      for (int x : sets[Sj]) {
        if (seen[x] and ++common == 2) {
          std::cout << Sj + 1 << " " << Si + 1 << "\n";
          return true;
        }
      }
    }

    for (int x : sets[Si]) seen[x] = false;  // Avoid resetting whole vector
  }

  return false;
}

bool process_smallsets(const std::vector<std::vector<int>>& sets,
                       const std::vector<std::vector<int>>& inv, int maxval) {
  std::vector<int> seen(maxval, -1);
  for (int x = 0; x < maxval; ++x) {
    for (int Si : inv[x]) {
      for (int j : sets[Si]) {
        if (j == x) continue;
        if (seen[j] != -1) {
          std::cout << seen[j] + 1 << " " << Si + 1 << "\n";
          return true;
        } else
          seen[j] = Si;
      }
    }
    for (int Si : inv[x]) {
      if (sets[Si].size() > LIM) continue;
      for (int j : sets[Si]) seen[j] = -1;
    }
  }
  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int T;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> sets(N);

    std::unordered_map<int, int> compress;  // Compress range from 10^9 to
                                            // maxval  2x10^5
    int maxval = 0;
    for (int i = 0, ki; i < N; ++i) {
      std::cin >> ki;
      sets[i].resize(ki);
      for (int& x : sets[i]) {
        std::cin >> x;
        if (!compress.count(x)) compress[x] = maxval++;
        x = compress[x];
      }
      std::sort(sets[i].begin(), sets[i].end());  // Sort to ensure pair order
    }

    std::vector<int> largesets;
    std::vector<std::vector<int>> inv(maxval);
    for (int i = 0; i < N; ++i) {
      if (sets[i].size() >= LIM)
        largesets.push_back(i);
      else
        for (int x : sets[i]) inv[x].push_back(i);
    }

    if (!process_largesets(sets, largesets, maxval) and
        !process_smallsets(sets, inv, maxval))
      std::cout << -1 << "\n";
  }
  return 0;
}