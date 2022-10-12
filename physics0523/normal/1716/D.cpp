#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<int> dp(n+1,0);
  dp[0]=1;
  vector<int> res(n+1,0);

  int h=0;
  for(int i=k;;i++){
    h+=i;
    if(h>n){break;}
    for(int j=0;i+j<=n;j++){
      dp[i+j]+=dp[j];
      dp[i+j]%=mod;
    }
    for(int j=0;h+j<=n;j++){
      res[h+j]+=dp[j];
      res[h+j]%=mod;
    }
  }

  for(int i=1;i<=n;i++){
    if(i-1){cout << " ";}
    cout << res[i];
  }cout << "\n";
  return 0;
}