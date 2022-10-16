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

const int maxn = 2123;

int n;
int x[maxn], y[maxn], c[maxn], k[maxn], par[maxn];

inline ll dis(int i, int j) {
  return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int Find(int u) {
  return par[u] == u ? par[u] : par[u] = Find(par[u]);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d", x + i, y + i);
  FOR(i, 1, n) scanf("%d", c + i);
  FOR(i, 1, n) scanf("%d", k + i);
  iota(par, par + n + 1, 0);
  vector<pair<ll, pii>> edges;
  FOR(i, 1, n) edges.eb(c[i], mp(0, i));
  FOR(i, 1, n) FOR(j, i + 1, n) edges.eb(dis(i, j) * (k[i] + k[j]), mp(i, j));
  sort(all(edges));
  ll cost = 0;
  vector<int> pw;
  vector<pii> w;
  for (auto e : edges) {
    ll d = e._1;
    int u = e._2._1, v = e._2._2;
    int a = Find(u), b = Find(v);
    if (a == b) continue;
    par[a] = b;
    cost += d;
    if (!u) pw.eb(v);
    else w.eb(u, v);
  }
  printf("%lld\n", cost);
  printf("%d\n", int(pw.size()));
  for (auto u : pw) printf("%d ", u);
  putchar('\n');
  printf("%d\n", int(w.size()));
  for (auto e : w) printf("%d %d\n", e._1, e._2);
}