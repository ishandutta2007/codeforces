#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
vector<int> edges[N];

pair<int, int> ask(vector<int> nodes) {
  printf("? %d", (int) nodes.size());
  for (int u: nodes) printf(" %d", u+1);
  printf("\n");
  fflush(stdout);

  int x, y;
  scanf("%d %d", &x, &y);
  --x;
  return make_pair(x, y);
}

char verdict[20];
void answer(int x, int y) {
  printf("! %d %d\n", x+1, y+1);
  fflush(stdout);
  scanf("%s", verdict);
  if (verdict[0] != 'C') exit(0);
}

int par[N];
int depth[N];
void dfs(int u, int p) {
  par[u] = p;
  for (int v: edges[u]) {
    if (v == p) continue;
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
}

bool isAncestor(int u, int v) {
  while (depth[u] > depth[v]) u = par[u];
  return u == v;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) edges[i].clear();
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  pair<int, int> p = ask(v);

  int root = p.first;
  dfs(root, root);

  pair<int, int> ans = {root, root};

  for (int len = p.second; len > 0; len >>= 1) {
    int flen = (len + 1) / 2;
    // cerr << flen << endl;
    vector<int> v;
    vector<int> anc(n, -1);
    for (int i = 0; i < n; ++i) {
      if (depth[i] - depth[ans.first] == flen && isAncestor(i, ans.first) && !isAncestor(ans.second, i)) {
        v.push_back(i);
        anc[i] = 0;
      } else if (depth[i] - depth[ans.second] == flen && isAncestor(i, ans.second) && !isAncestor(ans.first, i)) {
        v.push_back(i);
        anc[i] = 1;
      }
    }

    int u = ask(v).first;
    if (anc[u] == 0) ans.first = u;
    else ans.second = u;
  }

  answer(ans.first, ans.second);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}