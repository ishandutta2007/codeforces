#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  vector<long long> dp(5005,0);
  dp[0]=1;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    if(i==n-1){break;}
    if(s[0]=='s'){
      for(int i=5003;i>=0;i--){
        dp[i]+=dp[i+1];
        dp[i]%=mod;
      }
    }
    else{
      for(int i=5004;i>=1;i--){
        dp[i]=dp[i-1];
      }
      dp[0]=0;
    }
  }
  long long res=0;
  for(auto &nx : dp){res+=nx;res%=mod;}
  cout << res << "\n";
  return 0;
}