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

const int K = (int)1e5 + 9;
const ll MOD = (ll)1e9 + 7;

int dp[2][K];

int main(){
  fastIO;
  string f, t;
  cin >> f >> t;
  int k;
  cin >> k;
  int n = f.size();
  int good = 0, bad = 0;
  bool match;
  int ix;
  for(int i = 0;i < n; i ++ ){
    match = true;
    for(int j = 0;j < n;j ++ ){
      ix = j + i;
      ix %= n;
      if(f[ix] != t[j])
        match = false;
    }
    if(match)
      good ++ ;
    else
      bad ++ ;
  }
  if(f == t)
    dp[0][0] = 1, dp[1][0] = 0;
  else
    dp[0][0] = 0, dp[1][0] = 1;
  for(int i = 1; i <= k ;i ++ ){
    dp[0][i] = ((1LL * dp[0][i - 1] * (good - 1)) + (1LL * dp[1][i - 1] * good))% MOD;
    dp[1][i] = ((1LL * dp[0][i - 1] * bad) + (1LL * dp[1][i - 1] * (bad - 1))) % MOD;
  }
  cout << dp[0][k];
  return 0;
}