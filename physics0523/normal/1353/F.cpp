#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;

long long dp[128][128];
long long a[128][128];
long long n,m;

long long cup(int sa,int sb){
  for(int i=sa;i<n;i++){
    for(int j=sb;j<m;j++){dp[i][j]=llinf;}
  }
  dp[sa][sb]=0;
  for(int i=sa;i<n;i++){
    for(int j=sb;j<m;j++){
      long long d=(i-sa)+(j-sb),th;
      th=a[sa][sb]+d;
      if(a[i][j]<th){continue;}
      
      d=a[i][j]-th;
      if(i!=sa){
        dp[i][j]=min(dp[i-1][j]+d,dp[i][j]);
      }
      if(j!=sb){
        dp[i][j]=min(dp[i][j-1]+d,dp[i][j]);
      }
    }
  }
  return dp[n-1][m-1];
}

long long cdw(int sa,int sb){
  for(int i=0;i<=sa;i++){
    for(int j=0;j<=sb;j++){dp[i][j]=llinf;}
  }
  dp[sa][sb]=0;
  for(int i=sa;i>=0;i--){
    for(int j=sb;j>=0;j--){
      long long d=(sa-i)+(sb-j),th;
      th=a[sa][sb]-d;
      if(a[i][j]<th){continue;}

      d=a[i][j]-th;
      if(i!=sa){
        dp[i][j]=min(dp[i+1][j]+d,dp[i][j]);
      }
      if(j!=sb){
        dp[i][j]=min(dp[i][j+1]+d,dp[i][j]);
      }
    }
  }
  return dp[0][0];
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    cin >> n >> m;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin >> a[i][j];
      }
    }
    long long res=llinf;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        res=min(cup(i,j)+cdw(i,j),res);
      }
    }
    cout << res << '\n';
  }
  return 0;
}