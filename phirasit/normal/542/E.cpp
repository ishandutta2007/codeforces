#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int N = 1010;

typedef pair<int, int> pii;
queue<pii> bfs;

vector<int> adj[N];

int G[N], mx[N];
int pass[N], s[N];
int n, m;

bool err = false;

void dfs(int u, bool state) {
  pass[u] = true;
  s[u] = state;
  if(err) return;
  for(int v : adj[u]) {
    if(pass[v]) {
      if(state == s[v]) {
        err = true;
      }
    }else {
      dfs(v, not state);
    }
  }
}
int find(int u) {
  return u == G[u] ? u : G[u] = find(G[u]);
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0;i < m;i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1;i <= n;i++) {
    G[i] = i;
    if(not pass[i]) {
      dfs(i, true);
    }
  }
  for(int u = 1;u <= n;u++) {
    for(int v : adj[u]) {
      if(find(u) != find(v)) {
        G[find(u)] = find(v);
      }
    }
  }
  if(err) {
    printf("-1\n");
  }else {
    int ans = 0;
    for(int i = 1;i <= n;i++) {
      for(int j = 1;j <= n;j++) {
        pass[j] = 0;
      }
      bfs.push({i, 0});
      pass[i] = 1;
      while(not bfs.empty()) {
        int u = bfs.front().first, x = bfs.front().second;
        bfs.pop();
        if(x > mx[find(u)]) {
          mx[find(u)] = x;
        }
        for(int v : adj[u]) {
          if(not pass[v]) {
            pass[v] = 1;
            bfs.push({v, x+1});
          }
        }
      }
    }
    for(int i = 1;i <= n;i++) {
      ans += mx[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}