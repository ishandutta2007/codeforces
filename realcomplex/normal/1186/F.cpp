#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e6;
vector<pii> T[N];
bool used[N];
bool vis[N];
int u[N], v[N];
int dir[N];

vector<pii> E[N];
bool incl[N];
int lim[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> u[i] >> v[i];
    T[u[i]].push_back(mp(v[i], i));
    T[v[i]].push_back(mp(u[i], i));
  }
  vector<int> pp;
  int q = m;
  for(int i = 1; i <= n; i ++ ){
    if((int)T[i].size() & 1){
      pp.push_back(i);
    }
  }
  for(int i = 0 ; i < (int)pp.size(); i += 2){
    u[q] = pp[i];
    v[q] = pp[i + 1];
    T[u[q]].push_back(mp(v[q], q));
    T[v[q]].push_back(mp(u[q], q));
    q ++ ;
  }
  vector<pii> ty;
  int node;
  int idx;
  for(int i = 1; i <= n; i ++ ){
    if(vis[i]) continue;
    ty.push_back(mp(i, -1));
    while(!ty.empty()){
      node = ty.back().fi;
      idx = ty.back().se;
      vis[node] = true;
      while(!T[node].empty() && used[T[node].back().se])
        T[node].pop_back();  
      if(!T[node].empty()){
        used[T[node].back().se] = true;
        ty.push_back(T[node].back());
      }
      else{
        dir[idx] = node;
        ty.pop_back();
      }
    }
  }
  for(int i = 0 ; i < m ; i ++ ){
    E[u[i]].push_back(mp(v[i], i));
    E[v[i]].push_back(mp(u[i], i));
  }
  vector<pii> ans;
  for(int i = 1; i <= n; i ++ ){
    lim[i] = ((int)E[i].size() + 1) / 2;
  }
  for(int i = 1; i <= n; i ++ ){
    vector<int> pp;
    for(auto x : E[i]){
      if(incl[x.se]) continue;
      if(dir[x.se] != i){
        pp.push_back(x.se);
      }
    }
    for(auto x : pp){
      if(lim[u[x]] > 0 && lim[v[x]] > 0){
        lim[u[x]] -- ;
        lim[v[x]] -- ;
        incl[x] = true;
        ans.push_back(mp(u[x], v[x]));
      }
    }
  }
  for(int i = 0 ; i < m ; i ++ ){
    if(incl[i]) continue;
    if(lim[u[i]] > 0 || lim[v[i]] > 0){
      lim[u[i]] -- ;
      lim[v[i]] -- ;
      incl[i] = true;
      ans.push_back(mp(u[i], v[i]));
    }
  }
  cout << ans.size() << "\n";
  for(auto x : ans)
    cout << x.fi << " " << x.se << "\n";
  return 0;
}