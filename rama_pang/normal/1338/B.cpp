#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 100005;
int N;
vector<int> adj[MAXN];
int par[MAXN];
vector<int> ls[MAXN];

int p[MAXN];
vector<int> leaf;

int Find(int x) {
  return p[x] == x ? x : p[x] = Find(p[x]);
}

int dfs(int n, int p, int d = 0) {
  for (auto i : adj[n]) if (i != p) {
    dfs(i, n, d + 1);
  }
  par[n] = p;
  if (adj[n].size() == 1) leaf.emplace_back(d);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  iota(p, p + MAXN, 0);

  cin >> N;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int r = 0;
  for (int i = 1; i <= N; i++) {
    if (adj[i].size() > 1) r = i;
  }
  dfs(r, 0);
  int ansmx = N - 1;
  for (int i = 1; i <= N; i++) {
    if (adj[i].size() == 1) {
      if (ls[par[i]].size() > 0) {
        int x = Find(ls[par[i]][0]);
        int y = i;
        if (x != y) {
          p[x] = y;
          ansmx--;
        }
      }
      ls[par[i]].emplace_back(i);
    }
  }

  int ansmn = 1;

  int x = leaf[0];
  for (int i = 1; i < leaf.size(); i++) {
    if (leaf[i] % 2 != leaf[0] % 2) {
      ansmn = 3;
      break;
    }
  }

  cout << ansmn << " " << ansmx << "\n";

}