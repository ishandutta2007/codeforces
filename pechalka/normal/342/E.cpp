#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int MAXK = 17;
const int MAXN = 1 << MAXK;

vector<int> G[MAXN];
int up[MAXN][MAXK + 1];
int depth[MAXN];

void dfs(int v, int p, int d){
  up[v][0] = p;
  depth[v] = d;
  for (int u: G[v]){
    if (u != p)
      dfs(u, v, d + 1);
  }
}

int la(int v, int level){
  int k = MAXK;
  int pow = 1 << MAXK;
  while (k >= 0){
    if (level >= pow){
      v = up[v][k];
      level -= pow;
    }
    pow /= 2;
    --k;
  }
  return v;
}

int lca(int u, int v){
  if (depth[u] < depth[v])
    swap(u, v);
  u = la(u, depth[u] - depth[v]);
  if (u == v)
    return u;
  int k = MAXK;
  while (k >= 0){
    if (up[u][k] != up[v][k]){
      u = up[u][k];
      v = up[v][k];
    }
    --k;
  }
  return up[u][0];
}

int dist[MAXN];

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; ++i){
    int a, b;
    cin >> a >> b;
    G[a - 1].emplace_back(b - 1);
    G[b - 1].emplace_back(a - 1);
  }
  dfs(0, 0, 0);
  for (int j = 1; j <= MAXK; ++j){
    for (int i = 0; i < n; ++i)
      up[i][j] = up[up[i][j - 1]][j - 1];
  }
  for (int i = 0; i < n; ++i)
    dist[i] = depth[i];
  vector<int> red;
  red.emplace_back(0);
  vector<int> stack;
  for (int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    --b;
    if (a == 1){
      stack.emplace_back(b);
      red.emplace_back(b);
      if (stack.size() >= 77){
        fill(dist, dist + n, n);
        deque<int> Q;
        for (int x: red){
          dist[x] = 0;
          Q.emplace_back(x);
        }
        while (!Q.empty()){
          int v = Q.front();
          Q.pop_front();
          for (int u: G[v]){
            if (dist[u] == n){
              dist[u] = dist[v] + 1;
              Q.emplace_back(u);
            }
          }
        }
        vector<int>().swap(stack);
      }
    } else {
      int ans = dist[b];
      for (int x: stack)
        ans = min(ans, depth[b] + depth[x] - 2 * depth[lca(b, x)]);
      cout << ans << '\n';
    }
  }
  return 0;
}