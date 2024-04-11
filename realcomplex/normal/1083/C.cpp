#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
const int LOG = 18;
vector<int> T[N];
int p[N];
int par[LOG][N];

int tin[N];
int tout[N];
int dist[N];
int tim = 0;

void dfs(int u, int pr){
  tin[u] = ++tim;
  par[0][u] = pr;
  for(int i = 1; i < LOG; i ++ ){
    par[i][u] = par[i-1][par[i-1][u]];
  }
  for(auto x : T[u]){
    dist[x] = dist[u] + 1;
    dfs(x, u);
  }
  tout[u] = tim;
}

bool is_anc(int a, int b){ // is a an ancestor of b
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b){  
  if(is_anc(a,b)) return a;
  if(is_anc(b,a)) return b;
  for(int i = LOG - 1; i >= 0; i -- ){
    if(!is_anc(par[i][a], b))
      a = par[i][a];
  }
  return par[0][a];
}

pii unite(pii a, pii b){
  if(a.fi == -2) return b;
  if(b.fi == -2) return a;
  if(a.fi == -1 || a.se == -1 || b.fi == -1 || b.se == -1)
    return mp(-1,-1);
  vector<int> lis = {a.fi, a.se, b.fi, b.se};
  int up = lis[0];
  for(int i = 1; i < 4; i ++ ){
    if(dist[lis[i]] < dist[up]){
      up = lis[i];
    }
  }
  for(int i = 0 ; i < 4; i ++ ){
    for(int j = 0 ; j < 4; j ++ ){
      if(lis[i] == -1 || lis[j] == -1 || i == j) continue;
      if(is_anc(lis[i], lis[j])){
        lis[i] = -1;
        break;
      }
    }
  }
  int c = 0;
  for(int i = 0 ; i < 4; i ++ ){
    if(lis[i] != -1){
      lis[c ++ ] = lis[i];
    }
  }
  if(c == 1)
    return mp(up, lis[0]);
  else if(c == 2 && dist[lca(lis[0], lis[1])] <= dist[up])
    return mp(lis[0], lis[1]);
  else
    return mp(-1,-1);
}
 
pii Tree[N * 4 + 512];
 
void setid(int node, int cl, int cr, int p, pii vl){
  if(cl==cr){
    Tree[node] = vl;
    return ;
  }
  int mid=(cl+cr)/2;
  if(mid >= p)setid(node * 2, cl, mid, p, vl);
  else setid(node * 2 + 1, mid + 1, cr, p, vl);
  Tree[node] = unite(Tree[node * 2], Tree[node * 2 + 1]);
}

int query(int node, int cl, int cr, pii cur){
  if(unite(cur, Tree[node]) != mp(-1, -1))
    return cr;
  if(cl==cr)
    return cl - 1;
  pii un = unite(cur, Tree[node * 2]);
  int mid = (cl + cr) / 2;
  if(un == mp(-1, -1)){
    return query(node * 2, cl, mid, cur);
  }
  else{
    return query(node * 2 + 1, mid + 1, cr, un);
  }
}

void print(int node, int cl, int cr){
  cout << cl << " " << cr << "| " << Tree[node].fi << " " << Tree[node].se << "\n";
  if(cl == cr){
    return;
  }
  int mid = (cl + cr) / 2;
  print(node * 2, cl, mid);
  print(node * 2 + 1, mid + 1, cr);
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int a;
  for(int i = 1 ; i <= n ; i ++ ){
    cin >> p[i];
  }
  for(int i = 2; i <= n; i ++ ){
    cin >> a;
    T[a].push_back(i);
  }
  dfs(1, 1);
  for(int i = 0 ; i < n * 4 + 512; i ++ ){
    Tree[i] = mp(-2, -2);
  }
  for(int i = 1; i <= n; i ++ ){
    setid(1, 0, n - 1, p[i], mp(i, i));
  }
  int q;
  cin >> q;
  int typ;
  int pi, pj;
  for(int i = 0 ; i < q; i ++ ){
    cin >> typ;
    if(typ == 1){
      cin >> pi >> pj;
      setid(1, 0, n - 1, p[pj], mp(pi, pi));
      setid(1, 0, n - 1, p[pi], mp(pj, pj));
      swap(p[pi], p[pj]);
    }
    else{
      cout << query(1, 0, n - 1, mp(-2, -2)) + 1 << "\n"; 
    }
  }
  return 0;
}