#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)1e6 + 91;
const int LOG = 21;

vector<int> T[N];

bool rem[N];
int up[N][LOG];

void dfs(int u, int par){
  up[u][0] = par;
  for(int i = 1;i < LOG;i ++ ){
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for(auto x : T[u]){
    if(x == par)  
      continue;
    dfs(x, u);
  }
}

int stay;
 
void try_put(int x){
  if(rem[x] == true)
    return;
  int node = x;
  int tot = 0;
  for(int j = LOG - 1; j >= 0; j -- ){
    if(!rem[up[node][j]]){
      tot += 1 << j;
      node = up[node][j];
    }
  }
  ++ tot;
  if(tot > stay)
    return;
  stay -= tot;
  rem[x] = true;
  for(int j = LOG - 1; j >= 0; j -- ){
    if(!rem[up[x][j]]){
      for(int l = 0; l < (1 << j); l ++ ){ // in total O(N) because only N nodes
        x = up[x][0];
        rem[x] = true;
      }
    }
  }
}

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  int a, b;
  for(int i = 0; i < n-1;i ++ ){
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  int root = n;
  rem[root] = true;
  dfs(root, root);
  stay = n - k;
  stay -- ;
  for(int i = n;i >= 1; i -- ){
    try_put(i);
  }
  for(int i = 1;i <= n;i ++ ){
    if(rem[i] == false)
      cout << i << " ";
  }
  cout << "\n";
  return 0;
}