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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

vector<pii> G[maxn];
int n, q, anc[maxn][17], dep[maxn], in[maxn], clk, bit[17];
ll dis[maxn][17];
char op[5];

void dfs(int u, int par, int w) {
  in[u] = ++clk;
  dep[u] = dep[par] + 1;
  anc[u][0] = par;
  dis[u][0] = w;
  FOR(i, 1, 16) {
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
    dis[u][i] = dis[u][i - 1] + dis[anc[u][i - 1]][i - 1];
  }
  for (auto _ : G[u]) {
    int v = _._1, ww = _._2;
    if (v == par) continue;
    dfs(v, u, ww);
  }
}

ll get(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  ll ret = 0;
  ROF(i, 16, 0) if (dep[v] - dep[u] >= bit[i]) {
    ret += dis[v][i];
    v = anc[v][i];
  }
  if (u == v) return ret;
  ROF(i, 16, 0) if (anc[u][i] != anc[v][i]) {
    ret += dis[u][i] + dis[v][i];
    v = anc[v][i], u = anc[u][i];
  }
  ret += dis[u][0] + dis[v][0];
  return ret;
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].eb(v, w);
    G[v].eb(u, w);
  }
  dfs(1, 0, 0);
  REP(i, 17) bit[i] = 1 << i;
  scanf("%d", &q);
  set<pii> s;
  ll ans = 0;
  while (q--) {
    scanf("%s", op);
    if (op[0] == '?') printf("%lld\n", ans / 2);
    else {
      int u;
      scanf("%d", &u);
      auto now = mp(in[u], u);
      if (op[0] == '+') {
        if (s.empty()) {
          s.emplace(now);
          continue;
        }
        if (s.size() == 1) {
          auto v = s.begin()->_2;
          ans = 2 * get(u, v);
          s.emplace(now);
          continue;
        }
        auto hi = s.lower_bound(now), lo = hi;
        if (hi == s.end()) {
          lo--;
          hi = s.begin();
        } else if (hi == s.begin()) {
          lo = s.end();
          lo--;
        } else lo--;
        ans += get(u, hi->_2) + get(u, lo->_2) - get(lo->_2, hi->_2);
        s.emplace(now);
      } else {
        if (s.size() == 1) {
          s.erase(now);
          continue;
        }
        if (s.size() == 2) {
          s.erase(now);
          ans = 0;
          continue;
        }
        auto hi = s.lower_bound(now), lo = hi;
        hi++;
        if (hi == s.end()) {
          lo--;
          hi = s.begin();
        } else if (lo == s.begin()) {
          lo = s.end();
          lo--;
        } else lo--;
        ans -= get(u, hi->_2) + get(u, lo->_2) - get(lo->_2, hi->_2);
        s.erase(now);
      }
    }
  }
}