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

const int N = (int)1e5 + 9;
const int BIT = 18;

vector<int> G[N];
int anc[N][BIT];
int subtree[N];
int euler_open[N];
int euler_close[N];
int tt = 1;
int n;
bool vis[N];
int dd[N];

void dfs(int cur, int par, int dep){
  vis[cur] = true;
  subtree[cur] = 1;
  anc[cur][0] = par;
  euler_open[cur] = tt;
  tt ++ ;
  dd[cur] = dep;
  for(int i = 1;i < BIT;i ++ )
    anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
  for(int nex : G[cur]){
    if(!vis[nex]){
      dfs(nex, cur, dep + 1);
      subtree[cur] += subtree[nex];
    }
  }
  euler_close[cur] = tt;
  tt ++;
}

bool is_ancestor(int a,int b){
  return euler_open[a] <= euler_open[b] and euler_close[b] <= euler_close[a];
}

int lca(int A, int B){
  if(is_ancestor(A, B))
    return A;
  if(is_ancestor(B, A))
    return B;
  for(int i = BIT - 1; i >= 0;i -- )
    if(!is_ancestor(anc[A][i], B))
      A = anc[A][i];
  return anc[A][0];
}

int Query(int A, int B){
  if(A == B)
    return n;
  int C = lca(A, B);
  int t1 = dd[A] - dd[C];
  int t2 = dd[B] - dd[C];
  if(t1%2!=t2%2)
    return 0;
  if(t1 == t2){
    int V1 = A;
    for(int i = BIT-1;i >= 0;i -- )
      if(!is_ancestor(anc[V1][i], B))
        V1 = anc[V1][i];
    int V2 = B;
    for(int i = BIT-1;i >= 0;i -- )
      if(!is_ancestor(anc[V2][i], A)) 
        V2 = anc[V2][i];
    return n - subtree[V1] - subtree[V2];
  }
  if(t1 < t2)
    swap(A, B);
  int go = (t1 + t2) / 2;
  go--;
  for(int i = BIT-1;i >= 0;i -- ){
    if(go & (1 << i)){
      A = anc[A][i];
    }
  }
  return subtree[anc[A][0]]-subtree[A];
}

int main(){
  fastIO;
  cin >> n;
  int u,v;
  for(int i = 1;i < n; i ++ ){
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1, 0);
  int q;
  cin >> q;
  int n1, n2;
  for(int i = 0;i < q;i ++ ){
    cin >> n1 >> n2;
    cout << Query(n1, n2) << "\n";
  }
  return 0;
}