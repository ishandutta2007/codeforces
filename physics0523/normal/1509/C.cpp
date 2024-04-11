#include<bits/stdc++.h>

using namespace std;

long long n;
vector<long long> a;
long long dp[2005][2005];

long long rep(long long l,long long r,long long ce){
  if(l==r){return 0;}
  if(dp[l][r]!=-1){return dp[l][r];}
  dp[l][r]=rep(l+1,r,ce+1)+ce*(a[l+1]-a[l]);
  dp[l][r]=min(dp[l][r],rep(l,r-1,ce+1)+ce*(a[r]-a[r-1]));
  return dp[l][r];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i=0;i<2005;i++){
    for(int j=0;j<2005;j++){dp[i][j]=-1;}
  }
  cin >> n;
  a.resize(n);
  for(auto &nx : a){cin >> nx;}
  sort(a.begin(),a.end());
  cout << rep(0,n-1,1) << '\n';
  return 0;
}