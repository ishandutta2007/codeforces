#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
int a[200001];
int b[200001];
int dp[200001][2];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,c;cin>>n>>c;
  for (int i=1;i<n;i++) cin>>a[i];
  for (int i=1;i<n;i++) cin>>b[i];
  for (int i=0;i<=n;i++) dp[i][0]=1000000001,dp[i][1]=1000000001;
  dp[1][0]=0;
  for (int i=1;i<n;i++){
      ///relax with dp[i][0] and dp[i][1]
      dp[i+1][0]=min(dp[i][0],dp[i][1])+a[i];
      dp[i+1][1]=min(dp[i][1],dp[i][0]+c)+b[i];
  }
  for (int i=1;i<=n;i++) cout<<min(dp[i][0],dp[i][1])<<" ";
  return 0;
}