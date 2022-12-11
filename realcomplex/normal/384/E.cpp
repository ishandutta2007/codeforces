#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

struct Node{
  ll value;
  ll lazy;
};

struct SegTree{
  Node Tree[600000];
  int n;
  void push(int node, int tl, int tr){
    if(Tree[node].lazy != 0){
      Tree[node].value += (tr - tl + 1) * Tree[node].lazy;
      if(tl != tr){
        Tree[node * 2].lazy += Tree[node].lazy;
        Tree[node * 2 + 1].lazy += Tree[node].lazy;
      }
      Tree[node].lazy = 0;
    }
  }
  void update(int node, int cl, int cr, int tl, int tr, int val){
    push(node, cl, cr);
    if(cr < tl)
      return;
    if(cl > tr)
      return;
    if(cl >= tl and cr <= tr){
      Tree[node].lazy = val;
      push(node, cl, cr);
      return;
    }
    int mid = (cl + cr)/2;
    update(node * 2, cl, mid, tl, tr, val);
    update(node * 2 + 1, mid+1, cr, tl, tr, val);
    Tree[node].value = Tree[node * 2].value + Tree[node * 2 + 1].value;
  }
  int query(int node, int cl, int cr, int tl, int tr){
    push(node, cl, cr);
    if(cr < tl)
      return 0;
    if(cl > tr)
      return 0;
    if(cl >= tl and cr <= tr){
      return Tree[node].value;
    }
    int mid = (cl + cr)/2;
    return query(node * 2, cl, mid, tl, tr) + query(node * 2 + 1, mid + 1, cr, tl, tr);
  }
  void Print(){
    for(int i = 1;i < n*2;i ++ )
      cout << Tree[i].value << " ";
    cout << "\n";
  }
  void Init(int N){
    n = 1 << int(log2(N - 1) + 1);
    for(int i = 0;i < n*2;i ++ ){
      Tree[i].value = 0;
      Tree[i].lazy = 0;
    }
  }
};

SegTree even, odd;
const int N = 200005;
vector<int>T[N];
int topen[N];
int tclose[N];
int dep[N];
int tt;

void dfs(int u, int par, int dd){
  topen[u] = tt ++ ;
  dep[u] = dd;
  for(auto x : T[u]){
    if(x == par)
      continue;
    dfs(x, u, dd + 1);
  }
  tclose[u] = tt - 1;
}


int main(){
  fastIO;
  int N,q;
  cin >> N >> q;
  even.Init(N);
  odd.Init(N);
  int a[N];
  for(int i = 0;i < N; i++ ){
    cin >> a[i];
  }
  int u, v;
  for(int i = 1;i < N;i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(1, -1, 0);
  for(int i = 0;i < N; i ++ ){
    even.update(1, 0, even.n - 1, topen[i + 1], topen[i + 1], a[i]);
    odd.update(1, 0, odd.n - 1, topen[i + 1], topen[i + 1], a[i]);
  }
  int nod;
  int tt;
  int val;
  int even_val;
  int odd_val;
  for(int i = 0;i < q;i ++ ){
    cin >> tt;
    if(tt == 1){
      cin >> nod >> val;
      even_val = val;
      odd_val = -val;
      if(dep[nod]&1){
        swap(even_val, odd_val);
      }
      even.update(1, 0, even.n - 1, topen[nod], tclose[nod], even_val);
      odd.update(1, 0, odd.n - 1, topen[nod], tclose[nod], odd_val);
    }
    else{
      cin >> nod;
      if(dep[nod] % 2 == 0)
        cout << even.query(1, 0, even.n - 1, topen[nod], topen[nod]) << "\n";
      else
        cout << odd.query(1, 0, odd.n - 1, topen[nod], topen[nod]) << "\n";
    }
  }
  return 0;
}