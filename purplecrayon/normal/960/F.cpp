#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::map<int, int>> dp(n);

  for (int i = 0; i < n; ++i)
    dp[i][-1] = 0;

  auto qry = [&](int i, int w) {
    return (--dp[i].lower_bound(w))->second;
  };

  for (int mm = 0; mm < m; ++mm) {
    int i, j, w;
    std::cin >> i >> j >> w;
    --i, --j;

    if (i == j) {
      int from = qry(i, w);

      auto [it, placed] = dp[j].emplace(w, 0);
      it->second = from+1;

      while (next(it) != dp[j].end() && it->second >= next(it)->second)
        dp[j].erase(next(it));

      continue;
    }

    // from i to j

    int from = qry(i, w);
    int already = qry(j, w);

    if (from+1 <= already) continue;

    auto [it, placed] = dp[j].emplace(w, 0);
    it->second = from+1;

    while (next(it) != dp[j].end() && it->second >= next(it)->second)
      dp[j].erase(next(it));
  }

  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans = std::max(ans, dp[i].rbegin()->second);

  std::cout << ans << '\n';
}