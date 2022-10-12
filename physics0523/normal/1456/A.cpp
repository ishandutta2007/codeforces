#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,p,k;
    cin >> n >> p >> k;
    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;
    vector<int> dp(n+1,2000000007);
    for(int i=p-1;i<n;i++){
      dp[i]=(i-(p-1))*y;
    }
    for(int i=p-1;i<n;i++){
      if(s[i]=='1'){dp[min(n,i+k)]=min(dp[min(n,i+k)],dp[i]);}
      else{dp[min(n,i+k)]=min(dp[min(n,i+k)],dp[i]+x);}
    }
    cout << dp[n] << '\n';
  }
}