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

struct Node{
  ll sum[10];
  int nx[10];
};

ll ch[10];
int pi[10];

struct SegTree{
  Node T[500000];
  int N;
  
  void Init(int n, ll a[]){
    N = 1 << int(log2(n - 1) + 1);
    for(int i = 0;i < 500000;i ++ ){
      for(int j = 0;j < 10; j ++ )
        T[i].sum[j] = 0, T[i].nx[j] = j;
    }
    int p = 0;
    ll rz;
    ll dl;
    for(int j = N;j < N + n; j ++ ){
      dl = a[p];
      rz = 1;
      while(dl > 0){
        T[j].sum[dl%10] += rz;
        rz *= 10;
        dl /= 10;
      }
      p ++ ;
    }
    for(int j = N-1; j >= 1; j -- ){
      for(int x = 0; x < 10; x ++ ){
        T[j].sum[x] = T[j * 2].sum[x] + T[j * 2 + 1].sum[x];
      }
    }
  }
  void Push(int node, int tl, int tr){
    memset(ch, 0, sizeof ch);
    for(int j = 0;j < 10;j ++ ){
      ch[T[node].nx[j]] += T[node].sum[j];
    }
    for(int j = 0;j < 10; j ++ )
      T[node].sum[j] = ch[j];
    if(tl != tr){
      for(int j = 0;j < 10;j ++ )
        pi[j] = j;
      for(int j = 0;j < 10; j ++ ){
        pi[j] = T[node].nx[T[node * 2].nx[j]];
      }
      for(int j = 0;j < 10;j ++ ){
        T[node * 2].nx[j] = pi[j];
      }
      /* !#@% */
      for(int j = 0;j < 10;j ++ )
        pi[j] = j;
      for(int j = 0;j < 10; j ++ ){
        pi[j] = T[node].nx[T[node * 2 + 1].nx[j]];
      }
      for(int j = 0;j < 10;j ++ ){
        T[node * 2 + 1].nx[j] = pi[j];
      }
    }
    for(int j = 0;j < 10;j ++ )
      T[node].nx[j] = j;
  }
  void Update(int node, int cl, int cr, int tl, int tr, int xu, int yu){
    Push(node, cl, cr);
    if(cr < tl) 
      return;
    if(cl > tr)
      return;
    if(cl > cr)
      return;
    if(cl >= tl and cr <= tr){
      T[node].nx[xu] = yu;
      Push(node, cl, cr);
      return;
    }
    int md = (cl + cr)/2;
    Update(node * 2, cl, md, tl, tr, xu, yu);
    Update(node * 2 + 1, md + 1, cr, tl, tr, xu, yu);
    for(int j = 0;j < 10; j ++ )
      T[node].sum[j] = T[node * 2].sum[j] + T[node * 2 + 1].sum[j];
  }
  ll Ask(int node, int cl, int cr, int tl, int tr){
    Push(node, cl, cr);
    if(cr < tl)
      return 0;
    if(cl > tr)
      return 0;
    if(cl > cr)
      return 0;
    if(cl >= tl and cr <= tr){
      ll rez = 0;
      for(int j = 0; j < 10; j ++ ){
        rez += T[node].sum[j] * j;
      }
      return rez;
    }
    int md = (cl + cr)/2;
    return Ask(node * 2, cl, md , tl, tr) + Ask(node * 2 + 1, md + 1, cr, tl, tr);
  }
};

SegTree TR;

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  ll k[n];
  for(int i = 0;i < n;i ++ )
    cin >> k[i];
  TR.Init(n, k);
  int ty;
  int l, r, x, y;
  for(int i = 0;i < q; i ++ ){
    cin >> ty;
    if(ty == 1){
      cin >> l >> r >> x >> y;
      --l, --r;
      TR.Update(1, 0, TR.N-1, l, r, x, y);
    }
    else{
      cin >> l >> r;
      --l, --r;
      cout << TR.Ask(1, 0, TR.N-1, l, r) << "\n";
    }
  } 
  return 0;
}