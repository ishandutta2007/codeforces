#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int MOD = 998244353; 
int a[N];

struct Node{  
  int val;
  int lzy;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
  if(T[node].lzy == -1) return;
  T[node].val = ((cr - cl + 1) * 1ll * T[node].lzy)%MOD;
  if(cl != cr){
    T[node * 2].lzy = T[node].lzy;
    T[node * 2 + 1].lzy = T[node].lzy;
  }
  T[node].lzy = -1;
}

void upd(int node, int cl, int cr, int tl, int tr, int v){
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
  T[node].val = (T[node * 2].val + T[node * 2 + 1].val) % MOD;
}

int get(int node, int cl, int cr, int tl, int tr){
  push(node, cl, cr);
  if(cr < tl || cl > tr) return 0;
  if(cl >= tl && cr <= tr) return T[node].val;
  int mid = (cl + cr) / 2;
  return (get(node * 2, cl, mid, tl, tr) + get(node * 2 + 1, mid + 1, cr, tl, tr)) % MOD;
}

int main(){
  fastIO;
  for(int i = 0 ; i < N * 4 + 512; i ++ )
    T[i].lzy = -1;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
  }
  upd(1, 1, n + 1, n + 1, n + 1, 1);
  vector<int> b(m);
  for(int i = 0 ; i < m ; i ++ ){
    cin >> b[i];
  }
  reverse(b.begin(), b.end());
  int p = n;
  int id;
  int las;
  for(auto x : b){
    id = -1;
    las = -1;
    vector<pii> cur;
    while(p >= 1 && a[p] >= x){
      if(a[p] == x){
        id = p;
        if(las == -1) las = p;
      }
      if(id != -1){
        cur.push_back(mp(p, get(1, 1, n + 1, id + 1, n + 1)));
      }
      p -- ;
    }
    if(id == -1){
      cout << "0\n";
      return 0;
    }
    upd(1, 1, n + 1, 1, n + 1, 0);
    for(auto x : cur)
      upd(1, 1, n + 1, x.fi, x.fi, x.se);
  }
  cout << get(1, 1, n + 1, 1, 1) << "\n";
  return 0;
}