#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;
const int M = (int)1e4 + 2;
const int K = 2002;
const ll inf = (ll)1e18;
ll dp[M][K];
bool safe[N];
int nxR[N];
int nxL[N];
int mod;

int add(int a, int b){
  a += b;
  if(a >= mod) a -= mod;
  else if(a < 0) a += mod;
  return a;
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int d;
  vector<int> lis;
  for(int i = 1; i <= m ; i ++ ){
    cin >> d;
    safe[d] = true;
  }
  nxL[0] = 0;
  for(int i = 0; i <= n; i ++ ){
    if(safe[i]) nxL[i] = i;
    else nxL[i] = nxL[i-1];
    if(safe[i])lis.push_back(i);
  }
  nxR[n + 1] = n + 1;
  for(int i = n; i >= 0; i -- ){
    if(safe[i]) nxR[i] = i;
    else nxR[i] = nxR[i+1];
  }
  int r, g;
  cin >> g >> r;
  mod = r + g;
  for(int i = 0 ; i < m; i ++ ){
    for(int j = 0 ; j < mod ;j  ++ )
      dp[i][j] = inf;
  }
  queue<pii> bf;
  bf.push(mp(0,0));
  dp[0][0] = 0;
  int p, q;
  int dis;
  while(!bf.empty()){
    p = bf.front().fi;
    q = bf.front().se;
    bf.pop();
    if(lis[p] < n){
      dis = nxR[lis[p] + 1] - lis[p];
      if(q <= g && q + dis <= g && dp[p + 1][q + dis] > dp[p][q] + dis){
        dp[p + 1][q + dis] = dp[p][q] + dis;
        bf.push(mp(p + 1, q + dis));
      }
    }
    if(lis[p] > 0){
      dis = lis[p] - nxL[lis[p] - 1];
      if(q <= g && q + dis <= g && dp[p - 1][q + dis] > dp[p][q] + dis){
        dp[p - 1][q + dis] = dp[p][q] + dis;
        bf.push(mp(p - 1, q + dis));
      }
    }
    if(q >= g && dp[p][q] + 1 < dp[p][add(q,1)]){
      dp[p][add(q,1)] = dp[p][q] + 1;
      bf.push(mp(p, add(q, 1)));
    }
  }
  ll ans = inf;
  for(int i = 0 ; i < mod; i ++ ) 
    ans = min(ans, dp[m-1][i]);
  if(ans == inf) cout << -1;
  else cout << ans << "\n";
  return 0;
}