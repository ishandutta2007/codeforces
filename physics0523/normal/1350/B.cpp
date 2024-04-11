#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> s(n+1),dp(n+1,0);
    for(int i=1;i<=n;i++){cin >> s[i];}
    dp[1]=1;
    for(int i=1;i<=n;i++){
      dp[i]=max(dp[i],1);
      for(int j=2*i;j<=n;j+=i){
        if(s[i]<s[j]){dp[j]=max(dp[i]+1,dp[j]);}
      }
    }
    int res=0;
    for(auto &nx: dp){res=max(res,nx);}
    cout << res << '\n';
  }
  return 0;
}