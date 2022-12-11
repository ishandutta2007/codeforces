#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll N = (ll)5e5 + 9;
const ll M = (ll)1e6 + 19;

ll pi[N];
ll sz[N];
ll f[N];

vector<ll> T[M];
ll tin[M];
ll tout[M];
ll tree[M * 4 + 512];

ll tt;

ll lf[M];
ll n, q;
ll c;
bool shl;

void init(){
  c = n;
  shl = true;
  tt = 0;
  for(ll i = 0 ; i < N ; i ++ )
    pi[i] = i, sz[i] = 1, f[i] = i;
  for(ll i = 0 ; i < M ; i ++ ){
    T[i].clear();
    lf[i] = 0;
  }
  for(ll i = 0 ; i < M * 4 + 512; i ++ ){
    tree[i] = -1;
  }
}

ll fin(ll x){
  if(pi[x] == x) return x;
  return pi[x]=fin(pi[x]);
}

void unite(ll a, ll b){
  a=fin(a);
  b=fin(b);
  if(a==b) return;
  if(sz[a] > sz[b]) swap(a, b);
  ++ c;
  sz[b] += sz[a];
  if(shl){
    T[c].push_back(f[a]);
    T[c].push_back(f[b]);
  }
  pi[a] = b;
  f[b] = c;
}

void dfs(ll u){
  tin[u] = ++tt;
  for(auto x : T[u]){
    dfs(x);
    lf[u] += lf[x];
  }
  tout[u] = tt;
}

bool setv = true;

void push(ll node, ll cl, ll cr){
  if(cl == cr) return;
  if(setv){
    if(tree[node] == -1) return;
    tree[node * 2] = tree[node];
    tree[node * 2 + 1] = tree[node];
    tree[node] = -1;
  }
  else{
    tree[node * 2] += tree[node];
    tree[node * 2 + 1] += tree[node];
    tree[node] = 0;
  }
}

void update(ll node, ll cl, ll cr, ll tl, ll tr, ll vl){
  push(node, cl, cr);
  if(cr < tl) return;
  if(cl > tr) return;
  if(cl >= tl && cr <= tr){
    if(setv) tree[node] = vl;
    else tree[node] += vl;
    push(node, cl, cr);
    return;
  }
  ll mid = (cl + cr) / 2;
  update(node * 2, cl, mid, tl, tr, vl);
  update(node * 2 + 1, mid + 1, cr, tl, tr, vl);
}

ll ask(ll node, ll cl, ll cr, ll pos){
  push(node, cl, cr);
  if(cl==cr)
    return tree[node];
  ll mid = (cl + cr) / 2;
  if(mid >= pos)
    return ask(node * 2, cl, mid, pos);
  else
    return ask(node * 2 + 1, mid + 1, cr, pos);
}

struct Query{ 
  ll idx;
  ll node;
  ll sign;
};

vector<Query> qq[N];

vector<ll> out;


int main(){
  fastIO;
  cin >> n >> q;
  init();
  char typ[q];
  pii iq[q];
  for(ll i = 0 ; i < q; i ++ ){
    cin >> typ[i];
    iq[i] = mp(-1,-1);
    if(typ[i] == 'M') cin >> iq[i].fi >> iq[i].se;
    else if(typ[i] == 'U') cin >> iq[i].fi >> iq[i].se;
    else cin >> iq[i].fi;
  }
  for(ll i = 0 ;i < q; i ++ ){
    if(typ[i] == 'M'){
      unite(iq[i].fi, iq[i].se);
    }
  }
  for(ll i = 1; i <= n; i ++ )
    lf[i] = 1;
  for(ll i = 1; i <= n; i ++ ){
    if(fin(i) == i){
      dfs(f[i]);
    }
  }
  shl = false;
  c = n;
  ll ss;
  for(ll i = 0 ;i < N ; i ++ ){
    pi[i] = i;
    sz[i] = 1;
    f[i] = i;
  }
  ll ai;
  ll tim;
  for(ll i = 0 ; i < q; i ++ ){
    if(typ[i] == 'M'){
      unite(iq[i].fi, iq[i].se);
    }
    else if(typ[i] == 'Z'){
      ai = iq[i].fi;
      ai = f[fin(ai)];
      update(1, 1, tt, tin[ai], tout[ai], i);
    }
    else if(typ[i] == 'Q'){
      ss = out.size();
      qq[i].push_back({ss,iq[i].fi,+1});
      tim = ask(1, 1, tt, tin[iq[i].fi]);
      if(tim != -1) qq[tim].push_back({ss,iq[i].fi,-1});
      out.push_back(0);
    }
  }
  init();
  setv = false;
  for(ll i = 0 ; i < q; i ++ ){
    if(typ[i] == 'U'){
      unite(iq[i].fi, iq[i].se);
    }
  }
  for(ll i = 1; i <= n; i ++ )
    lf[i] = 1;
  for(ll i = 1; i <= n; i ++ ){
    if(fin(i) == i){
      dfs(f[i]);
    } 
  }
  shl = false;
  c = n;
  for(ll i = 0;i  < N ; i ++ ){
    pi[i] = i;
    sz[i] = 1;
    f[i] = i;
  }
  for(ll i = 0 ; i < M * 4 + 512; i ++ )
    tree[i] = 0;
  for(ll i = 0 ; i < q; i ++ ){
    if(typ[i] == 'U'){
      unite(iq[i].fi, iq[i].se);
    }
    else if(typ[i] == 'A'){
      ai = iq[i].fi;
      ai = f[fin(ai)];
      update(1, 1, tt, tin[ai], tout[ai], lf[ai]);
    }
    
    for(auto p : qq[i]){
      ai = p.node;
      out[p.idx] += ask(1, 1, tt, tin[ai]) * p.sign;
    }
  }
  for(auto x : out)
    cout << x << "\n";
  return 0;
}