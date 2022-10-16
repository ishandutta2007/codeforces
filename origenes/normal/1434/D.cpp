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

const int maxn = 512345;

int n, q;
vector<tuple<int, int, int>> G[maxn];

struct Tree {
  int clk;
  int in[maxn], out[maxn], dep[maxn], stone[maxn], ver[maxn], seq[maxn];
  bool vis[maxn];

  struct Seg {
    int l, r;
    int mx[2];
    bool lzy;
  } T[maxn << 2];

  void push_up(int o) {
    T[o].mx[0] = max(T[o << 1].mx[0], T[o << 1 | 1].mx[0]);
    T[o].mx[1] = max(T[o << 1].mx[1], T[o << 1 | 1].mx[1]);
  }

  void push_down(int o) {
    if (!T[o].lzy) return;
    swap(T[o << 1].mx[0], T[o << 1].mx[1]);
    T[o << 1].lzy ^= true;
    swap(T[o << 1 | 1].mx[0], T[o << 1 | 1].mx[1]);
    T[o << 1 | 1].lzy ^= true;
    T[o].lzy = false;
  }

  void build(int o, int l, int r) {
    T[o].l = l, T[o].r = r;
    if (l == r) {
      T[o].mx[stone[seq[l]] & 1] = dep[seq[l]];
    } else {
      int mi = l + r >> 1;
      build(o << 1, l, mi);
      build(o << 1 | 1, mi + 1, r);
      push_up(o);
    }
  }

  void update(int o, int l, int r) {
    if (l <= T[o].l && T[o].r <= r) {
      swap(T[o].mx[0], T[o].mx[1]);
      T[o].lzy ^= true;
      return;
    }
    push_down(o);
    int mi = T[o].l + T[o].r >> 1;
    if (l <= mi) update(o << 1, l, r);
    if (r > mi) update(o << 1 | 1, l, r);
    push_up(o);
  }

  void dfs(int u, int par) {
    if (par) dep[u] = dep[par] + 1;
    in[u] = ++clk;
    seq[clk] = u;
    for (auto[v, t, e] : G[u])
      if (v != par) {
        stone[v] = stone[u] + t;
        ver[e] = v;
        dfs(v, u);
      }
    out[u] = clk;
  }

  int bfs(int r) {
    queue<int> Q;
    Q.emplace(r);
    vis[r] = true;
    int u = 0;
    while (!Q.empty()) {
      u = Q.front();
      Q.pop();
      for (auto[v, _, __] : G[u])
        if (!vis[v]) {
          vis[v] = true;
          Q.emplace(v);
        }
    }
    return u;
  }
} T[2];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n - 1) {
    int u, v, t;
    cin >> u >> v >> t;
    G[u].eb(v, t, i);
    G[v].eb(u, t, i);
  }
  int r = 1;
  REP(i, 2) {
    r = T[i].bfs(r);
    T[i].dfs(r, 0);
    T[i].build(1, 1, n);
  }
  cin >> q;
  while (q--) {
    int id; cin >> id;
    int ans = 0;
    REP(i, 2) {
      int u = T[i].ver[id];
      T[i].update(1, T[i].in[u], T[i].out[u]);
      chkmax(ans, T[i].T[1].mx[0]);
    }
    cout << ans << '\n';
  }
}