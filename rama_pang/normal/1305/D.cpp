#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAXN = 1005;

int N;
vector<int> adj[MAXN];

int query(int u, int v) {
  cout << "? " << u << " " << v << endl;
  int w;
  cin >> w;
  if (w == -1) {
    exit(0);
  } 
  return w;
}

void answer(int u) {
  cout << "! " << u << endl;
  exit(0);
}

int depth[MAXN];
int mark[MAXN][MAXN];

int dfs(int n, int p, int d = 0) {
  depth[n] = d;
  int ret = n;
  for (auto &i : adj[n]) if (i != p && mark[n][i] == 0) {
    int tr = dfs(i, n, d + 1);
    if (depth[tr] > depth[ret]) {
      ret = tr;
    }
  }
  return ret;
}

int diam(int n, int p, int t) {
  if (n == t) {
    return 1;
  }
  for (auto &i : adj[n]) if (i != p && mark[n][i] == 0) {
    if (diam(i, n, t) == 1) {
      mark[n][i] = mark[i][n] = 1;
      return 1;
    }
  }
  return 0;
}

int main() {
  cin >> N;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int cur = 1;
  vector<pair<int, int>> d;
  while (true) {
    memset(depth, -1, sizeof(depth));
    d.clear();
    pair<int, int> d1 = {-1, -1};
    for (auto &i : adj[cur]) if (mark[cur][i] == 0) {
      int deep = dfs(i, cur, 1);
      // d1 = max(d1, {depth[i], i});
      d.emplace_back(depth[deep], deep);
    }
    d.emplace_back(0, cur);

    sort(begin(d), end(d));

    if (d.size() == 1) {
      break;
    }

    diam(d[(int) d.size() - 2].second, 0, d.back().second);
    cur = query(d[(int) d.size() - 2].second, d.back().second);
  }

  answer(d[0].second);
  return 0;
}