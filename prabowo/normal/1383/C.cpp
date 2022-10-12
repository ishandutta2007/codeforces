#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
const int C = 20;
 
int n;
char s[N], t[N];
 
vector<int> masks[C];
bool adj[C][C];
 
struct DSU {
  int par[C];
 
  void init() {
    for (int i = 0; i < C; ++i) {
      par[i] = i;
    }
  }
 
  int root(int u) {
    if (u == par[u]) return u;
    return par[u] = root(par[u]);
  }
 
  void merge(int u, int v) {
    if (root(u) == root(v)) return;
    par[par[u]] = par[v];
  }
 
  int count() {
    int ret = 0;
    for (int i = 0; i < C; ++i) {
      if (root(i) == i) ++ret;
    }
    return ret;
  }
} dsu;
 
void init() {
  dsu.init();
  memset(adj, 0, sizeof adj);
}

void setup() {
  for (int i = 0; i < n; ++i) {
    if (s[i] == t[i]) continue;
    dsu.merge(s[i] - 'a', t[i] - 'a');
    adj[s[i] - 'a'][t[i] - 'a'] = true;
  }
}

int deg[C];
int q[C];
bool isDag(int mask) {
  memset(deg, 0, sizeof deg);
  for (int i = 0; i < C; ++i) {
    if (mask >> i & 1); else continue;
    for (int j = 0; j < C; ++j) {
      if ((mask >> j & 1) && adj[i][j]); else continue;
      ++deg[j];
    }
  }

  int head = 0, tail = 0;
  for (int i = 0; i < C; ++i) {
    if ((mask >> i & 1) && deg[i] == 0) q[tail++] = i;
  }

  while (head < tail) {
    int u = q[head++];

    for (int v = 0; v < C; ++v) {
      if ((mask >> v & 1) && adj[u][v]) {
        --deg[v];
        if (deg[v] == 0) q[tail++] = v;
      }
    }
  }

  for (int i = 0; i < C; ++i) {
    if (deg[i] > 0) return false;
  }
  return true;
}
 
int solve() {
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%s", t);
 
  init();
  setup();
 
  int l = 0, r = C-1, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
 
    bool found = false;
    for (int mask: masks[mid]) if (isDag(mask)) {
      found = true;
      break;
    }
 
    if (found) {
      ans = mid+1;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
 
  printf("%d\n", C*2 - ans - dsu.count());
  return 0;
}
 
int main() {
  for (int i = 1; i < 1 << C; ++i) {
    masks[__builtin_popcount(i) - 1].push_back(i);
  }
 
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}