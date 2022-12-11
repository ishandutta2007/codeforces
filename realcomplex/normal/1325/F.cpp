#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

vector<int> T[N];
int sq;

int par[N];
int dep[N];
int deg[N];

void dfs(int u, int pp, int d){
  par[u] = pp;
  dep[u] = d;
  for(auto x : T[u]){
    if(dep[x] == -1){
      deg[u] ++ ;
      deg[x] ++ ;
      dfs(x, u, d + 1);
    }
  }
}

bool ban[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  while(sq * sq < n) sq ++ ;
  int u, v;
  for(int i = 1; i <= n; i ++ )dep[i] = -1;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(1,-1,0);
  int low;
  int cl;
  for(int i = 1; i <= n; i ++ ){
    low = i;
    for(auto x : T[i]){
      if(dep[x] < dep[low]){
        low = x;
      }
    }
    if(low == i || low == par[i]) continue;
    if(dep[i] - dep[low] + 1 >= sq){
      cout << 2 << "\n";
      cout << dep[i] - dep[low] + 1 << "\n";
      cl = i;
      while(1){
        cout << cl << " ";
        if(cl == low) break;
        cl = par[cl];
      }
      return 0;
    }
  }
  vector<pii> ind;
  for(int i = 1; i <= n; i ++ ){
    ind.push_back(mp(dep[i], i));
  }
  sort(ind.begin(), ind.end());
  reverse(ind.begin(),ind.end());
  vector<int> res;
  for(int i = 0 ; i < n; i ++ ){
    if(!ban[ind[i].se]){
      ban[ind[i].se] = true;
      res.push_back(ind[i].se);
      for(auto x : T[ind[i].se]){
        ban[x] = true;
      }
    }
  }
  cout << 1 << "\n";
  while((int)res.size() > sq) res.pop_back();
  for(auto p : res) cout << p << " ";
  return 0;
}