#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 100005;

int N, M, K;
vector<int> adj[MAXN];

int color[MAXN];
void Bipartite(int n, int p) {
  color[n] = color[p] ^ 1;
  for (auto i : adj[n]) if (i != p) Bipartite(i, n);
}

vector<int> st;
vector<int> cyc;

int depth[MAXN];
int mn = 1e9;
void Dfs(int n, int p, bool rec) {
  depth[n] = depth[p] + 1;
  if (rec) st.emplace_back(n);
  for (auto i : adj[n]) if (i != p) {
    if (depth[i] == 0) {
      Dfs(i, n, rec);      
    } else {
      if (rec) {
        if (depth[n] - depth[i] + 1 == mn) {
          while (mn--) {
            cyc.push_back(st.back());
            st.pop_back();
          }
          return;
        }
      } else if (depth[n] > depth[i]) {
        mn = min(mn, depth[n] - depth[i] + 1);
      }
    }
    if (!cyc.empty()) return;
  }
  if (!cyc.empty()) return;
  if (rec) st.pop_back();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  
  if (M == N - 1) { // no cycles
    Bipartite(1, 0);
    vector<int> zero, one;
    for (int i = 1; i <= N; i++) {
      if (color[i] == 0) {
        zero.emplace_back(i);
      } else {
        one.emplace_back(i);
      }
    }
    if (zero.size() < one.size()) swap(zero, one);
    cout << 1 << "\n";
    for (int i = 0; i < (K + 1) / 2; i++) {
      cout << zero[i] << " ";
    }
    cout << "\n";
    return 0;
  }

  Dfs(1, 0, 0);
  memset(depth, 0, sizeof(depth));
  Dfs(1, 0, 1);

  if (cyc.size() <= K) {
    cout << 2 << "\n" << cyc.size() << "\n";
    for (auto i : cyc) cout << i << " ";
    cout << "\n";
  } else {
    cout << 1 << "\n";
    for (int i = 0; i < (K + 1) / 2; i++) {
      cout << cyc[i * 2] << " ";
    }
    cout << "\n";
  }
  return 0;
}