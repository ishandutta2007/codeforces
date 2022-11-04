#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 404;

int n, m;
vector<int> g[N];
int d[N][N];
double prob[N];
double prob_dist[N];
int ptr;
int good[N];
bool vis[N];

double tommorow(int from, int dist) {
  fill(vis, vis + n + 1, 0);
  fill(prob, prob + n + 1, 0);
  ptr = 0;
  
  for (int i = 1; i <= n; i++) {
    if (d[from][i] != dist) continue;
    
    for (int u : g[i]) {
      prob[u] += (1.0D / n) / g[i].size();
      if (!vis[u]) {
        vis[u] = 1;
        good[ptr++] = u;
      }
    }
  }
  
  double ans = 0;
  
  for (int v = 1; v <= n; v++) {
    double cur = 0;
    
    for (int i = 0; i < ptr; i++) {
      int u = good[i];
      prob_dist[d[v][u]] = max(prob_dist[d[v][u]], prob[u]);
    }
    
    for (int i = 0; i < ptr; i++) {
      int u = good[i];
      cur += prob_dist[d[v][u]];
      prob_dist[d[v][u]] = 0;
    }
    
    ans = max(ans, cur);
  }
  
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  cin >> n >> m;
  
  for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, INF), d[i][i] = 0;
  
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    d[u][v] = 1;
    d[v][u] = 1;
  }
  
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  
  double ans = 0;
  
  for (int from = 1; from <= n; from++) {
    double cur = 0;
    
    for (int dist = 0; dist <= n; dist++) {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (d[from][i] == dist) cnt++;
      }
      
      if (cnt == 0) continue;
      
      double now = 1.0D / n;
      double after = tommorow(from, dist);
      
      cur += max(now, after);
    }
    
    ans = max(ans, cur);
  }
  
  cout << fixed << setprecision(12) << ans << "\n";
  return 0;
}