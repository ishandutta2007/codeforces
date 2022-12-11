#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5005;
vector<pii> T[N];

int par[N];
int idp[N];
int tin[N];
int tout[N];
int cost[N];
int tt;

void dfs(int u){
  tin[u] = ++tt;
  for(auto x : T[u]){
    if(x.fi == par[u]) continue;
    par[x.fi] = u;
    idp[x.fi] = x.se;
    dfs(x.fi);
  }
  tout[u] = tt;
}

bool is_anc(int a, int b){
  return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int main(){
  //fastIO;
  int n;
  cin >> n;
  int x,y;
  for(int i = 1; i < n ; i ++ ){
    cin >> x >> y;
    T[x].push_back(mp(y, i));
    T[y].push_back(mp(x, i));
  }
  dfs(1);
  int q;
  cin >> q;
  int u[q], v[q], z[q];
  for(int i = 0 ; i < q; i ++ ){
    cin >> u[i] >> v[i] >> z[i];
    x = u[i];
    y = v[i];
    while(!is_anc(x,y)){
      cost[idp[x]] = max(cost[idp[x]], z[i]);
      x = par[x];
    }
    while(!is_anc(y,x)){
      cost[idp[y]] = max(cost[idp[y]], z[i]);
      y = par[y];
    }
  }
  for(int i = 1; i < n; i ++ )
    if(cost[i] == 0) cost[i] = 69;
  int low;
  for(int i = 0 ; i < q; i ++ ){
    x = u[i];
    y = v[i];
    low = (int)1e6;
    while(!is_anc(x,y)){
      low = min(low, cost[idp[x]]);
      x=par[x];
    }
    while(!is_anc(y,x)){
      low = min(low, cost[idp[y]]);
      y=par[y];
    }
    if(low != z[i]){
      cout << -1 << "\n";
      return 0;
    }
  }
  for(int i = 1; i < n; i ++ )
    cout << cost[i] << " ";
  return 0;
}