#include <bits/stdc++.h>
using namespace std;
 
const int N = 300005;

int n, m, k;
int a[N];
char s[N];

vector<int> edges[N];
int cnt[N];

int dp[N];
int f(int x) {
  if (~dp[x]) return dp[x];
  dp[x] = 1;
  for (int v : edges[x]) dp[x] = max(dp[x], 1 + f(v));
  return dp[x];
}

int solve() {
  scanf("%d %d", &n, &m);

  vector<tuple<int, int, int>> points(m * 2);
  for (int i = 0; i < m; ++i) {
    int idx, l, r;
    scanf("%d %d %d", &idx, &l, &r);
    --idx;
    points[i*2 + 0] = make_tuple(l, -1, idx);
    points[i*2 + 1] = make_tuple(r, +1, idx);
  }
  sort(points.begin(), points.end());

  int nums = 0;
  set<int> intersects;
  for (int i = 0; i < m*2; ++i) {
    int x, t, idx;
    tie(x, t, idx) = points[i];

    int l = -1, r = -1;
    auto it = intersects.lower_bound(idx);
    if (it != intersects.end() && *it == idx) {
      auto nit = next(it);
      if (nit != intersects.end()) r = *nit;
      if (it != intersects.begin()) l = *prev(it);
    } else {
      if (it != intersects.end()) r = *it;
      if (it != intersects.begin()) l = *prev(it);
    }

    // cerr << "asfd: " << l << " " << idx << " " << r << endl;

    if (t == -1) {
      if (cnt[idx]++ == 0) {
        intersects.insert(idx);
        if (l != -1) edges[l].push_back(idx);
        if (r != -1) edges[idx].push_back(r);
      }
    } else {
      if (--cnt[idx] == 0) {
        intersects.erase(idx);
        if (l != -1 && r != -1) edges[l].push_back(r);
      }
    }
  }

  memset(dp, -1, sizeof dp);

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (f(i) > f(ans)) ans = i;
  }

  int maxseg = f(ans);
  vector<bool> vis(n, true);
  while (f(ans) > 1) {
    vis[ans] = false;
    for (int v : edges[ans]) {
      if (f(v) + 1 == f(ans)) {
        ans = v;
        break;
      }
    }
  }
  vis[ans] = false;

  printf("%d\n", n - maxseg);
  for (int i = 0; i < n; ++i) {
    if (vis[i]) printf("%d ", i + 1);
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}