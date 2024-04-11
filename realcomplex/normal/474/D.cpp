#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

#define N 124567

const int MOD = (int)1e9 + 7;
int dp[N];

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  dp[0] = 1;
  for(int i = 1;i < N;i ++ ){
    dp[i] += dp[i - 1];
    dp[i] %= MOD;
    if(i >= k)dp[i] += dp[i - k];
    dp[i] %= MOD;
  } 
  for(int i = 1;i < N;i ++ ){
    dp[i] += dp[i - 1];
    dp[i] %= MOD;
  }
  int l, r;
  for(int i = 1; i <= n;i ++ ){
    cin >> l >> r;
    l -- ;
    cout << (dp[r] - dp[l] + MOD) % MOD << "\n";
  }
  return 0;
}