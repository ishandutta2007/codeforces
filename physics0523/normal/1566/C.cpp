#include<bits/stdc++.h>

using namespace std;

int mex(string s){
  int fl=0;
  for(auto &nx : s){
    if(nx=='0'){fl|=1;}
    else if(nx=='1'){fl|=2;}
  }
  if(fl==3){return 2;}
  if(fl==1){return 1;}
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    string s1,s2;
    cin >> n >> s1 >> s2;
    vector<int> dp(n+1,0);
    for(int i=0;i<n;i++){
      string s;
      for(int j=0;j<5;j++){
        if(i+j>=n){break;}
        s.push_back(s1[i+j]);
        s.push_back(s2[i+j]);
        dp[i+j+1]=max(dp[i+j+1],dp[i]+mex(s));
      }
    }
    cout << dp[n] << '\n';
  }
  return 0;
}