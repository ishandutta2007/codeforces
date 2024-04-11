#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
const int MAX = (int)1e5 + 10;
const int MOD = 998244353;

int dp[N][N];
int pf[N][N];
int a[N];

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i ++ )
    cin >> a[i];
  sort(a + 1, a + n + 1);
  int p;
  int ans = 0;
  for(int d = 1;  d < MAX ; d ++ ){
    if(d * (k - 1) >= MAX || d > a[n]-a[1]) continue;
    for(int i = 1; i <= n; i ++ ){
      for(int j = 1; j <= k ; j ++ ){
        dp[i][j]=0;
        pf[i][j]=0;
      }
    }
    for(int i = 1; i <= n; i ++ ){
      dp[i][1]=1;
      pf[i][1]=i;
    }
    for(int j = 2; j <= k ; j ++ ){
      p = 0;
      for(int i = j; i <= n; i ++ ){
        while(p + 1 < i && a[i] - a[p + 1] >= d)
          p ++ ;
        dp[i][j]=pf[p][j-1];
        pf[i][j]=(dp[i][j] + pf[i-1][j]) % MOD;
      }
    }
    for(int i = k; i <= n; i ++ )
      ans = (ans + dp[i][k]) % MOD;
  }
  cout << ans << "\n";
  return 0;
}