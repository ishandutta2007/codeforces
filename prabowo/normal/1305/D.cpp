#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
vector<int> edges[N];

int ask(int u, int v) {
  printf("? %d %d\n", u+1, v+1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return --ret;
}

void answer(int r) {
  printf("! %d\n", r+1);
  fflush(stdout);
  exit(0);
}

void dfs(int u, int p, int hasPar) {
  int w = -1;
  if (hasPar) w = p;

  bool leaf = true;
  for (int v: edges[u]) {
    if (v == p) continue;
    leaf = false;

    if (w == -1) {
      w = v;
    } else {
      int lca = ask(w, v);

      if (w == p && lca == w) answer(p);
      if (lca == w) dfs(w, u, 0);
      if (lca == v) dfs(v, u, 0);

      w = -1;
    }
  }

  if (w == -1) answer(u);
  if (w == p) {
    answer(ask(w, u));
  }
  dfs(w, u, 1);
}

int solve() {
  scanf("%d", &n);

  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(0, -1, 0);
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