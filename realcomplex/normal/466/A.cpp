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

const int N = 1014;
int dp[N];

int main(){
  fastIO;
  memset(dp, 124421942, sizeof dp);
  int n,m,a,b;
  cin >> n >> m >> a >> b;
  dp[0] = 0;
  for(int i = 1;i <= n;i ++ ){
    dp[i] = min(dp[i], dp[i - 1] + a);
    dp[i] = min(dp[i], dp[max(0, i - m)] + b);
  }
  cout << dp[n];
  return 0;
}