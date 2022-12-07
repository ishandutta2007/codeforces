#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, tag;
int x[N];
int vst[N];
int nxt[N];
int last[N];
int save[N];

struct Persistent_SegmentTree{
  struct node{
    int left;
    int right;
    int val;
  }a[N * 50];
  int pos[N];
  vector < int > lst;
  int sz = 1, root = 1;
  #define mid ((l + r) >> 1)
  void build(int i, int l, int r){
    if(l == r){
      return;
    }
    a[i].left = ++sz;
    a[i].right = ++sz;
    build(a[i].left, l, mid);
    build(a[i].right, mid + 1, r);
  }
  void init(){
    lst.push_back(1);
    build(1, 1, n);
  }
  void upd(int u, int v, int l, int r, int p, int ins){
    a[u] = a[v];
    a[u].val += ins;
    if(l == r){
      return;
    }
    if(mid >= p){
      a[u].left = ++sz;
      upd(a[u].left, a[v].left, l, mid, p, ins);
    }
    else{
      a[u].right = ++sz;
      upd(a[u].right, a[v].right, mid + 1, r, p, ins);
    }
  }
  void update(int p, int ins){
    lst.push_back(++sz);
    upd(sz, root, 1, n, p, ins);
    root = lst.back();
  }
  int fin(int u, int l, int r, int s){
    if(l == r){
      if(a[u].val > s){
        return -1;
      }
      return r;
    }
    int x = a[a[u].left].val;
    if(x > s){
      return fin(a[u].left, l, mid, s);
    }
    return max(mid, fin(a[u].right, mid + 1, r, s - x));
  }
  int ask(int u, int l, int r, int d, int c){
    if(l >= d && r <= c){
      return a[u].val;
    }
    if(l > c || d > r){
      return 0;
    }
    return ask(a[u].left, l, mid, d, c) + ask(a[u].right, mid + 1, r, d, c);
  }
}smt;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", x + i);
  }
  smt.init();
  for(int i = 1; i <= n; ++i){
    if(vst[x[i]] == 0){
      smt.update(i, 1);
    }
    vst[x[i]] = 1;
  }
  for(int i = n; i >= 1; --i){
    nxt[i] = last[x[i]];
    last[x[i]] = i;
  }
  save[1] = smt.root;
  for(int i = 2; i <= n; ++i){
    smt.update(i - 1, -1);
    if(nxt[i - 1] != 0){
      smt.update(nxt[i - 1], 1);
    }
    save[i] = smt.root;
  }
  for(int curr = 1; curr <= n; ++curr){
    int i = 1, ans = 0;
    while(i <= n){
      ++ans;
      i = smt.fin(save[i], 1, n, curr) + 1;
    }
    printf("%d ", ans);
  }
  return 0;
}