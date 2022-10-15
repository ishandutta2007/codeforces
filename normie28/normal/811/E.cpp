// Problem: E. Vladik and Entertaining Flags
// Contest: Codeforces - Codeforces Round #416 (Div. 2)
// URL: https://codeforces.com/contest/811/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
#define N 12
#define M 100005
 
int mat[N][M],t,fa[10*M],n,m,q;
class segment_tree {
public:
  segment_tree() {}
  segment_tree(const segment_tree &x) {
    l = x.l;
    r = x.r;
    c = x.c;
    for (int i = 1; i <= n; ++i) {
      a[i] = x.a[i];
      b[i] = x.b[i];
    }
  }
  int l,r,c,a[N],b[N];
}st[1<<18];
 
int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
 
bool merge(int x,int y) {
  int px = find(x),py = find(y);
  if (px != py) {
    fa[py] = px;
    return true;
  }
  return false;
}
 
void combine(const segment_tree &a,const segment_tree &b,segment_tree &c) {
  for (int k = 1; k <= n; ++k) {
    fa[a.a[k]] = a.a[k];
    fa[a.b[k]] = a.b[k];
    fa[b.a[k]] = b.a[k];
    fa[b.b[k]] = b.b[k];
  }
  c.c = a.c + b.c;
  for (int k = 1; k <= n; ++k)
    if (mat[k][a.r] == mat[k][b.l])
      if (merge(a.b[k],b.a[k])) --c.c;
  for (int k = 1; k <= n; ++k) {
    c.a[k] = find(a.a[k]);
    c.b[k] = find(b.b[k]);
  }
  c.l = a.l,c.r = b.r;
}
 
void push_up(int i) {
  combine(st[i<<1],st[i<<1|1],st[i]);
}
 
void init_st(int i,int l,int r) {
  st[i].l = l;
  st[i].r = r;
  if (l < r) {
    int mid = (l+r)>>1;
    init_st(i<<1,l,mid);
    init_st(i<<1|1,mid+1,r);
    push_up(i);
  } else {
    for (int k = 1; k <= n; ++k) {
      if (k == 1 || mat[k][l] != mat[k-1][l]) {st[i].a[k] = st[i].b[k] = ++t; ++st[i].c;}
      else st[i].a[k] = st[i].b[k] = t;
    }
  }
}
 
 
segment_tree query(int i,int l,int r) {
  if (st[i].l >= l && st[i].r <= r) return st[i];
  int mid = (st[i].l + st[i].r)>>1;
  if (l > mid) return query(i<<1|1,l,r);
  else if (r <= mid) return query(i<<1,l,r);
  segment_tree lt = query(i<<1,l,r),rt = query(i<<1|1,l,r),ret;
  combine(lt,rt,ret);
  return ret;
}
 
int main() {
 	fio;
 	cin>>n>>m>>q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    cin>>mat[i][j];
  init_st(1,1,m);
  for (int l,r; q--; ) {
  	cin>>l>>r;
    cout<<query(1,l,r).c<<endl;
  }
}