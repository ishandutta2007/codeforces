#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
const int LOG = 19;

int pp[N];
bool ist[N];
int ans[N];

int fin(int u){ 
  if(u == pp[u]) return u;
  return pp[u]=fin(pp[u]);
}

bool unite(int a, int b){
  a = fin(a);
  b = fin(b);
  if(a == b) return false;
  pp[a] = b;
  return true;
}

int u[N], v[N], c[N];
vector<pii> T[N];

int par[LOG][N];
int mx[LOG][N];
int tin[N];
int tout[N];
int tt;

void dfs(int u, int pp, int id){
  tin[u] = ++tt;
  par[0][u] = pp;
  mx[0][u] = c[id];
  for(int i = 1; i < LOG; i ++ ){
    par[i][u] = par[i-1][par[i-1][u]];
    mx[i][u] = max(mx[i-1][u], mx[i-1][par[i-1][u]]);
  }
  for(auto x : T[u]){
    if(x.fi != pp){
      dfs(x.fi, u, x.se);
    }
  }
  tout[u] = tt;
}

bool is_anc(int a, int b){
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b){
  if(is_anc(a,b)) return a;
  if(is_anc(b,a)) return b;
  for(int i = LOG - 1; i >= 0 ; i -- ){
    if(!is_anc(par[i][a], b)){
      a = par[i][a];
    }
  }
  return par[0][a];
}

int get_max(int a, int b){
  int mix = 0;
  for(int i = LOG - 1; i >= 0 ; i -- ){
    if(!is_anc(par[i][a],b)){
      mix = max(mix, mx[i][a]);
      a = par[i][a];
    }
  }
  if(!is_anc(a, b)){
    mix = max(mix, mx[0][a]);
  }
  for(int i = LOG - 1; i >= 0 ; i -- ){
    if(!is_anc(par[i][b],a)){
      mix = max(mix, mx[i][b]);
      b = par[i][b];
    }
  }
  if(!is_anc(b, a)){
    mix = max(mix, mx[0][b]);
  }
  return mix;
}

multiset<int> add[N];
multiset<int> rem[N];

void dfs1(int u, int par, int id){
  for(auto x : T[u]){
    if(x.fi == par) continue;
    dfs1(x.fi, u, x.se);
    if(add[x.fi].size() > add[u].size()) swap(add[u], add[x.fi]);
    for(auto p : add[x.fi])
      add[u].insert(p);
    add[x.fi].clear();
  }
  for(auto p : rem[u]){
    add[u].erase(add[u].find(p));
    add[u].erase(add[u].find(p));
  }
  if(add[u].empty()){
    ans[id] = -1;
  }
  else{
    ans[id] = (*add[u].begin() - 1);
  }
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++ ) pp[i] = i;
  vector<pii> ed;
  for(int i = 1; i <= m ; i ++ ){
    cin >> u[i] >> v[i] >> c[i];
    ed.push_back(mp(c[i], i));
    ans[i] = -1;
  }
  sort(ed.begin(), ed.end());
  for(auto p : ed){
    if(unite(u[p.se], v[p.se])){
      T[u[p.se]].push_back(mp(v[p.se], p.se));
      T[v[p.se]].push_back(mp(u[p.se], p.se));
      ist[p.se] = true;
    }
  }
  dfs(1,1,0);
  for(int i = 1; i <= m ; i ++ ){
    if(!ist[i]){
      ans[i] = get_max(u[i], v[i]) - 1;
      add[u[i]].insert(c[i]);
      add[v[i]].insert(c[i]);
      rem[lca(u[i],v[i])].insert(c[i]);
    }
  }
  dfs1(1,-1,0);
  for(int i = 1; i <= m ; i ++ ) cout << ans[i] << " ";
  return 0;
}