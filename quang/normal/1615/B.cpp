#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int LOG = 20;

int cnt[LOG][N];

void Solve(int test) {
  int l, r;
  cin >> l >> r;
  int res = 0;
  for (int i = 0; i < LOG; i++) {
    res = max(res, cnt[i][r] - cnt[i][l - 1]);
  }
  cout << (r - l + 1) - res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < LOG; j++) {
      cnt[j][i] = cnt[j][i - 1] + (i >> j & 1);
    }
  }

  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}