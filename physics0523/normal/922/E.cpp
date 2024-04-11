#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long w,b,x;
  cin >> n >> w >> b >> x;
  vector<int> c(n);
  vector<long long> cost(n);
  for(int i=0;i<n;i++){cin >> c[i];}
  for(int i=0;i<n;i++){cin >> cost[i];}
  vector<long long> dp(10005,-llinf);
  dp[0]=w;
  int mx=0;
  for(int i=0;i<n;i++){
    for(int q=0;q<c[i];q++){
      for(int j=mx;j>=0;j--){
        if(dp[j]<0){continue;}
        if(dp[j]>=cost[i]){dp[j+1]=max(dp[j]-cost[i],dp[j+1]);}
      }
      mx++;
    }
    for(int j=0;j<=mx;j++){
      if(dp[j]>=0){dp[j]=min(dp[j]+x,w+j*b);}
    }
  }
  for(int j=10004;j>=0;j--){
    if(dp[j]>=0){cout << j << '\n';return 0;}
  }
  return 0;
}