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

int n;
struct T{
  int tree[N * 4 + 512];
  void init(){
    for(int i = 0 ; i < (n + 1) * 4 + 512; i ++ ){
      tree[i] = (int)1e9;
    }
  }
  void push(int node, int cl,int cr){
    if(cl != cr){
      tree[node * 2] = min(tree[node * 2], tree[node]);
      tree[node * 2 + 1] = min(tree[node * 2 + 1], tree[node]);
    }
  }
  void upd(int node, int cl, int cr, int tl, int tr, int v){
    push(node, cl, cr);
    if(cr < tl) return;
    if(cl > tr) return;
    if(cl >= tl && cr <= tr){
      tree[node]=min(tree[node],v);
      push(node,cl,cr);
      return;
    }
    int mid = (cl + cr) / 2;
    upd(node * 2, cl, mid, tl, tr, v);
    upd(node * 2 + 1, mid + 1, cr, tl, tr, v);
  }
  int get(int node, int cl, int cr, int pos){
    push(node, cl, cr);
    if(cl == cr){
      return tree[node];
    }
    int mid = (cl + cr) / 2;
    if(mid >= pos) return get(node * 2, cl, mid, pos);
    else return get(node * 2 + 1, mid + 1, cr, pos);
  }
};

int main(){
  fastIO;
  int k;
  cin >> n >> k;
  T cur, nx;
  cur.init();
  cur.upd(1, 0, n, 0, 0, 0);
  int l, r;
  int las = 0;
  int vl;
  int x;
  for(int i = 0 ; i < k ; i ++ ){
    cin >> l >> r;
    nx.init();
    for(int j = 0; j <= n; j ++ ){
      vl = cur.get(1, 0, n, j);
      if(vl == (int)1e9) continue;
      x = j + l - las;
      if(x <= n)
        nx.upd(1, 0, n, x, x, vl);
    }
    cur = nx;
    nx.init();
    for(int j = 0 ; j <= n ; j ++ ){
      vl = cur.get(1, 0, n, j);
      if(vl == (int)1e9) continue;
      x = min(n, j + r - l);
      nx.upd(1, 0, n, j, x, vl + 2);
      if(l - j <= n){
        x = min(l - j + r - l, n);
        nx.upd(1, 0, n, l - j, x, vl + 1);
      }
      x = j + r - l;
      if(x <= n)nx.upd(1, 0, n, x, x, vl);
    }
    for(int j = 0 ; j <= n; j ++ ){
      vl = nx.get(1, 0, n, j);
      if(vl == (int)1e9) continue;
      if(r - j <= n)
        nx.upd(1, 0, n, r - j, r - j, vl + 1);
    }
    cur = nx;
    las = r;
  }
  nx.init();
  for(int j = 0 ; j <= n; j ++ ){
    vl = cur.get(1, 0, n, j);
    if(vl == (int)1e9) continue;
    nx.upd(1, 0, n, j + 2 * n - las, j + 2 * n - las, vl);
  }
  if(nx.get(1, 0, n, n) == (int)1e9){
    cout << "Hungry\n";
    return 0;
  }
  cout << "Full\n";
  cout << nx.get(1, 0, n, n);
  return 0;
}