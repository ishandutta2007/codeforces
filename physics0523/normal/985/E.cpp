#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k,d;
  cin >> n >> k >> d;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  sort(a.begin(),a.end());
  a.push_back(2.1e9);
  vector<int> dp(n+5,0);
  dp[0]=1;
  dp[1]=-1;
  int p=0;
  for(int i=0;i<n;i++){
    if(dp[i]<=0){continue;}
    while(a[i]+d>=a[p]){p++;}
    if((i+k)<(p+1)){
      dp[i+k]++;
      dp[p+1]--;
    }
    dp[i+1]+=dp[i];
  }
  if(dp[n]>0){cout << "YES\n";}
  else{cout << "NO\n";}
  return 0;
}