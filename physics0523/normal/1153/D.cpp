#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n+1);
  vector<int> p(n+1);
  Graph g(n+1);
  for(int i=1;i<=n;i++){cin >> a[i];}

  for(int i=2;i<=n;i++){
    cin >> p[i];
    g[p[i]].push_back(i);
  }
  
  int k=0;
  vector<int> dp(n+1,0);
  for(int i=n;i>=1;i--){
    if(g[i].empty()){
      dp[i]=1;
      k++;
      continue;
    }
    if(a[i]==0){ // min
      for(auto &nx : g[i]){
        dp[i]+=dp[nx];
      }
    }
    else{ // max
      dp[i]=1e9;
      for(auto &nx : g[i]){
        dp[i]=min(dp[i],dp[nx]);
      }
    }
  }
  cout << k+1-dp[1] << '\n';
  return 0;
}