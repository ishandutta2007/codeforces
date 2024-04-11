#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    if(k==1){cout << "1\n";continue;}
    if(n==1){cout << "2\n";continue;}

    long long res=2;
    vector<long long> dp(n-1,0);
    dp[0]=1;
    for(int i=2;i<=k;i++){
      if(i%2==0){
        for(int j=1;j<n-1;j++){dp[j]=(dp[j-1]+dp[j])%mod;}
      }
      else{
        for(int j=n-3;j>=0;j--){dp[j]=(dp[j+1]+dp[j])%mod;}
      }
      for(auto &nx : dp){res+=nx;res%=mod;}
    }
    cout << res%mod << '\n';
  }
  return 0;
}