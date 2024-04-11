#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

int zt(int a,int b){return max(a,b)-min(a,b);}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int r,n;
  cin >> r >> n;
  vector<int> dp(n+1);
  int x[131072],y[131072],t[131072];
  for(int i=1;i<=n;i++){
    cin >> t[i] >> x[i] >> y[i];
    dp[i]=-10000000;
  }
  x[0]=1;y[0]=1;
  dp[0]=0;
  int res=0;
  for(int i=1;i<=n;i++){
    for(int j=i-2020;j<i;j++){
      if(j<0){continue;}
      if(zt(x[j],x[i])+zt(y[j],y[i])<=(t[i]-t[j])){
        dp[i]=max(dp[j]+1,dp[i]);
      }
    }
    res=max(dp[i],res);
  }
  cout << res << '\n';
}