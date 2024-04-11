#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <deque>
#include <bitset>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main () {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  vector<vector<long long>> A(n);
  vector<long long> sum_all(n);
  vector<long long> max_pref_sum(n);
  vector<long long> max_suff_sum(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    A[i].resize(x);
    for (int j = 0; j < x; ++j) {
      cin >> A[i][j];
      sum_all[i] += A[i][j];
    }
    max_pref_sum[i] = A[i][0];
    long long cur = A[i][0];
    for (int j = 1; j < x; ++j) {
      cur += A[i][j];
      max_pref_sum[i] = max(max_pref_sum[i], cur);
    }
    max_suff_sum[i] = 0;
    cur = 0;
    for (int j = x - 1; j >= 0; --j) {
      cur += A[i][j];
      max_suff_sum[i] = max(max_suff_sum[i], cur);
    }
  }
  vector<int> ids(m);
  for (int i = 0; i < m; ++i) {
    cin >> ids[i];
    --ids[i];
  }
  long long mx_prev = 0;
  long long ans = -1e18;
  for (int i = 0; i < m; ++i) {
    ans = max(ans, mx_prev + max_pref_sum[ids[i]]);
    mx_prev = max(mx_prev + sum_all[ids[i]], max_suff_sum[ids[i]]);
  }
  vector<bool> used(n, false);
  for (int id : ids)
    used[id] = true;
  for (int i = 0; i < n; ++i) {
    if (!used[i])
      continue;
    long long mn_pref_sum = 0;
    long long cur_pref_sum = 0;
    for (int l = 0; l < (int) A[i].size(); ++l) {
      cur_pref_sum += A[i][l];
      ans = max(ans, cur_pref_sum - mn_pref_sum);
      mn_pref_sum = min(mn_pref_sum, cur_pref_sum);
    }
  }
  cout << ans << '\n';
  return 0;
}