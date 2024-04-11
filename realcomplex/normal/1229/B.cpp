#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int LOG = 19;
const int MOD = (int)1e9 + 7;
ll vl[N];
int par[LOG][N];
ll gc[LOG][N];
int dis[N];
vector<int> T[N];

void dfs(int u, int pr){
  par[0][u] = pr;
  gc[0][u] = __gcd(vl[u], vl[pr]);
  for(int i = 1; i < LOG;i ++ ){
    par[i][u] = par[i-1][par[i-1][u]];
    gc[i][u] = __gcd(gc[i-1][u], gc[i-1][par[i-1][u]]);
  }
  for(auto x : T[u]){
    if(x != pr){
      dis[x] = dis[u] + 1;
      dfs(x,u);
    }
  }
}

int res = 0;
void inc(ll x){
  res = (res + (x%MOD)) % MOD;
}

void solve(int ver){
  int nx;
  ll cur = vl[ver];
  while(1){
    nx = ver;
    for(int i = LOG - 1; i >= 0 ; i -- ){
      if(__gcd(cur, gc[i][nx]) == cur){
        nx = par[i][nx];
      }
    }
    inc((dis[ver] - dis[nx] + 1) * 1ll * cur);
    if(nx == 1) break;
    ver = par[0][nx];
    cur = __gcd(cur, vl[ver]);
  }
  
}

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ )
    cin >> vl[i];
  int a, b;
  for(int i = 1; i < n; i ++ ){
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  dfs(1,1);
  for(int i = 1; i <= n; i ++ )
    solve(i);
  cout << res << "\n";
  return 0;
}