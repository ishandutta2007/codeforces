#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 2e9;

void Solve(int test) {
  int n;
  cin >> n;
  map<pair<int, int>, int> min_seg;
  pair<int, int> min_val(INF, INF);
  pair<int, int> max_val(-INF, -INF);
  for (int i = 0; i < n; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    if (!min_seg.count({l, r})) {
      min_seg[{l, r}] = c;
    } else {
      min_seg[{l, r}] = min(min_seg[{l, r}], c);
    }
    min_val = min(min_val, {l, c});
    max_val = max(max_val, {r, -c});
    int res = min_val.second - max_val.second;
    if (min_seg.count({min_val.first, max_val.first})) {
      res = min(res, min_seg[{min_val.first, max_val.first}]);
    }
    cout << res << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}