#include "bits/stdc++.h"
using namespace std;

const int MAXN = 100005;

int n, m, sq;
vector<int> adj[MAXN];

vector<int> ind_set, cycle;
vector<int> st;
int depth[MAXN];
int marked[MAXN];

void dfs(int n, int p) {
  st.emplace_back(n);
  for (auto &i : adj[n]) {
    if (depth[i] == -1) {
      depth[i] = depth[n] + 1;
      dfs(i, n);
    } else if (depth[n] - depth[i] + 1 >= sq && cycle.empty()) {
      while (st.back() != i) {
        cycle.emplace_back(st.back());
        st.pop_back();
      }
      cycle.emplace_back(st.back());
      st.pop_back();
    }
  }
  if (!st.empty()) st.pop_back();
  if (!marked[n]) {
    for (auto &i : adj[n]) {
      marked[i] = 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(depth, -1, sizeof(depth));

  cin >> n >> m;
  for (sq = 1; sq * sq < n; sq++);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  depth[0] = 0;
  dfs(0, -1);

  if (!cycle.empty()) {
    cout << 2 << "\n";
    cout << cycle.size() << "\n";
    for (auto &i : cycle) {
      cout << i + 1 << " ";
    }
  } else {
    cout << 1 << "\n";
    for (int i = 0; i < n; i++) {
      if (sq > 0 && !marked[i]) {
        sq--;
        cout << i + 1 << " ";
      }
    }
  }

  cout << "\n";
  return 0;
}