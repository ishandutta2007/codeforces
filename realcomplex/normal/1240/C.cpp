#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;
vector<pii> T[N];
ll dp[N][2];
int k;

void dfs(int u, int par){
  ll S = 0;
  for(auto x : T[u]){
    if(x.fi == par) continue;
    dfs(x.fi, u);
    S += dp[x.fi][0]; 
  }
  dp[u][0] = dp[u][1] = S;
  vector<ll> yy;
  for(auto x : T[u]){
    if(x.fi==par)continue;
    yy.push_back(x.se + dp[x.fi][1]-dp[x.fi][0]);
  }
  sort(yy.begin(),yy.end());
  reverse(yy.begin(),yy.end());
  for(int i = 0 ; i < yy.size(); i ++ ){
    if(yy[i] <= 0) break;
    if(i < k)
      dp[u][0] += yy[i];
    if(i < k - 1)
      dp[u][1] += yy[i];
  }
}

void solve(){
  int n;
  cin >> n >> k;
  int u, v, w;
  for(int i = 1; i <= n; i ++ ){
    dp[i][0] = 0;
    dp[i][1] = 0;
    T[i].clear();
  }
  for(int i = 1; i < n; i ++ ){
    cin >> u >> v >> w;
    T[u].push_back(mp(v,w));
    T[v].push_back(mp(u,w));
  }
  dfs(1,-1);
  cout << max(dp[1][0],dp[1][1]) << "\n";
}

int main(){ 
  fastIO;
  int q;
  cin >> q;
  for(int t = 0; t < q; t ++ ){
    solve();
  }
  return 0;
}