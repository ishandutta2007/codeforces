#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 9;
const int LOG = 20;

int a[N];

struct Node{
  ll ans;
  int li;
  int ri;
  vector<pii> lef;
  vector<pii> rig;
};

Node T[N * 4 + 512];
int k;
int re = 0;

Node unite(Node A, Node B){
  if(A.ans == -1) return B;
  if(B.ans == -1) return A;
  Node R;
  R.ans = A.ans + B.ans;
  R.li = A.li;
  R.ri = B.ri;
  R.rig = A.rig;
  for(int i = 0 ; i < B.rig.size(); i ++ ){
    if(((R.rig.back().fi) | B.rig[i].fi) > R.rig.back().fi){
      R.rig.push_back(mp((R.rig.back().fi | B.rig[i].fi), B.rig[i].se));
    }
  }
  R.lef = B.lef;
  for(int i = 0; i < A.lef.size() ; i ++ ){
    if(((R.lef.back().fi) | A.lef[i].fi) > R.lef.back().fi){
      R.lef.push_back(mp((R.lef.back().fi | A.lef[i].fi), A.lef[i].se));
    }
  }
  //
  for(int i = 0; i < A.lef.size(); i ++ ){
    A.lef[i].se = (A.lef[i].se - A.li + 1);
  }
  for(int i = 0 ; i + 1 < A.lef.size(); i ++ ){
    A.lef[i].se -= A.lef[i + 1].se;
  }
  for(int i = 0 ; i < B.rig.size(); i ++ ){
    B.rig[i].se = (B.ri - B.rig[i].se + 1);
  }
  for(int i = 0; i + 1 < B.rig.size(); i ++ ){
    B.rig[i].se -= B.rig[i + 1].se;
  }
  for(int i = 0 ; i < A.lef.size(); i ++ ){
    for(int j = 0 ; j < B.rig.size(); j ++ ){
      if((A.lef[i].fi | B.rig[j].fi) >= k){
        R.ans += A.lef[i].se * 1ll * B.rig[j].se; 
      }
    }
  }
  return R;
}

void build(int node, int cl, int cr){
  if(cl == cr){
    T[node].ans = (a[cl] >= k);
    T[node].li = cl;
    T[node].ri = cl;
    T[node].lef = {mp(a[cl], cl)};
    T[node].rig = {mp(a[cl], cl)};
    return;
  }
  int mid = (cl + cr) / 2;
  build(node * 2, cl, mid);
  build(node * 2 + 1, mid + 1, cr);
  T[node] = unite(T[node * 2], T[node * 2 + 1]);
} 

void upd(int node, int cl, int cr, int pos, int x){
  if(cl == cr){
    T[node].ans = (x >= k);
    T[node].li = cl;
    T[node].ri = cl;
    T[node].lef = {mp(x, cl)};
    T[node].rig = {mp(x, cl)};
    return ;
  }
  int mid = (cl + cr) / 2;
  if(mid >= pos)upd(node * 2, cl, mid, pos, x);
  else upd(node * 2 + 1, mid + 1, cr, pos, x);
  T[node] = unite(T[node * 2], T[node * 2 + 1]);
}

Node cur;

void ask(int node, int cl, int cr, int tl, int tr){
  if(cr < tl) return;
  if(cl > tr) return;
  if(cl >= tl && cr <= tr){
    cur = unite(cur, T[node]);
    return;
  }
  int mid = (cl + cr) / 2;
  ask(node * 2, cl, mid, tl, tr);
  ask(node * 2 + 1, mid + 1, cr, tl, tr);
}

int main(){
  fastIO;
  int n,q;
  cin >> n >> q >> k;
  for(int i = 1; i <= n; i ++ )
    cin >> a[i];
  
  build(1,1,n);
  int id, l, r;
  for(int i = 1; i <= q; i ++ ){
    cin >> id >> l >> r;
    if(id == 2){
      cur.ans = -1;
      ask(1, 1, n, l, r);
      cout << cur.ans << "\n";
    }
    else{
      upd(1, 1, n, l, r);
    }
  }
  return 0;
}