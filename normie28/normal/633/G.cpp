/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 

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
#define lson (id<<1)
#define rson ((id<<1)|1)
#define mid ((tree[id].l+tree[id].r)>>1)
 
const int N  = 110000;
const int M = 1020;
int n, m;
int head[N], tot;
struct Edge{
	int to, next;
}edge[N<<2];
 
void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}
 
void add_edge(int u, int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
 
int in[N], out[N], idx, dfn[N];
void dfs(int u, int fa){
	in[u] = ++idx;
	dfn[idx] = u;
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if(v != fa)	
		  	dfs(v, u);
	}
	out[u] = idx;
}
 
int arr[N];
bitset<M> prime;
bool is_prime(int x){
	for(int i = 2; i*i <= x; i++)
	  	if(x%i == 0)return false;
	return true;
}
 
void init_prime(){
	prime.reset();
	for(int i = 2; i < m; i++)
	  	if(is_prime(i))
		  	prime.set(i);
}
 
struct Node{
	int l, r, lazy;
	bitset<M> value;
}tree[N<<4];
 
void push_up(int id){
	tree[id].value = tree[lson].value | tree[rson].value;
}
 
void cyclic_shift(int id, int x){
	tree[id].value = (tree[id].value<<x) | (tree[id].value>>(m-x));
}
 
void push_down(int id){
	if(tree[id].lazy){
		tree[lson].lazy += tree[id].lazy;
		tree[lson].lazy %= m;
		tree[rson].lazy += tree[id].lazy;
		tree[rson].lazy %= m;
		cyclic_shift(lson, tree[id].lazy);
		cyclic_shift(rson, tree[id].lazy);
		tree[id].lazy = 0;
	}
}
 
void build(int id, int l, int r){
	tree[id].l = l;
	tree[id].r = r;
	tree[id].lazy = 0;
	if(l == r){
		tree[id].value.reset();
		tree[id].value.set(arr[dfn[l]]%m);
		return;
	}
	build(lson, l, mid);
	build(rson, mid+1, r);
	push_up(id);
}
 
void update(int id, int l, int r, int x){
	if(l <= tree[id].l && tree[id].r <= r){
		tree[id].lazy += x;
		tree[id].lazy %= m;
		cyclic_shift(id, x);
		return;
	}
	push_down(id);
	if(l <= mid)update(lson, l, r, x);
	if(r > mid)update(rson, l, r, x);
	push_up(id);
}
 
bitset<M> query(int id, int l, int r){
	if(l <= tree[id].l && tree[id].r <= r){
		return tree[id].value;
	}
	push_down(id);
	bitset<M> ans;
	if(l <= mid) ans |= query(lson, l, r);
	if(r > mid)ans |= query(rson, l, r);
	return ans;
}
 
int main()
{
	fio;
	while(cin>>n>>m){
		init_prime();
		for(int i = 1; i <= n; i++)
			cin>>arr[i];
		int u, v;
		init();
		for(int i = 1; i < n; i++){
			cin>>u>>v;
			add_edge(u, v);
			add_edge(v, u);
		}
		idx = 0;
		dfs(1, 0);
		build(1, 1, n);
		int q, t, x;
		cin>>q;
		while(q--){
			cin>>t>>v;
			if(t == 1){
				cin>>x;
				update(1, in[v], out[v], x%m);
			}else if(t == 2){
				bitset<M> ans = query(1, in[v], out[v]);
				cout<<(int)((ans&prime).count())<<endl;
			}
		}
	}
 
	return 0;
}