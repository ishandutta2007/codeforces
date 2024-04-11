#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> dp(512,1000);
  dp[0]=0;
  for(int i=0;i<n;i++){
    vector<int> ndp=dp;
    int v;
    cin >> v;
    for(int i=0;i<512;i++){
      if(dp[i]<v){
        ndp[i^v]=min(ndp[i^v],v);
      }
    }
    dp.swap(ndp);
  }
  vector<int> res;
  for(int i=0;i<512;i++){
    if(dp[i]<1000){res.push_back(i);}
  }
  cout << res.size() << '\n';
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}