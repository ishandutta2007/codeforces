#line 1 "/mnt/c/Users/noshi/Desktop/base_/Library/algorithm/smawk.cpp"
#include <cstddef>
#include <functional>
#include <numeric>
#include <vector>

template <class Select>
std::vector<std::size_t> smawk(const std::size_t row_size,
                               const std::size_t col_size,
                               const Select &select) {
  using size_t = std::size_t;
  using vec_zu = std::vector<size_t>;

  const std::function<vec_zu(const vec_zu &, const vec_zu &)> solve =
      [&](const vec_zu &row, const vec_zu &col) -> vec_zu {
    const size_t n = row.size();
    if (n == 0)
      return {};
    vec_zu c2;
    for (const size_t i : col) {
      while (!c2.empty() && select(row[c2.size() - 1], c2.back(), i))
        c2.pop_back();
      if (c2.size() < n)
        c2.push_back(i);
    }
    vec_zu r2;
    for (size_t i = 1; i < n; i += 2)
      r2.push_back(row[i]);
    const vec_zu a2 = solve(r2, c2);
    vec_zu ans(n);
    for (size_t i = 0; i != a2.size(); i += 1)
      ans[i * 2 + 1] = a2[i];
    size_t j = 0;
    for (size_t i = 0; i < n; i += 2) {
      ans[i] = c2[j];
      const size_t end = i + 1 == n ? c2.back() : ans[i + 1];
      while (c2[j] != end) {
        j += 1;
        if (select(row[i], ans[i], c2[j]))
          ans[i] = c2[j];
      }
    }
    return ans;
  };
  vec_zu row(row_size);
  std::iota(row.begin(), row.end(), 0);
  vec_zu col(col_size);
  std::iota(col.begin(), col.end(), 0);
  return solve(row, col);
}

/**
 * @brief SMAWK Algorithm
 * @see http://www.cs.ust.hk/mjg_lib/bibs/DPSu/DPSu.Files/p285-aggarwal.pdf
 */
#line 2 "/mnt/c/Users/noshi/Desktop/base_/Library/algorithm/concave_max_plus_convolution.cpp"

#include <cstddef>
#include <vector>

template <class T>
std::vector<T> concave_max_plus_convolution(const std::vector<T> &a,
                                            const std::vector<T> &b) {
  using size_t = std::size_t;

  const size_t n = a.size();
  const size_t m = b.size();
  const auto get = [&](const size_t i, const size_t j) {
    return a[j] + b[i - j];
  };
  const std::vector<size_t> amax =
      smawk(n + m - 1, n, [&](const size_t i, const size_t j, const size_t k) {
        if (i < k)
          return false;
        if (i - j >= m)
          return true;
        return get(i, j) <= get(i, k);
      });
  std::vector<T> c(n + m - 1);
  for (size_t i = 0; i != n + m - 1; i += 1)
    c[i] = get(i, amax[i]);
  return c;
}

/**
 * @brief Concave Max Plus Convlution
 * @see https://arxiv.org/abs/1802.06440
 */
#line 1 "/mnt/c/Users/noshi/Desktop/base_/Library/other/ceildiv.cpp"
template <class T> T ceildiv(const T &n, const T &d) {
  return n / d + (n % d != 0 ? 1 : 0);
}
#line 1 "/mnt/c/Users/noshi/Desktop/base_/Library/other/int_alias.cpp"
#include <cstddef>
#include <cstdint>

using i32 = std::int32_t;
using i64 = std::int64_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using isize = std::ptrdiff_t;
using usize = std::size_t;
#line 4 "/mnt/c/Users/noshi/Desktop/base_/Library/algorithm/axiotis_tzamos_knapsack.cpp"

#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>

template <class I>
u64 axiotis_tzamos_knapsack(const usize t, const std::vector<I> &item) {
  assert(t > 0);

  std::vector<std::vector<i64>> bucket(t);
  for (const I &e : item) {
    assert(e.w > 0);
    assert(e.v > 0);

    if (e.w < t)
      bucket[e.w].push_back(e.v);
  }

  std::vector<i64> dp(t, std::numeric_limits<i64>::lowest());
  dp[0] = 0;
  for (usize w = 1; w != t; w += 1) {
    std::vector<i64> &list = bucket[w];
    if (list.empty())
      continue;
    std::sort(list.begin(), list.end(), std::greater<i64>());
    const usize m = std::min(list.size(), ceildiv(t, w));
    std::vector<i64> sum(m + 1);
    sum[0] = 0;
    for (usize i = 0; i != m; i += 1)
      sum[i + 1] = sum[i] + list[i];
    for (usize k = 0; k != w; k += 1) {
      const usize n = ceildiv(t - k, w);
      std::vector<i64> v(n);
      for (usize i = 0; i != n; i += 1)
        v[i] = dp[i * w + k];
      const std::vector<i64> res = concave_max_plus_convolution(v, sum);
      for (usize i = 0; i != n; i += 1)
        dp[i * w + k] = res[i];
    }
  }
  return *std::max_element(dp.begin(), dp.end());
}

/**
 * @brief Axiotis-Tzamos Knapsack
 * @see https://arxiv.org/abs/1802.06440
 */
#line 2 "temp0.cpp"

#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  usize n, m;
  std::cin >> n >> m;
  struct item_t {
    i64 w, v;
  };
  std::vector<item_t> is(n);
  for (auto &e : is) {
    std::cin >> e.w >> e.v;
  }
  std::cout << axiotis_tzamos_knapsack(m + 1, is) << std::endl;
}