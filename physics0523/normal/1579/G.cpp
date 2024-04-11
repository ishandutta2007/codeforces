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
    vector<int> dp(2005);
    for(int i=0;i<2005;i++){dp[i]=i;}
    for(auto &nx : a){
      cin >> nx;
      vector<int> ndp(2005,114514);
      for(int i=0;i<2005;i++){
        int mi=i-nx,pl=i+nx;
        if(0<=mi && mi<2005){ndp[mi]=max(mi,min(dp[i],ndp[mi]));}
        if(0<=pl && pl<2005){ndp[pl]=max(pl,min(dp[i],ndp[pl]));}
      }
      dp.swap(ndp);
    }
    int res=114514;
    for(auto &nx : dp){res=min(nx,res);}
    cout << res << '\n';
  }
  return 0;
}