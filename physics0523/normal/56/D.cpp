#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s,t;
  cin >> s >> t;
  swap(s,t);

  int n=s.size();
  int m=t.size();
  vector<vector<pi>> dp(n+1,vector<pi>(m+1,{1e9,1e9}));
  dp[0][0]={0,-1};
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i<n && j<m){
        if(s[i]==t[j]){
          // nothing
          dp[i+1][j+1]=min(dp[i+1][j+1],{dp[i][j].first,0});
        }
        else{
          // replace
          dp[i+1][j+1]=min(dp[i+1][j+1],{dp[i][j].first+1,1});
        }
      }
      if(j<m){
        // delete
        dp[i][j+1]=min(dp[i][j+1],{dp[i][j].first+1,2});
      }
      if(i<n){
        // insert
        dp[i+1][j]=min(dp[i+1][j],{dp[i][j].first+1,3});
      }
    }
  }
  // for(int i=0;i<=n;i++){
  //   for(int j=0;j<=m;j++){
  //     cout << dp[i][j].first << ' ';
  //   }cout << '\n';
  // }
  int ci=n,cj=m;
  vector<string> typ;
  while(ci!=0 || cj!=0){
    int tn=dp[ci][cj].second;
    if(tn==0){
      typ.push_back("NA");
      ci--;cj--;
    }
    else if(tn==1){
      typ.push_back("REPLACE");
      ci--;cj--;
    }
    else if(tn==2){
      typ.push_back("DELETE");
      cj--;
    }
    else if(tn==3){
      typ.push_back("INSERT");
      ci--;
    }
  }
  reverse(typ.begin(),typ.end());
  cout << dp[n][m].first << '\n';
  ci=0;cj=0;
  for(auto &nx : typ){
    if(nx=="NA"){ci++;cj++;}
    if(nx=="REPLACE"){
      cout << nx << ' ' << ci+1 << ' ' << s[ci] << '\n';
      ci++;cj++;
    }
    if(nx=="DELETE"){
      cout << nx << ' ' << ci+1 << '\n';
      cj++;
    }
    if(nx=="INSERT"){
      cout << nx << ' ' << ci+1 << ' ' << s[ci] << '\n';
      ci++;
    }
  }
  return 0;
}