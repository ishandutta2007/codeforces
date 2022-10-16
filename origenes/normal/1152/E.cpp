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

int n, b[maxn], c[maxn], deg[maxn * 2], cnt, st[maxn * 2];
bool done[2 * maxn];
vector<pii> G[maxn * 2];
unordered_map<int, int> mmap, rref;
stack<pii> res;

int init() {
  scanf("%d", &n);
  FOR(i, 1, n - 1) scanf("%d", b + i);
  FOR(i, 1, n - 1) scanf("%d", c + i);
  FOR(i, 1, n - 1) {
    if (c[i] < b[i]) return -1;
    if (!mmap.count(b[i])) {
      mmap[b[i]] = mmap.size();
      rref[mmap[b[i]]] = b[i];
    }
    b[i] = mmap[b[i]];
    if (!mmap.count(c[i])) {
      mmap[c[i]] = mmap.size();
      rref[mmap[c[i]]] = c[i];
    }
    c[i] = mmap[c[i]];
  }
  FOR(i, 1, n - 1) {
    G[b[i]].eb(c[i], i << 1);
    G[c[i]].eb(b[i], i << 1 | 1);
    deg[b[i]]++;
    deg[c[i]]++;
  }
  cnt = 0;
  REP(i, 2 * maxn) if (deg[i] & 1) cnt++;
  if (cnt == 1 || cnt > 2) return -1;
  return 0;
}

void dfs1(int u, vector<bool> &vis) {
  vis[u] = true;
  for (auto _ : G[u]) {
    int v = _._1;
    if (!vis[v]) dfs1(v, vis);
  }
}

bool check() {
  vector<bool> vis(2 * maxn);
  int cc = 0;
  REP(i, 2 * maxn) if (deg[i] && !vis[i]) {
      cc++;
      dfs1(i, vis);
    }
  return cc == 1;
}

void dfs2(int u) {
  int s = st[u];
  FOR(i, s, int(G[u].size()) - 1) {
    int v = G[u][i]._1, e = G[u][i]._2;
    if (!done[e]) {
      done[e] = done[e ^ 1] = true;
      st[u] = i + 1;
      dfs2(v);
      if (e & 1) {
        res.emplace(rref[c[e >> 1]], rref[b[e >> 1]]);
      } else {
        res.emplace(rref[b[e >> 1]], rref[c[e >> 1]]);
      }
    }
    if (i < st[u]) i = st[u] - 1;
  }
}

int main() {
  int ans = init();
  if (ans == -1) {
    puts("-1");
    return 0;
  }
  if (!check()) {
    puts("-1");
    return 0;
  }
  if (!cnt) {
    REP(i, maxn) if (deg[i]) {
        dfs2(i);
        break;
      }
  } else {
    REP(i, maxn) if (deg[i] & 1) {
        dfs2(i);
        break;
      }
  }
  vector<int> vec;
  while (!res.empty()) {
    vec.eb(res.top()._1); vec.eb(res.top()._2);
    res.pop();
  }
  for (int i = 0; i < int(vec.size()); i += 2) printf("%d ", vec[i]);
  printf("%d", vec.back());
}