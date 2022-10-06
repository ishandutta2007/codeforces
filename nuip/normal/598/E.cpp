#include<bits/stdc++.h>
using namespace std;

#define rep(i,j) for(int i=0;i<(j);i++)
#define eb emplace_back
#define all(X) (X).begin(),(X).end()
#define Re real()
#define Im imag()
#define X first
#define Y second

typedef pair<int,int> pii;
typedef long long ll;
typedef complex<ll> P;

vector<pair<P,int> > c;
int a1, a2;
int n;

const ll INF=1e17;
ll dp[40][40][55];

int main(){
  fill(dp[0][0],dp[0][0]+40*40*55,INF);
  rep(n,33)rep(m,33){
    dp[n][m][0]=0;
    if(n*m<52) dp[n][m][n*m]=0;
  }
  rep(n,33)rep(m,33)rep(t,53){
    rep(i,n)if(i){
      rep(j,t+1)
	dp[n][m][t]=min(dp[n][m][t],
			dp[i][m][j]+dp[n-i][m][t-j]+m*m);
    }
    rep(i,m)if(i){
      rep(j,t+1)
	dp[n][m][t]=min(dp[n][m][t],
			dp[n][i][j]+dp[n][m-i][t-j]+n*n);
    }
  }

  int q;
  cin>>q;
  while(q--){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<dp[a][b][c]<<endl;
  }
  return 0;

}