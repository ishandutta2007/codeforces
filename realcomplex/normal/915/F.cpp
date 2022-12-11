#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e6 + 10;

int par[N];
int sz[N];
bool act[N];

void init(){
  for(int i = 0 ; i < N ; i ++ )
    par[i]=i, sz[i]=1,act[i]=false;
}

int fin(int x){
  if(x==par[x]) return x;
  return par[x]=fin(par[x]);
}


void unite(int u, int v){
  u=fin(u);
  v=fin(v);
  if(u==v) return;
  if(sz[u]>sz[v])swap(u,v);
  sz[v]+=sz[u];
  par[u]=v;
}

vector<int> T[N];

ll f(int n){
  return n * 1ll * (n + 1) / 2ll;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<pii> cc(n);
  for(int i = 0 ; i < n ; i ++ ){
    cin >> cc[i].fi;
    cc[i].se = i + 1;
  }
  sort(cc.begin(), cc.end());
  int u, v;
  for(int i = 1; i < n ; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  vector<int> ids;
  ll sum = 0;
  int nx;
  init();
  ids.clear();
  for(int i = 0; i < n ; i ++ ){
    ids.push_back(cc[i].se);
    if(i + 1 == n || cc[i].fi != cc[i + 1].fi){
      set<int> bf;
      ll cur = 0;
      for(auto x : ids){
        for(auto y : T[x]){
          if(!act[y]) continue;
          nx=fin(y);
          if(!bf.count(nx)){
            cur -= f(sz[nx]);
            bf.insert(nx);
          }
        }
      }
      bf.clear();
      for(auto x : ids) act[x]=true;
      for(auto x : ids){
        for(auto y : T[x]){
          if(act[y])unite(x, y);
        }
      }
      for(auto x : ids){
        nx=fin(x);
        if(!bf.count(nx)){
          cur += f(sz[nx]);
          bf.insert(nx);
        }
      }
      sum += cur * 1ll * cc[i].fi;
      ids.clear();
    }
  }
  init();
  ids.clear();
  for(int i = n - 1; i >= 0 ; i -- ){
    ids.push_back(cc[i].se);
    if(i == 0 || cc[i].fi != cc[i - 1].fi){
      set<int> bf;
      ll cur = 0;
      for(auto x : ids){
        for(auto y : T[x]){
          if(!act[y]) continue;
          nx=fin(y);
          if(!bf.count(nx)){
            cur -= f(sz[nx]);
            bf.insert(nx);
          }
        }
      }
      bf.clear();
      for(auto x : ids) act[x]=true;
      for(auto x : ids){
        for(auto y : T[x]){
          if(act[y])unite(x, y);
        }
      }
      for(auto x : ids){
        nx=fin(x);
        if(!bf.count(nx)){
          cur += f(sz[nx]);
          bf.insert(nx);
        }
      }
      sum -= cur * 1ll * cc[i].fi;
      ids.clear();
    }
  }
  cout << sum << "\n";
  return 0;
}