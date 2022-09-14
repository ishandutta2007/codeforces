#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
int a[200001];
vector<int>g[201];
int dp[201][201];
int n,k;
void dfs(int v,int pr){
  for (auto to:g[v]){
    if (to==pr) continue;
    dfs(to,v);
  }
  for (int i=n;i>=1;i--){
    //calc dp[v][i]
    if (i<n) dp[v][i]=dp[v][i+1];
    else dp[v][i]=0;
    for (auto to:g[v]){
      if (to==pr) continue;
      int cur=dp[to][i-1];
      for (auto to1:g[v]){
        if (to1==pr || to1==to) continue;
        cur+=dp[to1][max(k-i,i-1)];
      }
      dp[v][i]=max(dp[v][i],cur);
    }

  }
  ///calc dp[v][0]
  dp[v][0]=a[v];
  for (auto to:g[v]){
    if (to==pr) continue;
    dp[v][0]+=dp[to][k];
  }
  dp[v][0]=max(dp[v][0],dp[v][1]);

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for (int i=1;i<=n;i++) cin>>a[i];
  for (int i=1;i<n;i++){
    int x,y;cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0);
  cout<<dp[1][0];
  return 0;
}