#include <bits/stdc++.h>

using namespace std;

typedef long long lll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> T[N];
int dis[N];
int cnt[N];

void dfs(int u, int par){ 
  for(auto x : T[u]){
    if(x == par) continue;
    if(T[x].size() == 1) cnt[u] ++ ;
    dis[x] = dis[u] + 1;
    dfs(x, u);
  }
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int u, v;
  for(int i = 1; i < n; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  int root = 1;
  for(int i = 1; i <= n; i ++ )
    if(T[i].size() >= 2) root = i;
  dfs(root, 0);
  int c[2];
  c[0] = 0, c[1] = 0;
  for(int i = 1; i <= n; i ++ ){
    if(T[i].size() == 1){
      c[dis[i]%2] ++ ;
    }
  }
  if(c[0] > 0 && c[1] > 0)
    cout << 3 << " " ;
  else
    cout << 1 << " ";
  int res = n - 1;
  for(int i = 1; i <= n; i ++ ){
    if(cnt[i] > 1)
      res -= cnt[i] - 1;
  }
  cout << res;
  return 0;
}