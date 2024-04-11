#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()
#define ones(a) __builtin_popcount(a)

const int N = (int)1e5 + 9;
const int BLOCK = 350;
const int BIT = 18;

vector<int>T[N];
int anc[N][BIT];
int dd[N];
int upd[N]; 

int euler_open[N];
int euler_close[N];
int tt = 1;
bool vis[N];

void dfs(int u, int dep, int par){
  anc[u][0] = par;
  dd[u] = dep;
  upd[u] = dep;
  vis[u] = true;
  euler_open[u] = tt;
  tt ++ ;
  for(int i = 1;i < BIT; i ++ ){
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
  }
  for(int X : T[u]){
    if(!vis[X]){
      dfs(X, dep + 1, u);
    }
  }
  euler_close[u] = tt;
  tt ++ ;
}

bool is_ancestor(int a, int b){
  return euler_open[a] <= euler_open[b] and euler_close[a] >= euler_close[b];
}

int lca(int a, int b){
  if(is_ancestor(a, b))
    return a;
  if(is_ancestor(b, a))
    return b;
  for(int i = BIT - 1;i >= 0;i -- ){
    if(!is_ancestor(anc[a][i], b)){
      a = anc[a][i];
    }
  }
  return anc[a][0];
}

int dist(int a,int b){
  int c = lca(a, b);
  return (dd[a] - dd[c]) + (dd[b] - dd[c]);
}

int main(){
  fastIO;
  int n,q;
  cin >> n >> q;
  int u,v;
  for(int i = 1;i < n;i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(1, 0, 1);
  int TT;
  int nd;
  vector<int> red;
  int ans;
  for(int i = 0;i < q;i ++ ){
    cin >> TT >> nd;
    if(TT == 1){
      red.push_back(nd);
    }
    else{
      ans = upd[nd];
      for(int X : red)
        ans = min(ans, dist(nd, X));
      cout << ans << "\n";
    }
    if(i % BLOCK == 0){
      queue<int>pp;
      for(int X : red){
        upd[X] = 0;
        pp.push(X);
      }
      red.clear();
      while(!pp.empty()){
        nd = pp.front();
        pp.pop();
        for(int X : T[nd]){
          if(upd[nd] + 1 < upd[X]){
            upd[X] = upd[nd] + 1;
            pp.push(X);
          } 
        }
      }
    }
  }
  return 0;
}