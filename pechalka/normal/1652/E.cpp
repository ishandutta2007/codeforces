#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int K = 317;
unordered_map<int, int> dp[100'100];

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  vector<long long> vals(n);
  int ans = 0;
  for (int h = -K; h <= K; ++h) {
    for (int i = 0; i < n; ++i)
      vals[i] = A[i] - h * 1ll * i;
    sort(vals.begin(), vals.end());
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      ++cur;
      ans = max(ans, cur);
      if (i + 1 == n || vals[i + 1] != vals[i])
        cur = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = max(0, i - K); j < i; ++j) {
      int d = A[i] - A[j];
      if (d % (i - j) != 0)
        continue;
      int h = d / (i - j);
      auto tmp = dp[j].find(h);
      if (tmp != dp[j].end())
        dp[i][h] = (tmp->second) + 1;
      else
        dp[i][h] = 2;
      ans = max(ans, dp[i][h]);
    }
  }
  cout << n - ans << '\n';
  return 0;
}