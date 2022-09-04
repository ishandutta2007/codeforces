#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>


using usize = std::size_t;
using u64 = std::uint_fast64_t;
using u32 = std::uint_fast32_t;
using i32 = std::int_fast32_t;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  usize n, m;
  std::cin >> n >> m;
  std::vector<std::vector<i32>> a(m);
  for (auto &v : a) {
    v.resize(n);
    for (auto &e : v) {
      std::cin >> e;
    }
  }
  usize ans = m;
  std::vector<usize> ansl(m);
  std::iota(ansl.begin(), ansl.end(), 0);
  for (usize i = 0; i < n - 1; i += 1) {
    std::vector<std::pair<i32, usize>> v;
    i32 sum = 0;
    for (usize j = 0; j < m; j += 1) {
      v.emplace_back(a[j][n - 1] - a[j][i], j);
      sum += a[j][i] - a[j][n - 1];
    }
    std::sort(v.rbegin(), v.rend());
    std::vector<usize> cans;
    for (usize j = 0; j < n; j += 1) {
      if (sum >= 0) {
        break;
      }
      cans.push_back(v[j].second);
      sum += v[j].first;
    }
    if (ans > cans.size()) {
      ans = cans.size();
      ansl = std::move(cans);
    }
  }
  std::cout << ans << '\n';
  for (usize i = 0; i < ans; i += 1) {
    if (i != 0) {
      std::cout << ' ';
    }
    std::cout << ansl[i] + 1;
  }
  std::cout << '\n';
  return 0;
}