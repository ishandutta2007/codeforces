#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    vector<int> dp(26,-1e9);
    int res=0;
    for(auto &nx : s){
      int send=res;
      res=max(res,dp[nx-'a']+1);
      dp[nx-'a']=max(dp[nx-'a'],send);
    }
    cout << (int)s.size()-2*res << '\n';
  }
  return 0;
}