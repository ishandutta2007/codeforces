#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 1005;
const int K = 55;

int dp[2][N][K][K];
int l[N];
int r[N];

int main(){
  fastIO;
  int n,p,k;
  cin >> n >> p >> k;
  p = min ( p , ((n + k - 1) / k) * 2);
  int cur,las;
  int m;
  int x;
  cin >> m;
  for(int i = 1;i<=m;i++){
    cin >> x;
    l[x] = 1;
  }
  cin >> m;
  for(int i = 1;i<=m;i++){
    cin >> x;
    r[x] = 1;
  }
  cur = 1;
  las = 0;
  int a,b;
  for(int i = 0; i < 2 ;i ++){
    for(int j = 0;j <= p;j ++ ){
      for(int x = 0;x < k ; x++){
        for(int z = 0 ; z < k ; z ++ )
          dp[i][j][x][z] = -1e9;
      }
    }
  }
  dp[0][0][0][0] = 0;
  for(int i = 1;i <= n;i++){
    for(int j = 1; j <= p;j ++){
      dp[cur][j][k-1][0] = max(dp[cur][j][k-1][0],
      dp[las][j - 1][0][0] + l[i]);
    }
    for(int j = 1;j<=p;j ++ ){
      for(int a = 0 ; a < k - 1;a ++ ){
        dp[cur][j][a][0] = max(dp[cur][j][a][0],
        dp[las][j][a + 1][0] + l[i]);
      }
    }
    for(int j = 1;j <= p; j ++ ){
      dp[cur][j][0][k-1] = max(dp[cur][j][0][k-1],
      dp[las][j - 1][0][0] + r[i]);
    }
    for(int j = 1; j <= p;j ++ ){
      for(int a = 0 ;a < k - 1;a ++ ){
        dp[cur][j][0][a] = max(dp[cur][j][0][a],
        dp[las][j][0][a + 1] + r[i]);
      }
    }
    /* */
    for(int j = 1;j <= p ; j ++ ){
      for(int a = 0 ; a < k - 1; a ++ ){
        dp[cur][j][a][k-1] = max(dp[cur][j][a][k-1],
        dp[las][j - 1][a + 1][0] + (l[i] | r[i]));
      }
    }
    for(int j = 1;j <= p;j ++ ){
      for(int a = 0; a < k - 1;a ++ ){
        dp[cur][j][k-1][a] = max(dp[cur][j][k-1][a],
        dp[las][j - 1][0][a + 1] + (l[i] | r[i]));
      }
    }
    for(int j = 2;j <= p ;j ++ ){
      for(int a = 0; a < k - 1;a ++ ){
        for(int b = 0 ;b < k - 1; b ++ ){
          dp[cur][j][a][b] = max(dp[cur][j][a][b],
          dp[las][j][a + 1][b + 1] + (l[i] | r[i]));
        }
      }
    }
    /* */
    for(int j = 0;j<= p;j ++ ){
      dp[cur][j][0][0] = max(dp[cur][j][0][0], dp[las][j][0][0]); 
    }
    for(int j = 0;j <= p;j ++ ){
      for(int a = 0; a < k ; a ++ ){
        for(int b = 0 ;b < k ;b ++ ){
          dp[las][j][a][b] = -1e9;
        }
      }
    }
    cur = !cur;
    las = !las;
  }
  int ans = 0;
  for(int j = 1; j <= p;j ++){
    for(int x = 0 ; x < k ; x ++ ){
      for(int y = 0 ;y < k ; y ++ ){
        ans = max(ans,dp[n & 1][j][x][y]);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}