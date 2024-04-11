#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<pii> T[N];

int n, k;

int f[N];

void dfs(int u, int par){
  for(auto x : T[u]){
    if(x.fi == par) continue;
    dfs(x.fi, u);
    f[u] = max(f[u], f[x.fi] + x.se);
  }
}

int len = (int)2e9;
int cen = 1;

void dfs1(int u, int par, int fd){
  pii p1=mp(0,-1), p2=mp(0,-1);
  for(auto x : T[u]){
    if(x.fi == par) continue;
    if(mp(f[x.fi] + x.se, x.fi) > p1){
      p2 = p1;
      p1 = mp(f[x.fi] + x.se, x.fi);
    }
    else if(mp(f[x.fi] + x.se, x.fi) > p2){
      p2 = mp(f[x.fi] + x.se, x.fi);
    }
  }
  for(auto x : T[u]){
    if(x.fi == par) continue;
    if(p1.se != x.fi){
      dfs1(x.fi, u, max(fd, p1.fi) + x.se);
    }
    else{
      dfs1(x.fi, u, max(fd, p2.fi) + x.se);
    }
  }
  if(max({p1.fi, p2.fi, fd}) < len){
    len = max({p1.fi, p2.fi, fd});
    cen = u;
  }
}

int dp[N];
void dfs2(int u, int par){
  for(auto x : T[u]){
    if(x.fi == par) continue;
    dfs2(x.fi, u);
    dp[u] = max(dp[u], dp[x.fi] + x.se);
  }
}

int u[N], v[N], d[N];
int deg[N];

int main(){
  fastIO;
  cin >> n >> k;
  for(int i = 1; i < n; i ++ ){
    cin >> u[i] >> v[i] >> d[i];
    T[u[i]].push_back(mp(v[i], d[i]));
    T[v[i]].push_back(mp(u[i], d[i]));
  }
  dfs(1,-1);
  dfs1(1,-1,0);
  dfs2(cen, -1);
  int l = 0, r = (int)2e9;
  int md;
  int tot;
  while(l < r){
    md = (l + r) / 2;
    for(int i = 1; i <= n; i ++ )
      deg[i] = 0;
    tot = 0;
    for(int i = 1; i < n; i ++ ){
      if(min(dp[u[i]], dp[v[i]]) + d[i] > md){
        deg[u[i]] ++ ;
        deg[v[i]] ++ ;
        tot ++ ;
      }
    }
    for(int i = 1; i <= n; i ++ ){
      if(deg[i] >= 3)
        tot = k;
    }
    if(tot < k)
      r = md;
    else
      l = md + 1;
  }
  cout << r << "\n";
  return 0;
}