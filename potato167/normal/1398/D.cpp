#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int R,G,B;
  cin>>R>>G>>B;
  int64_t Z=0;
  vector<int64_t> r(205);
  vector<int64_t> g(205);
  vector<int64_t> b(205);
  for(int i=0;i<R;i++){
    cin>>r[i];
  }
  for(int i=0;i<G;i++){
    cin>>g[i];
  }
  for(int i=0;i<B;i++){
    cin>>b[i];
  }
  sort(r.begin(),r.end());
  sort(g.begin(),g.end());
  sort(b.begin(),b.end());
  reverse(r.begin(),r.end());
  reverse(g.begin(),g.end());
  reverse(b.begin(),b.end());
  vector<vector<vector<int64_t>>> dp(206,vector<vector<int64_t>>(206,vector<int64_t>(206)));
  for(int l=0;l<=612;l+=2){
    for(int i=0;i<205;i++){
    for(int j=0;j<205;j++){
      int k=l-i-j;
      if(k<0||204<k){
        continue;
      }
        dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+r[i]*g[j]);
        dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+r[i]*b[k]);
        dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]+b[k]*g[j]);
       Z=max(Z,dp[i+1][j+1][k]);
      Z=max(Z,dp[i+1][j][k+1]);
      Z=max(Z,dp[i][j+1][k+1]);
      }
    }
  }
  cout<<Z<<endl;
}