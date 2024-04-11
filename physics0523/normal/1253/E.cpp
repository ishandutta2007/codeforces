#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<pi> pv(n);
  for(int i=0;i<n;i++){
    cin >> pv[i].first;
    cin >> pv[i].second;
  }
  sort(pv.begin(),pv.end());
  vector<int> dp(m+5,inf);
  dp[1]=0;
  for(int i=0;i<n;i++){
    int ccos=inf;
    for(int j=0;j<m;j++){
      int del=max(0,j-pv[i].second);
      if((pv[i].first-j)>=1){ccos=min(dp[pv[i].first-j],ccos);}
      if((pv[i].first+j)<=m){ccos=min(dp[pv[i].first+j],ccos);}
      dp[min(pv[i].first+j,m)+1]=min(ccos+del,dp[min(pv[i].first+j,m)+1]);
    }
  }
  cout << dp[m+1] << '\n';
  return 0;
}