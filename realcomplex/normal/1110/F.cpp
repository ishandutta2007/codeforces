#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;
const ll inf = (ll)1e18;


vector<pii> A[N];
ll dis[N];

// segment tree is my hero

struct Node{
  ll value;
  ll lazy;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
  T[node].value += T[node].lazy;
  if(cl != cr){
    T[node * 2].lazy += T[node].lazy;
    T[node * 2 + 1].lazy += T[node].lazy;
  }
  T[node].lazy = 0;
}

void update(int node, int cl, int cr, int tl, int tr, ll v){
  push(node, cl, cr);
  if(cr < tl) return;
  if(cl > tr) return;
  if(cl >= tl && cr <= tr){
    T[node].lazy=v;
    push(node,cl,cr);
    return;
  }
  int mid = (cl + cr) / 2;
  update(node * 2, cl, mid, tl, tr, v);
  update(node * 2 + 1, mid + 1, cr, tl, tr, v);
  T[node].value = min(T[node * 2].value, T[node * 2 + 1].value);
}

ll ask(int node, int cl, int cr, int tl, int tr){
  push(node, cl, cr);
  if(cr < tl) return inf;
  if(cl > tr) return inf;
  if(cl >= tl && cr <= tr)
    return T[node].value;
  int mid = (cl + cr) / 2;
  return min(ask(node * 2, cl, mid, tl, tr), ask(node * 2 + 1, mid + 1, cr, tl, tr));
}

int tin[N];
int tout[N];
int tt;

void dfs(int u){
  ++tt;
  tin[u]=tt;
  for(auto x : A[u]){
    dis[x.fi] = dis[u] + x.se;
    dfs(x.fi);
  }
  tout[u]=tt;
  
}

struct Query{ 
  int lef;
  int rig;
  int idx;
};

vector<Query> Q[N];

ll sol[N];

int n;
void dfs1(int u){
  for(auto x : Q[u]){
    sol[x.idx] = ask(1,1,n,x.lef,x.rig);
  }
  for(auto p : A[u]){
    update(1,1,n,1,n,p.se);
    update(1,1,n,tin[p.fi],tout[p.fi],-2*p.se);
    dfs1(p.fi);
    update(1,1,n,1,n,-p.se);
    update(1,1,n,tin[p.fi],tout[p.fi],+2*p.se);
  }
}

int main(){
  fastIO;
  int q;
  cin >> n >> q;
  int par;
  ll w;
  for(int i = 2 ; i <= n; i ++ ){
    cin >> par >> w;
    A[par].push_back(mp(i,w));
  }
  for(int i = 1; i <= n; i ++ ){
    sort(A[i].begin(), A[i].end());
  }
  dis[1]=0;
  dfs(1);
  for(int i = 1; i <= n; i ++ )
    if(A[i].size() == 0) update(1, 1, n, i, i, dis[i]);
    else update(1, 1, n, i, i, inf);
  int u,l,r;
  for(int i = 0 ; i < q; i ++ ){
    cin >> u >> l >> r;
    Q[u].push_back({l,r,i});
  }
  dfs1(1);
  for(int i = 0 ; i < q; i ++ )
    cout << sol[i] << "\n";
  return 0;
}