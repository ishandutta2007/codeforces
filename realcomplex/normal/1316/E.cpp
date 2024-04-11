#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int M = 7;
const ll inf = (ll)1e18;

ll dp[N][(1<<M)];
ll a[N];
ll st[N][M];

int main(){
  fastIO;
  for(int i = 0 ; i < N ; i ++ )
    for(int j = 0 ; j < (1 << M) ; j ++ )
      dp[i][j] = -inf;
  vector<pii> s;
  int n, p, k;
  cin >>n >> p >> k;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    s.push_back(mp(a[i],i));
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 0; j < p; j ++ ) cin >> st[i][j];
  }
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  ll aa;
  int mask;
  int cnt;
  dp[0][0] = 0;
  for(int i = 0 ; i < n; i ++ ){
    aa = s[i].fi;
    for(int j = 0 ; j < (1 << p) ; j ++ ){
      cnt = __builtin_popcount(j);
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (i+1-cnt <= k ? 1 : 0) * aa);
    }
  
    for(int j = 0 ; j < p ; j ++ ){
      for(int q = 0 ; q < (1 << p); q ++ ){
        if((q&(1 << j))) continue;
        mask = q;
        mask |= (1 << j);
        dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][q] + st[s[i].se][j]);
      }
    }
  }
  cout << dp[n][(1<<p)-1];
  return 0;
}