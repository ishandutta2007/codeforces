#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = 205;
const int K = 1005;
const ll MOD = (int)1e9 + 7;

int dp[N][N][K];
int a[N];

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  for(int i = 1;i <= n;i ++ )
    cin >> a[i];
  sort(a, a + n + 1);
  dp[0][0][0] = 1;
  int wl;
  ll last;
  for(int i = 1;i <= n; i++ ){
    for(int j = 0;j < i; j ++ ){
      for(int x = 0; x <= k; x ++ ){
        wl = x + (a[i] - a[i - 1]) * j ;
        if(wl > k)
          continue;
        last = dp[i - 1][j][x];
        dp[i][j][wl] = (dp[i][j][wl] + 1ll * last * (j + 1)) % MOD; // continue an existing group 
        dp[i][j + 1][wl] += (dp[i][j + 1][wl] + 1ll * last) % MOD; // start a new group
        if(j > 0)
          dp[i][j - 1][wl] = (dp[i][j - 1][wl] + 1ll * last * j) % MOD; // end an existing group;
      } 
    }
  }
  ll ans = 0;
  for(int i = 0; i <= k;i ++ ){
    ans += dp[n][0][i];
    ans %= MOD;
  }
  cout << ans;
  return 0;
}