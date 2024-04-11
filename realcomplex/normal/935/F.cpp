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

const int N = (int)1e5 + 10;

struct Node{
  ll val;
  ll lzy;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
  T[node].val += T[node].lzy;
  if(cl != cr){
    T[node * 2].lzy += T[node].lzy;
    T[node * 2 + 1].lzy += T[node].lzy;
  }
  T[node].lzy = 0;
}

void upd(int node, int cl, int cr, int tl, int tr, ll v){
  push(node, cl, cr);
  if(cr < tl || cl > tr) return;
  if(cl >= tl && cr <= tr){
    T[node].lzy = v;
    push(node, cl, cr);
    return;
  }
  int mid = (cl + cr) / 2;
  upd(node * 2, cl, mid, tl, tr, v);
  upd(node * 2 + 1, mid + 1, cr, tl, tr, v);
}

ll ask(int node, int cl, int cr, int p){
  push(node, cl, cr);
  if(cl == cr)
    return T[node].val;
  int mid = (cl + cr) / 2;
  if(mid >= p) return ask(node * 2, cl, mid, p);
  else return ask(node * 2 + 1, mid + 1, cr, p);
}

int n;
ll get(int id){  
  return ask(1, 1, n, id);
}

ll sum;

ll ab(ll x) {
  return max(x,-x);
}

ll diff(int i, ll x, ll y){
  return ab(get(i)+x-get(i+1)-y);
}

struct S{
  bool h1;
  ll n1;
  ll n2;
  int idx;
};

const ll inf = (ll)1e18;

S unite(S A, S B){
  S Q;
  Q.h1 = (A.h1 | B.h1);
  Q.n1 = max(A.n1, B.n1);
  Q.n2 = max(A.n2, B.n2);
  Q.idx = max(A.idx, B.idx);
  return Q;
}

S tree[N * 4 + 512];

void incr(int node, int cl, int cr, int pos, S F){
  if(cl == cr){
    tree[node] = F;
    return;
  }
  int mid = (cl + cr) / 2;
  if(mid >= pos)
    incr(node * 2, cl, mid, pos, F);
  else
    incr(node * 2 + 1, mid + 1, cr, pos, F);
  tree[node] = unite(tree[node * 2], tree[node * 2 + 1]);
}

S qry(int node, int cl, int cr, int tl, int tr){
  if(cr < tl || cl > tr) return {false, -inf, -inf, -1};
  if(cl >= tl && cr <= tr){
    return tree[node];
  }
  int mid = (cl + cr) / 2;
  return unite(qry(node * 2, cl, mid, tl, tr), qry(node * 2 + 1, mid + 1, cr, tl, tr));
}

void upds(int id, int act){
  if(!act) incr(1, 1, n, id, {false, -inf,-inf,-1});
  else{
    if(id <= 1 || id >= n) return;
    S pq = {false, -inf, -inf, -1};
    ll li = get(id - 1);
    ll mid = get(id);
    ll ri = get(id + 1);
    if(mid >= li && mid >= ri) 
      pq.h1 = true;
    if(li <= mid && mid <= ri)
      pq.n1 = 2ll * (mid - ri);
    if(li >= mid && mid >= ri){
      pq.n2 = 2ll * (mid - li);
    }
    if(mid <= li && mid <= ri)
      pq.idx = id;
    incr(1, 1, n, id, pq);
  }
}


int main(){
  fastIO;
  for(int i = 0 ; i < N * 4 + 512; i ++ )
    tree[i] = {false, -inf, -inf, -1};
  cin >> n;
  int a;
  for(int i = 1; i <= n; i ++ ){
    cin >> a;
    upd(1, 1, n, i, i, a);
  }
  for(int i = 1; i < n; i ++ ){
    sum += diff(i,0,0);
  }
  for(int i = 2; i <= n-1; i ++ ){
    upds(i, 1);
  }
  int q;
  cin >> q;
  int typ, l, r;
  ll x;
  
  for(int i = 0 ; i < q; i ++ ){
    cin >> typ >> l >> r >> x;
    if(typ == 2){
      sum -= diff(l - 1, 0, 0);
      sum -= diff(r, 0, 0);
      upds(l - 1, 0);
      upds(l, 0);
      upds(r, 0);
      upds(r + 1, 0);
      upd(1, 1, n, l, r, x);
      upds(l - 1, 1);
      upds(l, 1);
      upds(r, 1);
      upds(r + 1, 1);
      sum += diff(l - 1, 0, 0);
      sum += diff(r, 0, 0);
    }
    else{
      ll ans = -inf;
      S cur = qry(1, 1, n, l, r);
      if(cur.h1) ans = 2ll * x;
      if(cur.n1 != -inf) ans = max(ans, max(0ll, cur.n1 + 2ll * x));
      if(cur.n2 != -inf) ans = max(ans, max(0ll, cur.n2 + 2ll * x));
      if(cur.idx != -1){
        ans = max(ans, diff(cur.idx - 1, 0, x) + diff(cur.idx, x, 0) -diff(cur.idx - 1, 0, 0) - diff(cur.idx, 0, 0));
      }
      cout << sum + ans << "\n";
    }
  }
  return 0;
}