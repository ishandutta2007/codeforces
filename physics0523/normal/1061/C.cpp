#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

vector<int> div(int x){
  vector<int> res;
  for(int i=1;i*i<=x;i++){
    if(x%i==0){
      res.push_back(i);
      if(i*i!=x){res.push_back(x/i);}
    }
  }
  sort(res.begin(),res.end());
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> dp(1048576,0);
  dp[1]=1;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    vector<int> dv=div(v);
    for(int j=dv.size()-1;j>=0;j--){
      dp[dv[j]+1]+=dp[dv[j]];
      dp[dv[j]+1]%=mod;
    }
  }
  int res=0;
  for(auto &nx : dp){
    res+=nx;res%=mod;
  }
  res+=(mod-1);res%=mod;
  cout << res << '\n';
  return 0;
}