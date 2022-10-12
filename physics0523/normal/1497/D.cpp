#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> tag(n);
    vector<long long> s(n);
    for(int i=0;i<n;i++){cin >> tag[i];}
    for(int i=0;i<n;i++){cin >> s[i];}
    vector<long long> dp(n,0);
    for(int i=1;i<n;i++){
      for(int j=i-1;j>=0;j--){
        if(tag[i]!=tag[j]){
          long long del=abs(s[i]-s[j]);
          long long gj=dp[j];
          //back
          dp[j]=max(dp[i]+del,dp[j]);
          //go
          dp[i]=max(gj+del,dp[i]);
        }
      }
      //for(int j=0;j<n;j++){cout << dp[j] << ' ';}
      //cout << '\n';
    }
    long long res=0;
    for(int i=0;i<n;i++){res=max(dp[i],res);}
    cout << res << '\n';
  }
  return 0;
}