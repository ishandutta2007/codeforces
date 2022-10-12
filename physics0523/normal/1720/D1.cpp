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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
      int cur=1;
      for(int j=max(0,i-256);j<i;j++){
        if((a[j]^i)<(a[i]^j)){cur=max(cur,dp[j]+1);}
      }
      dp[i]=max(dp[i],cur);
    }

    int res=1;
    for(auto &nx : dp){res=max(res,nx);}
    cout << res << "\n";
  }
  return 0;
}