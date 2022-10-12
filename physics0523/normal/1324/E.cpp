#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,h,l,r;
  cin >> n >> h >> l >> r;
  vector<int> dp(h,-1e9);
  dp[0]=0;
  for(int i=0;i<n;i++){
    vector<int> ndp(h,-1e9);
    int v;
    cin >> v;
    for(int j=0;j<h;j++){
      for(int d=-1;d<=0;d++){
        int nx=(h+j+v+d)%h;
        int val=dp[j];
        if(l<=nx && nx<=r){val++;}
        ndp[nx]=max(ndp[nx],val);
      }
    }
    dp=ndp;
  }
  int res=0;
  for(auto &nx : dp){res=max(res,nx);}
  cout << res << '\n';
  return 0;
}