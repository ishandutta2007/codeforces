#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a,n,m;
  cin >> a >> n >> m;
  vector<bool> rai(a,false);
  for(int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    for(int j=l;j<r;j++){rai[j]=true;}
  }
  vector<int> uw(a,1e9);
  for(int i=0;i<m;i++){
    int x,w;
    cin >> x >> w;
    if(x==a){continue;}
    uw[x]=min(w,uw[x]);
  }
  vector<int> dp(100005,1e9);
  dp[0]=0;
  for(int i=0;i<a;i++){
    for(int j=0;j<=100000;j++){
      if(dp[j]>=5e8){continue;}
      dp[0]=min(dp[0],dp[j]);
      if(uw[i]<=5e8){dp[uw[i]]=min(dp[uw[i]],dp[j]);}
    }
    if(rai[i]){dp[0]=1e9;}
    for(int j=0;j<=100000;j++){
      dp[j]+=j;
      dp[j]=min(dp[j],1000000000);
    }
  }
  int res=1e9;
  for(auto &nx : dp){res=min(res,nx);}
  if(res>=5e8){res=-1;}
  cout << res << '\n';
  return 0;
}