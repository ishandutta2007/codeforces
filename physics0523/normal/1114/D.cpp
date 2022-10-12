#include<bits/stdc++.h>

using namespace std;

int sl[5005];
int sr[5005];
int c[5005];
int dp[5005][5005];

int rep(int l,int r){
  if(l>r){return 0;}
  if(dp[l][r]>=0){return dp[l][r];}
  dp[l][r]=1e9;
  if(c[l]==c[r]){
    dp[l][r]=min(dp[l][r],1+rep(sr[l]+1,sl[r]-1));
  }
  else{
    dp[l][r]=min(dp[l][r],1+rep(sr[l]+1,r));
    dp[l][r]=min(dp[l][r],1+rep(l,sl[r]-1));
  }
  return dp[l][r];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i=0;i<5005;i++){
    for(int j=0;j<5005;j++){
      dp[i][j]=-1;
    }
  }

  int n;
  cin >> n;
  c[0]=-1;
  c[n+1]=-2;
  for(int i=1;i<=n;i++){
    cin >> c[i];
  }

  int pt=0;
  for(int i=0;i<=n;i++){
    if(c[i]!=c[i+1]){pt=i+1;}
    sl[i+1]=pt;
  }

  pt=n+1;
  for(int i=n;i>=0;i--){
    if(c[i]!=c[i+1]){pt=i;}
    sr[i]=pt;
  }

  cout << rep(1,n)-1 << "\n";
}