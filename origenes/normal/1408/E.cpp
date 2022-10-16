#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

int n, m;
int a[maxn], b[maxn], par[maxn * 2];
vector<tuple<int, int, int>> edges;

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

int main() {
  scanf("%d%d", &m, &n);
  FOR(i, 1, m) scanf("%d", a + i);
  FOR(i, 1, n) scanf("%d", b + i);
  FOR(i, 1, m) {
    int s; scanf("%d", &s);
    while (s--) {
      int j; scanf("%d", &j);
      edges.eb(a[i] + b[j], i, j + m);
    }
  }
  sort(all(edges), greater<>());
  iota(par + 1, par + m + n + 1, 1);
  ll ans = 0;
  for (auto [w, u, v] : edges) {
    u = Find(u), v = Find(v);
    if (u == v) ans += w;
    else par[u] = v;
  }
  printf("%lld", ans);
}