#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> G(100000);

int ans[100001];
int dp[100001];
int st[100001][20];
int depth[100001];
void dfs(int x, int p = -1, int d = 0){
  depth[x] = d;
  for(auto i : G[x]){
    if(i.first != p){
      st[i.first][0] = x;
      dfs(i.first, x, d + 1);
    }
  }
}

void dfs2(int x, int p = -1, int road = -1){
  for(auto i : G[x]){
    if(i.first != p){
      dfs2(i.first, x, i.second);
    }
  }
  // cout << road << ' ' << x << ' ' << dp[x] << endl;
  if(road != -1){
    ans[road] = dp[x];
    dp[p] += dp[x];
  }
}

int lca(int x, int y){
  if(depth[x] < depth[y]) swap(x, y);
  for(int i = 19; i >= 0; i--){
    if(depth[x] - (1 << i) >= depth[y]){
      x = st[x][i];
    }
  }
  if(x == y){
    return x;
  }
  for(int i = 19; i >= 0; i--){
    if(st[x][i] != st[y][i]){
      x = st[x][i], y = st[y][i];
    }
  }
  return st[x][0];
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n - 1; i++){
    int v1, v2;
    cin >> v1 >> v2;
    v1--; v2--;
    G[v1].push_back({v2, i});
    G[v2].push_back({v1, i});
  }

  st[0][0] = 0;
  dfs(0);

  for(int i = 1; i < 20; i++){
    for(int j = 0; j < n; j++){
      st[j][i] = st[st[j][i - 1]][i - 1];
    }
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    int v1, v2;
    cin >> v1 >> v2;
    v1--; v2--;
    int l = lca(v1, v2);
    // printf("* %d %d %d\n", v1, v2, l);
    dp[v1]++, dp[v2]++, dp[l] -= 2;
    // cout << v1 << ' ' << v2 << ' ' << l << endl;
  }

  dfs2(0);
  for(int i = 0; i < n - 1; i++){
    cout << ans[i] << ' ';
  }
  cout << endl;
}
// answer for input7.txt should be:
// 2 2 1 1 0 3 4 3 1 2 1