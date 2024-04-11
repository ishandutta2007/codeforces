#include <utility>
#include <vector>

template <class C, class T = decltype(std::declval<C>().get())>
T incremental_monge_shortest_path(const int n, C init) {
  class env {
  public:
    C mid;
    C last;
    int prev;
  };
  std::vector<env> nodes;
  {
    int n_ = n;
    int d = 0;
    while (n_ != 0) {
      n_ /= 2;
      d += 1;
    }
    nodes.assign(d, {init, init, 0});
  }
  std::vector<T> dp(n + 1, static_cast<T>(0));

  const auto f = [&](const auto &f, const int d, const int r) -> int {
    auto &[mid, last, prev] = nodes[d];
    const int w = 1 << d;
    if ((r >> d) % 2 == 1) {
      for (int i = std::max(0, r - 2 * w); i != r; i += 1) {
        mid.push_back(i);
      }
      const int next = r + w <= n ? f(f, d + 1, r + w) : r - w;
      int argmin = prev;
      dp[r] = dp[argmin] + mid.get();
      for (int i = prev; i != next;) {
        mid.pop_front(i);
        i += 1;
        const T t = dp[i] + mid.get();
        if (dp[r] > t) {
          dp[r] = t;
          argmin = i;
        }
      }
      prev = next;
      return argmin;
    } else {
      for (int i = std::max(0, r - 2 * w); i != r; i += 1) {
        last.push_back(i);
      }
      for (int i = std::max(0, r - 3 * w); i != r - 2 * w; i += 1) {
        last.pop_front(i);
      }
      int argmin = prev;
      for (int i = r - 2 * w; i != r - w;) {
        last.pop_front(i);
        i += 1;
        const T t = dp[i] + last.get();
        if (dp[r] > t) {
          dp[r] = t;
          argmin = i;
        }
      }
      return argmin;
    }
  };

  for (int i = 1; i != n + 1; i += 1) {
    f(f, 0, i);
  }

  return dp[n];
}

#include <cassert>
#include <cstdint>
#include <functional>
#include <utility>

namespace golden_section_search_impl {

using i64 = std::int64_t;

template <class F, class T = decltype(std::declval<F>()(std::declval<i64>())),
          class Compare = std::less<T>>
std::pair<i64, T> golden_section_search(F f, i64 min, i64 max,
                                        Compare comp = Compare()) {
  assert(min <= max);

  i64 a = min - 1, x, b;
  {
    i64 s = 1, t = 2;
    while (t < max - min + 2) {
      std::swap(s += t, t);
    }
    x = a + t - s;
    b = a + t;
  }
  T fx = f(x), fy;
  while (a + b != 2 * x) {
    const i64 y = a + b - x;
    if (max < y || comp(fx, (fy = f(y)))) {
      b = a;
      a = y;
    } else {
      a = x;
      x = y;
      fx = fy;
    }
  }
  return {x, fx};
}

} // namespace golden_section_search_impl

using golden_section_search_impl::golden_section_search;

#include <iostream>
#include <vector>

int main() {
  using i64 = long long;

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int &e : a) {
    std::cin >> e;
    e -= 1;
  }

  struct cost {
    const std::vector<int> *a;
    i64 lambda;
    std::vector<int> count;
    i64 w;

    void pop_front(int l) {
      count[(*a)[l]] -= 1;
      w -= count[(*a)[l]];
    }

    void push_back(int r) {
      w += count[(*a)[r]];
      count[(*a)[r]] += 1;
    }

    i64 get() { return lambda + w; }
  };

  const auto f = [&](const i64 lambda) -> i64 {
    return incremental_monge_shortest_path(
               n, cost({&a, lambda, std::vector<int>(n), 0})) -
           lambda * k;
  };

  std::cout
      << golden_section_search(f, 0, i64(n) * n, std::greater<i64>()).second
      << "\n";

  return 0;
}