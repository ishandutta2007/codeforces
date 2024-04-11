#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = 2005;
ll dp[N];
int main(){
  fastIO;
  for(int x = 0; x < N; x ++ )
    dp[x] = (ll)1e18;
  dp[0] = 0;
  int n;
  cin >> n;
  int t;
  ll c;
  for(int i = 1;i <= n;i ++ ){
    cin >> t >> c;
    t ++ ;
    for(int j = n;j >= 1;j -- ){
      dp[j] = min(dp[j], dp[max(0, j - t)] + c);
    }
  }
  cout << dp[n];
  return 0;
}