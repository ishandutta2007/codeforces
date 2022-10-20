#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void Solve(int test) {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int res = INF;

  auto GetEven = [&]() {
    int cnt[2] = {0, 0};
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && t[i] == '0') {
        cnt[0]++;
      }
      if (s[i] == '0' && t[i] == '1') {
        cnt[1]++;
      }
    }
    if (cnt[0] != cnt[1]) return INF;
    return cnt[0] + cnt[1];
  };

  auto GetOdd = [&]() {
    int cnt[2] = {0, 0};
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && t[i] == '1') {
        cnt[0]++;
      }
      if (s[i] == '0' && t[i] == '0') {
        cnt[1]++;
      }
    }
    if (cnt[0] != cnt[1] + 1) return INF;
    return cnt[0] + cnt[1];
  };

  res = min(res, GetEven());
  res = min(res, GetOdd());
  cout << (res == INF ? -1 : res) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}