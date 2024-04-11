#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> a(n),b(n);
    long long bas=0;
    for(auto &nx : a){
      cin >> nx;
      bas+=(nx*nx);
    }
    for(auto &nx : b){
      cin >> nx;
      bas+=(nx*nx);
    }
    bas*=(n-1);

    long long res=1e18,sig=0;
    vector<long long> dp(10005,1e18);
    dp[0]=0;
    for(int i=0;i<n;i++){
      vector<long long> ndp(10005,1e18);
      for(long long j=0;j<10005;j++){
        if(dp[j]>9e17){continue;}
        //cout << i << ' ' << j << ' ' << dp[j] << '\n';
        ndp[j+a[i]]=min(ndp[j+a[i]],dp[j]+j*a[i]+(sig-j)*b[i]);
        ndp[j+b[i]]=min(ndp[j+b[i]],dp[j]+j*b[i]+(sig-j)*a[i]);
      }
      sig+=a[i];
      sig+=b[i];
      dp.swap(ndp);
    }
    for(auto &nx : dp){res=min(res,nx);}
    cout << bas+2ll*res << '\n';
  }
  return 0;
}