#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,mmx,abm,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAX = 1001 * 10000;
 
int dist[MAX];
int adj[MAX][3];
bitset<MAX> vis;
 
void AddEdge(int u, int v, int w) {
  int pt = 0;
  while (adj[u][pt] != -1) pt++;
  adj[u][pt] = ((v << 1) + w);
}

const int DQSZ = MAX + 5;
int dq[DQSZ];

int MOD(int a) {
  if (a < 0) a += DQSZ;
  return a % DQSZ;
}

void BFS() {
  memset(dist, -1, sizeof(dist));
  int head = 0, tail = 0;

  dq[MOD(--head)] = 0;
  // dq.emplace_back(0);
  dist[0] = 0;
 
  while (MOD(head) != MOD(tail)) {
    int u = dq[MOD(head++)];
    // dq.pop_front();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = 0; i < 3; i++) {
      int v = adj[u][i];
      if (v == -1) continue;
      if (dist[v / 2] == -1 || dist[v / 2] > dist[u] + (v & 1)) {
        dist[v / 2] = dist[u] + (v & 1);
        if ((v & 1) == 0) {
          dq[MOD(--head)] = v / 2;
          // dq.emplace_front(v / 2);
        } else {
          dq[MOD(tail++)] = v / 2;
          // dq.emplace_back(v / 2);
        }
      }
    }
  }
}
 
 
int N, M, G, R;
int A[10001];
 
const int LIM = 1001;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(adj, -1, sizeof(adj));
 
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }
  cin >> G >> R;
  sort(A, A + M);
 
  for (int i = 0; i + 1 < M; i++) {
    for (int g = 0; g <= G; g++) {
      if (g + A[i + 1] - A[i] <= G) {
        AddEdge(i * LIM + g, (i + 1) * LIM + g + A[i + 1] - A[i], 0);
        AddEdge((i + 1) * LIM + g, i * LIM + g + A[i + 1] - A[i], 0);
      }
    }
    AddEdge(i * LIM + G, i * LIM + 0, 1);
  }

  BFS();
 
  lint ans = 1e18;
  for (int g = 0; g <= G; g++) {
    if (dist[(M - 1) * LIM + g] != -1) {
      ans = min(ans, 1ll * dist[(M - 1) * LIM + g] * (R + G) + g);
    }
  }
 
  if (ans == 1e18) {
    ans = -1;
  }
 
  cout << ans << "\n";
  return 0;
}