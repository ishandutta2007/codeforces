#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;
int self[N];
int deg[N];
vector<int> T[N];
bool has[N];
bool shd[N];

void dfs(int u){
  has[u]=true;
  for(auto x : T[u]){
    if(!has[x])
      dfs(x);
  }
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int u, v;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> u >> v;
    shd[u]=true;
    shd[v]=true;
    if(u==v){
      self[u]++;
    }
    else{
      deg[u]++;
      deg[v]++;
      T[u].push_back(v);
      T[v].push_back(u);
    }
  }
  for(int i = 1; i <= n; i ++ )
    if(shd[i]){
      dfs(i);
      break;
    }
  for(int i = 1; i <= n; i ++ ){
    if(shd[i] == true && has[i] == false){
      cout << "0\n";
      return 0;
    }
  }
  ll res = 0;
  ll sf = 0;
  for(int i = 1; i <= n; i ++ ){
    sf += self[i];
    res += deg[i] * 1ll * (deg[i] - 1) / 2ll;
  }
  res += sf * 1ll * (sf - 1) / 2ll;
  res += sf * 1ll * (m - sf);
  cout << res << "\n";
  return 0;
}