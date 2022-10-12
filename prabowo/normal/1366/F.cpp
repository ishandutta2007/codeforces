#include <bits/stdc++.h>
using namespace std;
 
const int N = 2005;
const int MOD = 1000000007;
 
int n, m, q;
vector<pair<int, int>> edges[N];
 
int dist[N][N];
void computeDist(int u) {
  for (int i = 0; i <= n; ++i) for (int j = 0; j < n; ++j) {
    dist[i][j] = -1;
  }
  dist[0][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int u = 0; u < n; ++u) {
      if (dist[i-1][u] == -1) continue;
      for (pair<int, int> p: edges[u]) {
        int v, w; tie(v, w) = p;
        dist[i][v] = max(dist[i][v], dist[i-1][u] + w);
      }
    }
  }
}
 
int medge[N];
 
int find(int len) {
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret = max(ret, dist[len][i]);
  }
  return ret;
}
 
vector<pair<int, int>> buildHull() {
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    v.emplace_back(medge[i], dist[n][i]);
  }
  sort(v.begin(), v.end());
 
  auto check = [&](pair<int, int> p, pair<int, int> q, pair<int, int> r) {
    return 1LL * (p.second - r.second) * (r.first - q.first) >= 1LL * (q.second - r.second) * (r.first - p.first);
  };
 
  vector<pair<int, int>> ret;
  for (pair<int, int> p: v) {
    while (ret.size() >= 1 && p.first == ret.back().first) ret.pop_back();
    while (ret.size() >= 2 && check(ret[ret.size() - 2], ret.back(), p)) ret.pop_back();
    ret.push_back(p);
  }
 
  return ret;
}
 
int arith(long long a, int step, int n) {
  a %= MOD;
  return (a + (a + 1LL*(n-1)*step)) % MOD * n % MOD * 500000004 % MOD;
}
 
int solve() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
 
    edges[u].push_back(make_pair(v, w));
    edges[v].push_back(make_pair(u, w));
 
    medge[u] = max(medge[u], w);
    medge[v] = max(medge[v], w);
  }
 
  computeDist(0);
 
  int ans = 0;
  for (int i = 0; i < n-1; ++i) {
    ans = (1LL * ans + find(i+1)) % MOD;
  }
 
  vector<pair<int, int>> hull = buildHull();
 
  // cerr << "OK" << endl;
  // cerr << hull[0].first << " " << hull[0].second << endl;
  int cur = 0, inter;
  for (int i = 1; i < hull.size(); ++i) {
    // cerr << hull[i].first << " " << hull[i].second << endl;
    inter = (hull[i-1].second - hull[i].second) / (hull[i].first - hull[i-1].first);
    if (hull[i-1].second < hull[i].second) continue;
    if (inter < cur) continue;
    if (cur > q-n) continue;
 
    ans = (ans + arith(1LL * hull[i-1].first * cur + hull[i-1].second, hull[i-1].first, min(q-n, inter) - cur + 1)) % MOD;
    cur = inter + 1;
  }
 
  if (cur <= q-n) {
    ans = (ans + arith(1LL * hull.back().first * cur + hull.back().second, hull.back().first, q-n - cur + 1)) % MOD;
  }
 
  printf("%d\n", ans);
  return 0;
}
 
 
int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}