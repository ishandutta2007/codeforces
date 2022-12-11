#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int Q = (int)3e5 + 9;
vector<pii> T[N];
ll di[N];

struct Edge{  
  int a;
  int b;
  ll ww;
  bool operator< (const Edge &T){
    return ww < T.ww;
  }
};

set<int> qq[N];
int par[N];
ll ret[Q];

int fin(int x){
  if(par[x]==x)
    return x;
  return par[x]=fin(par[x]);
}


void unite(int a, int b, ll ww){
  a=fin(a);
  b=fin(b);
  if(a==b) return;
  if(qq[a].size() > qq[b].size()) swap(a,b);
  for(auto x : qq[a]){
    if(qq[b].count(x)){
      ret[x]=ww;
    }
    qq[b].insert(x);
  }
  qq[a].clear();
  par[a]=b;
}

int main(){
  fastIO;
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  int u[m], v[m], w[m];
  for(int i = 0 ; i < m ; i ++ ){
    cin >> u[i] >> v[i] >> w[i];
    T[u[i]].push_back(mp(v[i],w[i]));
    T[v[i]].push_back(mp(u[i],w[i]));
  }
  for(int i = 1; i <= n; i ++ )di[i] = (ll)1e18;
  priority_queue<pii, vector<pii>, greater<pii>> ff;
  for(int i = 1; i <= k ; i ++ ){
    ff.push(mp(0, i));
    di[i]=0;
  }
  int node;
  ll dis;
  while(!ff.empty()){
    node = ff.top().se;
    dis = ff.top().fi;
    ff.pop();
    if(dis != di[node]){
      continue;
    }
    for(auto x : T[node]){
      
      if(di[x.fi] > dis + x.se){
        di[x.fi] = dis + x.se;
        ff.push(mp(di[x.fi], x.fi));
      }
    }
  }
  vector<Edge> ri;
  for(int i = 0 ; i < m ; i ++ ){
    ri.push_back({u[i], v[i], w[i] + di[u[i]] + di[v[i]]});
  }
  sort(ri.begin(), ri.end());
  for(int i = 1; i <= n; i ++ )
    par[i]=i;
  int iq, jq;
  for(int i = 0 ; i < q; i ++ ){
    cin >> iq >> jq;
    qq[iq].insert(i);
    qq[jq].insert(i);
  }
  for(int i = 0 ; i < m ; i ++ ){
    unite(ri[i].a, ri[i].b, ri[i].ww);
  }
  for(int i = 0 ; i < q; i ++ )
    cout << ret[i] << "\n";
  return 0;
}