#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 100;

struct Node{
  ll value;
  ll lazy;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
  T[node].value += (cr - cl + 1) * 1ll * T[node].lazy;
  if(cl != cr){
    T[node * 2].lazy += T[node].lazy;
    T[node * 2 + 1].lazy += T[node].lazy;
  }
  T[node].lazy = 0;
}

void upd(int node, int cl, int cr, int tl, int tr, ll v){
  push(node, cl, cr);
  if(cl > tr || cr < tl) return;
  if(cl >= tl && cr <= tr){
    T[node].lazy=v;
    push(node,cl,cr);
    return;
  }
  int mid = (cl + cr) / 2;
  upd(node * 2, cl, mid, tl, tr, v);
  upd(node * 2 + 1, mid + 1, cr, tl, tr, v);
  T[node].value = T[node * 2].value + T[node * 2 + 1].value;
}

ll qry(int node, int cl, int cr, int tl, int tr){
  push(node, cl, cr);
  if(cr < tl) 
    return 0ll;
  if(cl > tr)
    return 0ll;
  if(cl >= tl && cr <= tr)
    return T[node].value;
  int mid = (cl + cr) / 2;
  return qry(node * 2, cl, mid, tl, tr) + qry(node * 2 + 1, mid + 1, cr, tl, tr);
}

const int LOG = 18;

vector<int> E[N];

int tin[N];
int tout[N];
int dep[N];
int tt;

int pp[LOG][N];

void dfs(int u, int par){
  pp[0][u]=par;
  for(int i = 1; i < LOG; i ++ )
    pp[i][u]=pp[i-1][pp[i-1][u]];
  tin[u]=++tt;
  for(auto x : E[u]){
    if(x==par) continue;
    dep[x]=dep[u] + 1;
    dfs(x,u);
  }
  tout[u]=tt;
}

int a[N];

bool is_anc(int a, int b){
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int u, int v){
  if(is_anc(u,v)) return u;
  if(is_anc(v,u)) return v;
  for(int i = LOG - 1; i >= 0 ; i -- )
    if(!is_anc(pp[i][u], v))
      u=pp[i][u];
  return pp[0][u];
}

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
  }
  int u, v;
  for(int i = 1; i < n; i ++ ){
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(1, 1);
  for(int i = 1; i <= n; i ++ )
    upd(1, 1, n, tin[i], tin[i], a[i]);
  int ty, nd, x;
  int root = 1;
  int lc;
  int f1, f2;
  int k;
  for(int i = 1; i <= q; i ++ ){
    cin >> ty;
    if(ty == 1){
      cin >> nd;
      root = nd;
    }
    else if(ty == 2 ){
      cin >> u >> v >> x;
      lc = lca(u, v);
      if(lc == root){
        upd(1, 1, n, 1, n, x);
      }
      else if(is_anc(root,u) != is_anc(root, v)){
        upd(1, 1, n, 1, n, x);
      }
      else if(is_anc(lc, root)){
        f1 = lca(u, root);
        f2 = lca(v, root);
        if(dep[f1] > dep[lc]) lc = f1;
        if(dep[f2] > dep[lc]) lc = f2;
        k = root;
        for(int j = LOG - 1; j >= 0 ; j -- ){
          if(!is_anc(pp[j][k],lc)){
            k = pp[j][k];
          }
        }
        upd(1, 1, n, 1, n, x);
        upd(1, 1, n, tin[k], tout[k], -x);
      }
      else{
        upd(1, 1, n, tin[lc], tout[lc], x);
      }
    }
    else{
      cin >> nd;
      if(root == 1){
        cout << qry(1, 1, n, tin[nd], tout[nd]) << "\n";
      }
      else if(nd == root){
        cout << qry(1, 1, n, 1, n) << "\n";
      }
      else{
        if(!is_anc(nd, root)){
          cout << qry(1, 1, n, tin[nd], tout[nd]) << "\n";
        }
        else{
          k = root;
          for(int j = LOG - 1; j >= 0 ; j -- ){
            if(!is_anc(pp[j][k], nd)){
              k = pp[j][k];
            }
          }
          cout << qry(1, 1, n, 1, n) - qry(1, 1, n, tin[k], tout[k]) << "\n";
        }
      }
    }
  }
  return 0;
}