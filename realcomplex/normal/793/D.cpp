#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 81;
int dp[N][N][N][N];
vector<pii> T[N];

int k;
int solve(int l, int r, int cur, int dep){
  if(l > r) return -1;
  if(dp[l][r][cur][dep] != (int)1e9+1) return dp[l][r][cur][dep];
  if(dep == k) return 0;
  int low = (int)1e9;
  for(auto x : T[cur]){
    if(x.fi > cur && x.fi <= r){
      low = min(low, solve(cur + 1, r, x.fi, dep + 1) + x.se);
    }
    if(x.fi >= l && x.fi < cur){
      low = min(low, solve(l, cur - 1, x.fi, dep + 1) + x.se);
    }
  }
  dp[l][r][cur][dep] = low;
  return low;
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> k >> m;
  int u, v, c;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> u >> v >> c;
    T[u].push_back(mp(v, c));
  }
  for(int l = 1; l <= n; l ++ ){
    for(int r = l ; r <= n; r ++ ){
      for(int c = l; c <= r; c ++ ){
        for(int d = 1; d <= k; d ++ ){
          dp[l][r][c][d] = (int)1e9 + 1;
        }
      }
    }
  }
  int ans = (int)1e9;
  for(int i = 1; i <= n; i ++ ){
    ans = min(ans, solve(1, n, i, 1));
  }
  if(ans == (int)1e9) cout << -1;
  else cout << ans << "\n";
  return 0;
}