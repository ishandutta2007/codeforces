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

const int N = (int)3e5 + 9;
vector<int>T[N];
int subtree[N];
bool vis[N];

void dfs(int u){
  subtree[u] = 1;
  vis[u] = true;
  for(auto x : T[u])
    if(!vis[x]){
      dfs(x);
      subtree[u] += subtree[x];
    }
}

int main(){
  fastIO;
  int n,x,y;
  cin >> n >> x >> y;
  int u,v;
  for(int i = 0;i < n;i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(x);
  ll bad = subtree[y];
  memset(vis, false, sizeof vis);
  dfs(y);
  bad *= 1LL * subtree[x];
  ll road = n;
  road *= (ll)n-1;
  road -= bad;
  cout << road << "\n";
  return 0;
}