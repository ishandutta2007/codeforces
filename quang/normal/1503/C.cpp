#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
pair<int, int> a[N];
long long dp[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  int max_reach_id = 1;
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    // cout << i << ' ' << max_reach_id << endl;
    dp[i] = dp[max_reach_id] + max(0, a[i].first - a[max_reach_id].first - a[max_reach_id].second);
    if (a[max_reach_id].first + a[max_reach_id].second < a[i].first + a[i].second) {
      max_reach_id = i;
    }
  }
  long long res = dp[n];
  for (int i = 1; i <= n; i++) {
    res += a[i].second;
  }
  cout << res << endl;
  return 0;
}