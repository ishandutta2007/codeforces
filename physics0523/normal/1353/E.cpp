#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    s="0"+s;n++;
    vector<int> rw(n,0),dp(k+2,1000000007);
    int st=k,fi=k+1;
    for(int i=1;i<n;i++){
      rw[i]=rw[i-1];
      if(s[i]=='1'){rw[i]++;}
    }
    dp[st]=0;

    for(int i=1;i<n;i++){
      if(s[i]=='1'){dp[fi]++;}
      
      int dlt;
      if(i<=k){dlt=0;}
      else{dlt=rw[i-1]-rw[i-k];}
      dp[fi]=min(dp[fi],dp[i%k]+dlt);
      dp[fi]=min(dp[fi],dp[st]);

      if(s[i]=='0'){dlt++;}
      dp[i%k]+=dlt;
      dp[i%k]=min(dp[st],dp[i%k]);
      
      if(s[i]=='1'){dp[st]++;}
    }
    cout << dp[fi] << '\n';
  }
}