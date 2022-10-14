#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> row;
  vector<int> col(m, 1e9);
  vector<int> ans(n * m), ans2(n * m);
  vector<int> pref(n * m);
  for (int i = 0; i < n * m; i++) {
    if (s[i] == '1') {
      col[i % m] = min(col[i % m], i);
      // row[0] at [i, i + m - 1]
      // row[1] at [i + m, i + 2m - 1]
      // row[r] at [i + rm, i + rm + m - 1]
      // col[0] at [i, i + m, i + 2m, ...]
      // col[1] at [i + 1, i + 1 + m, ...]
      // col[x] at [i + x, i + x + m, ...]
      pref[i] += 1;
    } else {
    }
    if (i) pref[i] += pref[i - 1];
  }
  for (int i = 0; i < n * m; i++) {
    int cnt = pref[i] - (i >= m ? pref[i - m] : 0);
    if (cnt != 0) {
      // row[0] is good at time i
      // row[1] is good at time i + m
      ans2[i] += 1;
    }
    if (i >= m) {
      ans2[i] += ans2[i - m];
    }
  }
  for (int i = 0; i < m; i++) {
    if (col[i] >= n * m) continue;
    ans[col[i]] += 1;
  }
  for (int i = 1; i < n * m; i++) {
    ans[i] += ans[i - 1];
  }
  for (int i = 0; i < n * m; i++) {
    cout << ans[i] + ans2[i] << " \n"[i + 1 == n * m];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}