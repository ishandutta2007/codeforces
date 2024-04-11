#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n;
vector<int> adj[N];

bool vis[N];

int par[N];
int grundy[N];
void dfs(int u, int p=-1) {
  par[u] = p;
  grundy[u] = 0;
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    grundy[u] ^= grundy[v];
  }
  ++grundy[u];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0);

  int g = grundy[0] - 1;
  printf(g == 0 ? "2" : "1");
  vis[0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int u = i; !vis[u]; u = par[u]) {
      vis[u] = true;
      g ^= grundy[u] ^ (grundy[u] - 1) ^ 1;
    }
    printf(g == 0 ? "2" : "1");
  }
  printf("\n");
  return 0;
}