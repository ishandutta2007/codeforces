#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 52;
const int M = 20005;
int dp[N][M];
int pf[N][M];
int a[N][M];

int bf[M];
int sf[M];

int intersect(int i, int l, int r, int cl, int cr){
  int il = max(l,cl);
  int ir = min(r,cr);
  return (pf[i][r]-pf[i][l-1])+(pf[i][cr]-pf[i][cl-1])-(pf[i][ir]-pf[i][il-1]);
}

int main(){
  fastIO;
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      cin >> a[i][j];
      pf[i][j]=pf[i][j-1]+a[i][j];
    }
  }
  for(int i = 1; i <= n; i ++ ){
    if(i == 1){
      for(int j = 1; j <= m-k+1; j ++ ){
        dp[i][j]=pf[i][j+k-1]-pf[i][j-1];
      }
    }
    else{
      for(int j = 0 ; j <= m + 1; j ++ )
        bf[j] = 0, sf[j] = 0;
      for(int j = 1; j <= m - k + 1; j ++ ){
        bf[j + k - 1] = dp[i-1][j]+pf[i][j+k-1]-pf[i][j-1];
        bf[j+k-1]=max(bf[j+k-1],bf[j+k-2]);
      }
      for(int j = m; j - k + 1 >= 1; j -- ){
        sf[j - k + 1] = dp[i-1][j-k+1]+pf[i][j]-pf[i][j-k];
        sf[j-k+1]=max(sf[j-k+1],sf[j-k+2]);
      }
      for(int j = 1; j <= m - k + 1; j ++ ){
        dp[i][j]=max(bf[j-1],sf[j+k])+pf[i][j+k-1]-pf[i][j-1];
        for(int l = max(1,j-k+1); l <= min(m,j+k-1); l ++ ){
          dp[i][j] = max(dp[i][j],dp[i-1][l]+intersect(i,j,j+k-1,l,l+k-1));
        }
      }
    }
  }
  int res = 0;
  for(int j = 1; j <= m ; j ++ )
    res = max(res, dp[n][j]);
  cout << res << "\n";
  return 0;
}