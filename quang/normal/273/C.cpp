#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m;
vector <int> a[N];
int enemy[N];
int g[N];
int inqueue[N], q[N], top = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
    enemy[u]++;
    enemy[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (enemy[i] > 1) {
      q[top++] = i;
      inqueue[i] = 1;
    }
  }
  for (int i = 0; i < top; i++) {
    int u = q[i];
    inqueue[u] = 0;
    if (enemy[u] < 2) {
      continue;
    }
    g[u] ^= 1;
    enemy[u] = a[u].size() - enemy[u];
    for (int v : a[u]) {
      if (g[v] == g[u]) {
        enemy[v]++;
      } else {
        enemy[v]--;
      }
      if (enemy[v] >= 2 && !inqueue[v]) {
        q[top++] = v;
        inqueue[v] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << g[i];
  }
  return 0;
}