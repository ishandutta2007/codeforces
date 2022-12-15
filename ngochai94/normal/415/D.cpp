#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long dp[2222][2222], n, k;
vector<int> dvs[2222];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  FOR (i, 1, n) for (int j = i; j <= n; j += i) dvs[j].pb(i);
  FOR (i, 1, n) dp[i][1] = 1;
  FOR (j, 2, k) FOR (i, 1, n) for (int prev: dvs[i]) dp[i][j] = (dp[i][j] + dp[prev][j - 1]) % mod;
  long long ans = 0;
  FOR (i, 1, n) ans = (ans + dp[i][k]) % mod;
  cout << ans;
}