#include <bits/stdc++.h>
using namespace std;
 
const int N = 16;

int n;
vector<int> edges[1 << N];

int P[1 << N];
int iP[1 << N];

int dist[1 << N];

void bfs() {
  for (int i = 0; i < 1 << n; ++i) {
    dist[i] = -1;
    P[i] = iP[i] = 0;
  }
  queue<int> q;
  q.push(0);
  P[0] = 0; dist[0] = 0; iP[0] = 0;
  
  for (int i = 0; i < n; ++i) {
    iP[edges[0][i]] = 1 << i;
  }

  while (q.size()) {
    int u = q.front();
    q.pop();

    P[iP[u]] = u;

    for (int v : edges[u]) {
      if (dist[v] == dist[u] + 1 || dist[v] == -1) {
        iP[v] |= iP[u];
      }
      if (dist[v] != -1) continue;
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < 1 << n; ++i) edges[i].clear();
  for (int i = 0; i < n * (1 << (n - 1)); ++i) {
    int u, v;
    scanf("%d %d", &u, &v);

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  bfs();
  for (int i = 0; i < 1 << n; ++i) printf("%d ", P[i]);
  printf("\n");

  if (n != 1 && n != 2 && n != 4 && n != 8 && n != 16) return 0 * printf("-1\n");

  for (int i = 0; i < 1 << n; ++i) {
    int x = iP[i];
    int col = 0;
    for (int len = 1; len < n; len <<= 1) {
      int bit = 0;
      for (int j = 0; j < n; j += len << 1) {
        for (int k = j; k < j + len; ++k) {
          bit ^= x >> k & 1;
        }
      }
      if (bit) col |= len;
    }
    printf("%d ", col);
  } 
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}