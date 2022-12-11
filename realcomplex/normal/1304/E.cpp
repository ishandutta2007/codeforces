#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int LOG = 18;
int par[LOG][N];
vector<int> T[N];
int tin[N];
int tout[N];
int tt;
int dis[N];


void dfs(int u, int pp){
  par[0][u] = pp;
  for(int i = 1; i < LOG; i ++ ){
    par[i][u]=par[i-1][par[i-1][u]];
  }
  tin[u] = ++tt;
  for(auto x : T[u]){
    if(x == pp) continue;
    dis[x] = dis[u] + 1;
    dfs(x,u);
  }
  tout[u]=tt;
}

bool is_anc(int a, int b){
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b){
  if(is_anc(a,b)) return a;
  if(is_anc(b,a)) return b;
  for(int i = LOG - 1; i >= 0 ; i -- )
    if(!is_anc(par[i][a], b))
      a = par[i][a];
  return par[0][a];
}

int dist(int a, int b){ 
  return dis[a] + dis[b] - 2 * dis[lca(a, b)];
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int u, v;
  for(int i =1 ; i < n ; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(1,1);
  int q;
  cin >> q;
  int x, y, a, b, k;
  int p1,p2,p3;
  for(int i = 0 ; i < q; i ++ ){
    cin >> x >> y >> a >> b >> k;
    p1 = dist(a,b);
    p2 = dist(a,x) + dist(y,b) + 1;
    p3 = dist(a,y) + dist(x,b) + 1;
    if((k >= p1 && (k-p1)%2==0) || (k >= p2 && (k-p2)%2==0) || (k >= p3 && (k-p3)%2==0)){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
  return 0;
}