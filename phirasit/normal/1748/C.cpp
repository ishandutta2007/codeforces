#include <bits/stdc++.h>

using namespace std;

constexpr int X = 40;

long long dp[X][X];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    map<long long, int> count;
    bool first = true;
    int ans = 0;
    long long prefix_sum = 0LL;
    auto check = [&] () {
      if (!first) {
        int mx = 0;
        count[0]++;
        for (auto [val, c] : count) {
          mx = max(mx, c);
        }
        ans += mx;
      } else {
        ans += count[0];
      }
      first = false;
      count.clear();
      prefix_sum = 0LL;
    };

    for (int i = 0; i < n; ++i) {
      int val;
      cin >> val;

      if (val == 0) {
        check();
      } else {
        prefix_sum += val;
        count[prefix_sum]++;
      }
    }

    check();

    cout << ans << "\n";
  }

  return 0;
}