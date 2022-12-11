#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 9;
// n sqrt(n) log(n) my favorite complexity
int par[N];

int fin(int u){
  if(u == par[u]) return u;
  return par[u] = fin(par[u]);
}

vector<int> T[N];

int mx[N];

void dfs(int u, int par){
  for(auto x : T[u]){
    if(x == par) continue;
    dfs(x, u);
    mx[u] = max(mx[u], mx[x] + 1);
  }
}

vector<int> dd[N];
vector<int> ss[N];

void dfs2(int u, int par, int mm){
  dd[fin(u)].push_back(max(mx[u], mm));
  int m1 = 0, m2 = 0;
  for(auto x : T[u]){
    if(x == par) continue;
    if(mx[x] + 1 > mx[m1] + 1){
      m2 = m1;
      m1 = x;
    }
    else if(mx[x] + 1 > mx[m2] + 1){
      m2 = x;
    }
  }
  int nx;
  for(auto x : T[u]){
    if(x == par) continue;
    nx = mm + 1;
    if(x != m1) nx = max(nx, mx[m1] + 2);
    else nx = max(nx, mx[m2] + 2);
    dfs2(x, u, nx);
  }
}

map<pii, ld> memo;

int main(){
  fastIO;
  mx[0] = -500;
  int n, m, q;
  cin >> n >> m >> q;
  int u, v;
  for(int i = 1; i <= n; i ++ ) par[i] = i;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
    par[fin(u)] = fin(v);
  }
  for(int i = 1; i <= n; i ++ ){
    if(par[i] == i){
      dfs(i,-1);
      dfs2(i,-1,0);
      sort(dd[i].begin(), dd[i].end());
      ss[i].resize(dd[i].size() + 1);
      for(int j = dd[i].size() - 1; j >= 0 ; j -- ){
        ss[i][j] = dd[i][j];
        ss[i][j] += ss[i][j + 1];
      }
    }
  }
  int lim;
  ld sum;
  ld par;
  int id;
  for(int i = 0 ; i < q; i ++ ){
    cin >> u >> v;
    u = fin(u);
    v = fin(v);
    if(dd[u].size() > dd[v].size()) swap(u, v);
    if(u == v) cout << -1 << "\n";
    else if(memo.count(mp(u,v))) cout << memo[mp(u, v)] << "\n";
    else{
      lim = max(dd[u].back(), dd[v].back());
      sum = 0;
      for(auto x : dd[u]){
        id = lower_bound(dd[v].begin(), dd[v].end(), lim-1-x) - dd[v].begin();
        sum += ((ld)dd[v].size() - id) * 1ll * (x + 1);
        sum += ss[v][id];
        sum += id * 1ll * lim;
      }
      par = (ld)dd[u].size() * 1ll * (ld)dd[v].size();
      sum /= par;
      memo[mp(u,v)] = sum;
      cout << fixed << setprecision(10) << sum << "\n";
    }
  }
  return 0;
}