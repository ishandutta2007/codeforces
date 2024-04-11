#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t,n,a[524288];
  int dp[524288],pv[524288],res[524288];
  cin >> t;
  while(t>0){
    t--;
    cin >> n;
    for(int i=1;i<=n;i++){
      dp[i]=0;
      pv[i]=-1;
      res[i]=inf;
    }
    for(int i=0;i<n;i++){
      cin >> a[i];
      dp[a[i]]=max(i-pv[a[i]],dp[a[i]]);
      pv[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
      if(pv[i]==-1){continue;}
      dp[i]=max(n-pv[i],dp[i]);
      res[dp[i]]=min(i,res[dp[i]]);
    }
    for(int i=1;i<=n;i++){
      if(i!=1){cout << " ";}
      if(res[i]==inf){cout << -1;}
      else{cout << res[i];}
      res[i+1]=min(res[i],res[i+1]);
    }cout << '\n';
  }
  return 0;
}