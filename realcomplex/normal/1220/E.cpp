#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<pii> T[N];
ll vl[N];
bool bri[N];
int tin[N];
int low[N];
int tt = 0;

void dfs(int u, int par){
  tin[u] = tt++;
  low[u] = tin[u];
  for(auto x : T[u]){
    if(x.fi == par)continue;
    if(tin[x.fi] == 0){
      dfs(x.fi, u);
      low[u] = min(low[u], low[x.fi]);
    }
    else{
      low[u] = min(low[u], tin[x.fi]);
    }
    if(tin[u] < low[x.fi]){
      bri[x.se] = true;
    }
  }
}

int idx[N];
int sz[N];
int cnt = 1;
ll sum[N];
vector<int> G[N];

void dfs1(int u){
  idx[u] = cnt;
  sz[cnt] ++ ;
  sum[cnt] += vl[u];
  for(auto x : T[u]){
    if(bri[x.se]) continue;
    if(idx[x.fi]) continue;
    dfs1(x.fi);
  }
}

bool isg[N];
ll res = 0;
ll f[N];
void dfs2(int u, int par){
  for(auto x : G[u]){
    if(x != par){
      dfs2(x, u);
      isg[u] |= isg[x];
      f[u] = max(f[u], f[x]);
    }
  }
  f[u] += sum[u];
  res += isg[u] * sum[u];
}


int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++ )
    cin >> vl[i];
  int u, v;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> u >> v;
    T[u].push_back(mp(v,i));
    T[v].push_back(mp(u,i));
  }
  int root;
  cin >> root;
  dfs(root, -1);
  for(int i = 1; i <= n; i ++ ){
    if(idx[i] == 0){
      dfs1(i);
      ++cnt;
    }
  }
  for(int i = 1; i <= n; i ++ )
    for(auto x : T[i])
      if(bri[x.se])
        G[idx[i]].push_back(idx[x.fi]);
  for(int i = 1; i <= cnt; i ++ ){
    isg[i] = (sz[i] > 1);
  }
  dfs2(idx[root], -1);
  ll bes = 0;
  for(int i = 1; i <= n; i ++ )
    if(!isg[i]) bes = max(bes, f[i]);
  cout << res + bes;
  return 0;
}