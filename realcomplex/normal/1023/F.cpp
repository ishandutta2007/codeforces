#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;
vector<pii> T[N];
int par[N];

int fin(int x){
  if(par[x]==x)
    return x;
  return par[x]=fin(par[x]);
}

bool unite(int a, int b){
  a=fin(a);
  b=fin(b);
  if(a==b)
    return false;
  par[a]=b;
  return true;
}

int pp[N];
int dep[N];
int shit[N];

void dfs(int u, int pi){
  pp[u] = pi;
  for(auto x : T[u]){
    if(x.fi == pi) continue;
    dep[x.fi]=dep[u]+1;
    shit[x.fi] = x.se;
    dfs(x.fi, u);
  }
}

int main(){
  fastIO;
  int n, k, m;
  cin >> n >> k >> m;
  for(int i = 1; i <= n; i++)
    par[i]=i;
  int u, v;
  for(int i = 1; i <= k ; i ++ ){
    cin >> u >> v;
    unite(u, v);
    T[u].push_back(mp(v,1));
    T[v].push_back(mp(u,1));
  }
  int a[m], b[m], w[m];
  for(int i = 0 ; i < m ; i ++ ){
    cin >> a[i] >> b[i] >> w[i];
    if(unite(a[i],b[i])){
      T[a[i]].push_back(mp(b[i], 0));
      T[b[i]].push_back(mp(a[i], 0));
    }
  }
  dfs(1,1);
  for(int i = 1; i <= n; i++)
    par[i]=i;
  ll ret = 0;
  for(int i = 0 ;i  < m ; i ++ ){
    u=a[i],v=b[i];
    while(1){ // dsu is my hero
      u=fin(u);
      v=fin(v);
      if(u == v) break;
      if(dep[u] < dep[v]) swap(u, v);
      if(shit[u])
        ret += w[i];
      shit[u]=0;
      unite(u,pp[u]);
    } 
  }
  for(int i = 1 ;i <= n; i ++ )
    if(shit[i]){
      cout << -1 << "\n";
      return 0;
    }
  cout << ret << "\n";
  return 0;
}