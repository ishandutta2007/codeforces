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
    string s;
    cin >> n >> s;
    s.push_back('0');
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<long long> dp(2,-8e18);
    if(s[0]=='0'){dp[0]=0;}else{dp[1]=0;}
    for(int i=0;i<n;i++){
      vector<long long> ndp(2,-8e18);
      if(s[i+1]=='0'){
        ndp[0]=max(dp[0],dp[1]+a[i]);
      }
      else{
        ndp[0]=dp[0]+a[i];
        ndp[1]=max(dp[1]+a[i],dp[0]);
      }
      dp=ndp;
    }
    cout << max(dp[0],dp[1]) << "\n";
  }
  return 0;
}