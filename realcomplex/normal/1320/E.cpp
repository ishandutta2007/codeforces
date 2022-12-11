#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)2e5 + 10;
const int LOG = 19;

vector<int> T[N];
vector<pii> G[N];

int tin[N];
int tout[N];
int par[LOG][N];
int dis[N];
int ti;

void dfs(int u, int pr){
  par[0][u]=pr;
  for(int i = 1; i < LOG; i ++ ){
    par[i][u]=par[i-1][par[i-1][u]];
  }
  tin[u] = ++ti;
  for(auto x : T[u]){
    if(x == pr) continue;
    dis[x] = dis[u] + 1;
    dfs(x, u);
  }
  tout[u] = ti;
}

bool is_anc(int a, int b){
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}


int lca(int a, int b){
  if(is_anc(a,b))return a;
  if(is_anc(b,a))return b;
  for(int i = LOG - 1; i >= 0 ; i -- ){
    if(!is_anc(par[i][a],b))a=par[i][a];
  }
  return par[0][a];
}

vector<pii> vv;
vector<int> imp;
vector<pii> nod;

struct ST{
  int node;
  int rt;
  int dis;
  bool operator< (const ST &Q) const {
    if((dis+vv[rt].se-1)/vv[rt].se == (Q.dis+vv[Q.rt].se-1)/vv[Q.rt].se){
      return rt > Q.rt;
    }
    return (dis+vv[rt].se-1)/vv[rt].se > (Q.dis+vv[Q.rt].se-1)/vv[Q.rt].se;
  }
};

ST F[N];

void solve(){
  vv.clear();
  imp.clear();
  nod.clear();
  int k, m;
  cin >> k >> m;
  int a, b;
  for(int i = 0 ; i < k ; i ++ ){
    cin >> a >> b;
    vv.push_back(mp(a, b));
    nod.push_back(mp(tin[a], a));
  }
  for(int i = 0 ; i < m ; i ++ ){
    cin >> a;
    imp.push_back(a);
    nod.push_back(mp(tin[a], a));
  }
  int len;
  sort(nod.begin(), nod.end());
  nod.resize(unique(nod.begin(), nod.end()) - nod.begin());
  int l = nod.size();
  int v;
  for(int i = 0 ; i + 1 < l ; i ++ ){
    v = lca(nod[i].se, nod[i + 1].se);
    nod.push_back(mp(tin[v], v));
  }
  sort(nod.begin(), nod.end());
  nod.resize(unique(nod.begin(), nod.end()) - nod.begin());
  vector<int> cur;
  for(auto p : nod){
    while(!cur.empty() && !is_anc(cur.back(), p.se)) cur.pop_back();
    if(!cur.empty()){
      len = dis[p.se] - dis[cur.back()];
      G[p.se].push_back(mp(cur.back(), len));
      G[cur.back()].push_back(mp(p.se, len));
    }
    cur.push_back(p.se);
  }
  priority_queue<ST> pq;
  for(auto x : nod){
    F[x.se] = {x.se, -1, -1};
  }
  for(int i = 0; i < vv.size(); i ++ ){
    F[vv[i].fi] = {vv[i].fi, i, 0};
    pq.push({vv[i].fi, i, 0});
  }
  ST ci;
  ST ni;
  int idx;
  while(!pq.empty()){
    ci = pq.top();
    idx = ci.node;
    pq.pop();
    if(ci.rt != F[idx].rt || ci.dis != F[idx].dis)
      continue;
    for(auto p : G[idx]){
      ni = {p.fi, ci.rt, ci.dis + p.se};
      if(F[p.fi].rt == -1){
        F[p.fi] = ni;
        pq.push(F[p.fi]);
      }
      else if(F[p.fi] < ni){
        F[p.fi] = ni;
        pq.push(F[p.fi]);
      }
    }
  }
  for(auto v : imp)
    cout << F[v].rt + 1 << " ";
  cout << "\n";
  for(auto x : nod){
    G[x.se].clear();
  }
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int u, v;
  for(int i = 1 ; i < n ; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(1,1);
  int q;
  cin >> q;
  for(int t = 0; t < q; t ++ ) solve();
  return 0;
}