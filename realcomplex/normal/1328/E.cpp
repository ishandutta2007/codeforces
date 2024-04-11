#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<int> T[N];
int par[N];
int tin[N];
int tout[N];
int tt;

void dfs(int u){
  tin[u] = ++tt;
  for(auto x : T[u]){
    if(par[x] == 0){
      par[x]=u;
      dfs(x);
    }
  }
  tout[u] = tt;
}

bool is(int u, int v){
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int u, v;
  for(int i = 1; i < n; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  par[1]=1;
  dfs(1);
  vector<pii> vv;
  int k;
  int id;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> k;
    vv.resize(k);
    for(int j = 0 ; j < k ; j ++ ){
      cin >> vv[j].se;
      vv[j].se = par[vv[j].se];
      vv[j].fi = tin[vv[j].se];
    }
    sort(vv.begin(), vv.end());
    bool yes = true;
    for(int i = 0 ; i + 1 < k ; i ++ ){
      if(!is(vv[i].se, vv[i+1].se))
        yes = false;
    }
    if(yes)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}