#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
const int M = 11;
const int MOD = (int)1e9 + 7;
int dp[M][N];

int main(){
  fastIO;
  for(int i = 1; i < N; i ++ )
    dp[1][i] = 1;
  int f;
  for(int i = 2; i < M ; i ++ ){
    f = 0;
    for(int j = 1; j < N ; j ++ ){
      f += dp[i-1][j];
      if(f >= MOD) f-=MOD;
      dp[i][j]=f;
    }
  }
  int n, m;
  cin >> n >> m;
  int res = 0;
  for(int i = 1; i <= n; i ++ ){
    for(int j = i; j <= n; j ++ ){
      res += (dp[m][i] * 1ll * dp[m][n-j+1]) % MOD;
      if(res >= MOD) res -= MOD;
    }
  }
  cout << res;
  return 0;
}