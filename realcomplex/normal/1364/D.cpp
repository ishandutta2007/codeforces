#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
vector<int> T[N];
bool vis[N];
int dep[N];
int pp[N];
int u[N], v[N];

vector<int> bit[2];

void dfs(int u, int par, int b){ 
  pp[u] = par;
  vis[u] = true;
  bit[b].push_back(u);
  for(auto x : T[u]){
    if(x == par || vis[x]) continue;
    dep[x] = dep[u] + 1;
    dfs(x, u, b ^ 1);
  }
}

int main(){
  fastIO;
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> u[i] >> v[i];
    T[u[i]].push_back(v[i]);
    T[v[i]].push_back(u[i]);
  }
  dfs(1, 1, 0);
  int id = -1, low = (int)1e9;
  for(int i = 0 ;i  < m ; i ++ ){
    if(dep[u[i]] > dep[v[i]]) swap(u[i], v[i]);
    if(dep[v[i]] == dep[u[i]] + 1) continue; // parent
    if(dep[v[i]] - dep[u[i]] + 1 <= k){
      int nd = v[i];
      vector<int> sol;
      while(1){
        sol.push_back(nd);
        if(nd == u[i]) break;
        nd = pp[nd];
      }
      cout << 2 << "\n";
      cout << sol.size() << "\n";
      for(auto x : sol)
        cout << x << " ";
      return 0;
    }
    else{
      if(dep[v[i]] - dep[u[i]] + 1 < low){
        low = dep[v[i]] - dep[u[i]] + 1;
        id = v[i];
      }
    }
  }
  if(id != -1){
    vector<int> sol;
    int cur = 1;
    while(sol.size() < (k + 1) / 2){
      if(cur) sol.push_back(id);
      id = pp[id];
      cur ^= 1;
    }
    cout << 1 << "\n";
    for(auto x : sol)
      cout << x << " ";
    cout << "\n";
    return 0;
  }
  else{
    if(bit[0].size() < bit[1].size()) swap(bit[0], bit[1]);
    while(bit[0].size() > (k + 1) / 2) bit[0].pop_back();
    cout << 1 << "\n";
    for(auto x : bit[0])
      cout << x << " ";
    cout << "\n";
  }
  return 0;
}