#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const int MOD = 998244353;

struct Node{
  int value;
  int lz_multi;
  int lz_add;
};

struct SegTree{ 
  Node Tree[4000000];
  int sz;
  void Init(int n){
    sz = n;
    for(int i = 0;i < 4000000;i ++ ){
      Tree[i].value = 0;
      Tree[i].lz_add = 0;
      Tree[i].lz_multi = 1;
    }
  }
  void push(int node, int cl, int cr){
    Tree[node].value = (Tree[node].value * 1ll * Tree[node].lz_multi) % MOD;
    Tree[node].value = (Tree[node].value + (1ll * Tree[node].lz_add * (cr - cl + 1))) % MOD;
    if(cl != cr){
      Tree[node * 2].lz_multi = (Tree[node * 2].lz_multi * 1ll * Tree[node].lz_multi) % MOD;
      Tree[node * 2].lz_add = (Tree[node * 2].lz_add * 1ll * Tree[node].lz_multi) % MOD;
      Tree[node * 2].lz_add = (Tree[node * 2].lz_add + Tree[node].lz_add) % MOD;
      Tree[node * 2 + 1].lz_multi = (Tree[node * 2 + 1].lz_multi * 1ll * Tree[node].lz_multi) % MOD;
      Tree[node * 2 + 1].lz_add = (Tree[node * 2 + 1].lz_add * 1ll * Tree[node].lz_multi) % MOD;
      Tree[node * 2 + 1].lz_add = (Tree[node * 2 + 1].lz_add + Tree[node].lz_add) % MOD;
    }
    Tree[node].lz_multi = 1;
    Tree[node].lz_add = 0;
  }
  void Update(int node, int cl, int cr, int tl, int tr, int upd){
    push(node, cl, cr);
    if(cl > cr)
      return;
    if(cr < tl) 
      return;
    if(cl > tr)
      return;
    if(cl >= tl and cr <= tr){
      if(upd == 0){
        Tree[node].lz_add ++ ;
        Tree[node].lz_add %= MOD;
      }
      else{
        Tree[node].lz_multi = (Tree[node].lz_multi * 2ll) % MOD;
        Tree[node].lz_add = (Tree[node].lz_add * 2ll) % MOD;
      }
      push(node, cl, cr);
      return;
    }
    int md = (cl + cr)/2;
    Update(node*2, cl, md, tl, tr, upd);
    Update(node*2+1, md + 1, cr, tl, tr, upd);
    Tree[node].value = Tree[node * 2].value + Tree[node * 2 + 1].value;
    if(Tree[node].value >= MOD)
      Tree[node].value -= MOD;
  }
  int Ask(int node, int cl, int cr, int tl, int tr){
    push(node, cl, cr);
    if(cl > cr)
      return 0;
    if(cr < tl)
      return 0;
    if(cl > tr)
      return 0;
    if(cl >= tl and cr <= tr){
      return Tree[node].value;
    }
    int md = (cl + cr)/2;
    return (Ask(node*2, cl, md, tl, tr) + Ask(node*2+1, md+1, cr, tl, tr)) % MOD;
  }
};

SegTree sizes;

const int N = (int)2e5 + 9;
set<pii> Segm[N];

void Update_Range(int L, int R, int mm){
  if(L > R)
    return;
  sizes.Update(1, 0, sizes.sz - 1, L, R, mm);
}

int Query(int L, int R){
  return sizes.Ask(1, 0, sizes.sz - 1, L, R);
}

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  sizes.Init(n);
  int t, l, r, x;
  for(int i = 0;i < q;i ++ ){
    cin >> t;
    if(t == 1){
      cin >> l >> r >> x;
      --l;
      --r;
      auto it = Segm[x].lower_bound(mp(l, 0));
      if(it != Segm[x].begin())
        it -- ;
      int Al = l, Ar = r;
      int Cl, Cr;
      int Ul, Ur;
      int las = l;
      while(it != Segm[x].end() and it->fi <= r){
        Cl = it->fi;
        Cr = it->se;
        if(Cr < l){
          it ++ ;
          continue;
        }
        Al = min(Al, Cl);
        Ar = max(Ar, Cr);
        Ul = Cl;
        Ur = Cr;
        Ul = max(Ul, l);
        Ur = min(Ur, r);
        Update_Range(Ul, Ur, 1);
        Update_Range(las, Cl - 1, 0);
        las = Cr + 1;
        auto nex = it;
        nex ++ ;
        Segm[x].erase(it);
        it = nex;
      }
      Update_Range(las, r, 0);
      Segm[x].insert(mp(Al, Ar));
    }
    else{
      cin >> l >> r;
      l --;
      r --;
      cout << Query(l, r) << "\n";
    }
  } 
  return 0;
}