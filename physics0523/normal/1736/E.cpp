#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n+5);
  a[0]=0;
  for(int i=1;i<=n;i++){cin >> a[i];}

  vector<vector<int>> dp(n+5,vector<int>(n+5,-1e9));
  dp[0][0]=0;
  for(int p=1;p<=n;p++){
    vector<vector<int>> ndp(n+5,vector<int>(n+5,-1e9));
    vector<int> hpopt(n+5,-1e9);
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
        if(dp[i][j]<0){continue;}
        ndp[i][j]=max(ndp[i][j],dp[i][j]+a[i]);
        if(p!=i){
          ndp[p][j+1]=max(ndp[p][j+1],dp[i][j]+a[p]);
        }
        hpopt[j+1]=max(hpopt[j+1],dp[i][j]);
      }
    }
    for(int h=1;h<=n;h++){
      if(hpopt[h]<0){continue;}
      int rig=min(n-p,h);
      for(int i=1;i<=rig;i++){
        ndp[p+i][h-i]=max(ndp[p+i][h-i],hpopt[h]+a[p+i]);
      }
    }
    dp=ndp;
    // for(int i=0;i<=n;i++){
    //   for(int j=0;j<=n;j++){
    //     cout << dp[i][j] << " ";
    //   }cout << "\n";
    // }cout << "\n";
  }

  int res=0;
  for(auto &nx : dp){
    for(auto &ny : nx){res=max(res,ny);}
  }
  cout << res << "\n";
  return 0;
}