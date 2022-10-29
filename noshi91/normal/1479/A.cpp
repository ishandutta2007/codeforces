#include <utility>

using i64 = long long;

template <class F> i64 discrete_golden_section_search(i64 min, i64 max, F f) {
  min -= 1;
  max += 1;
  i64 a = 1, b = 1;
  while (a + b < max - min) {
    a += b;
    std::swap(a, b);
  }
  auto l = f(min + a), r = f(min + b);
  while (a < b) {
    b -= a;
    std::swap(a, b);
    if (l < r) {
      r = l;
      l = f(min + a);
    } else {
      min += b;
      if (min + b < max) {
        l = r;
        r = f(min + b);
      } else {
        b -= a;
        std::swap(a, b);
        l = f(min + a);
      }
    }
  }
  return min + 1;
}

#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int ans = discrete_golden_section_search(1, n, [](int i) {
    std::cout << "? " << i << std::endl;
    int a;
    std::cin >> a;
    return a;
  });

  std::cout << "! " << ans << std::endl;

  return 0;
}