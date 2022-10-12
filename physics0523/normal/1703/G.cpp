#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<long long> dp(40,-8e18);
    dp[0]=0;
    for(int i=0;i<n;i++){
      vector<long long> ndp(40,-8e18);
      for(int j=0;j<=39;j++){
        ndp[j]=max(ndp[j],dp[j]+(a[i]>>j)-k);
        ndp[min(39,j+1)]=max(ndp[min(39,j+1)],dp[j]+(a[i]>>(j+1)));
      }
      dp=ndp;
    }
    long long res=0;
    for(auto &nx : dp){res=max(res,nx);}
    cout << res << '\n';
  }
  return 0;
}