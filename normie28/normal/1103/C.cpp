// Problem: C. Johnny Solving
// Contest: Codeforces - Codeforces Round #534 (Div. 1)
// URL: https://codeforces.com/contest/1103/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define MAXN 250005
int n,m,k,len,tot,head[MAXN],qu[MAXN],id[MAXN],cnt,vis[MAXN];
struct edge {
	int u,v,nxt;
} edg[MAXN<<2];
inline void addedg(int u,int v) {
	edg[tot].u = u;
	edg[tot].v = v;
	edg[tot].nxt = head[u];
	head[u] = tot++;
}
bool dfs1(int u,int fa) {
	if(cnt == len) return true;
	for(int i = head[u]; i != -1; i = edg[i].nxt) {
		int v = edg[i].v;
		if(v != fa && !vis[v]) {
			qu[cnt++] = v;
			vis[v] = 1;
			if(dfs1(v,u)) return true;
			--cnt;
		}
	}
	return false;
}
void dfs2(int u,int fa) {
	int flag = 0;
	if(k == 0) return;
	for(int i = head[u]; i != -1; i = edg[i].nxt) {
		int v = edg[i].v;
		if(v != fa && !vis[v]) {
			flag = 1;
			qu[cnt] = v;
			id[v] = cnt;
			vis[v] = 1;
			++cnt;
			dfs2(v,u);
			--cnt;
		}
	}
	if(!flag) {
		int fa1 = -1,fa2 = -1;
		for(int i = head[u]; i != -1; i = edg[i].nxt) {
			int v = edg[i].v;
			if(v != fa) {
				if(fa1 == -1) fa1 = v;
				else {
					fa2 = v;
					break;
				}
			}
		}
		if(id[fa1] < id[fa2]) swap(fa1,fa2);
		flag = 0;
		if((id[u] - id[fa1] + 1) % 3) flag = fa1;
		else if((id[u] - id[fa2] + 1) % 3) flag = fa2;
		if(flag) {
			len = id[u] - id[flag] + 1;
			printf("%d\n",len);
			for(int i = id[u]; i >= id[flag]; --i) printf("%d ",qu[i]);
			printf("\n");
			--k;
		} else {
			len = id[fa1] - id[fa2] + 2;
			printf("%d\n",len);
			printf("%d ",u);
			for(int i = id[fa1]; i >= id[fa2]; --i) printf("%d ",qu[i]);
			printf("\n");
			--k;
		}
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	memset(head,-1,4 * n + 4);
	tot = cnt = 0;
	int u,v;
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d",&u,&v);
		addedg(u,v);
		addedg(v,u);
	}
	len = n / k;
	if(n%k) ++len;
	vis[1] = 1;
	qu[cnt++] = 1;
	if(dfs1(1,1)) {
		printf("PATH\n%d\n",len);
		for(int i = 0; i < cnt; ++i) printf("%d ",qu[i]);
	} else {
		memset(vis,0,4*n+4);
		cnt = 0;
		printf("CYCLES\n");
		qu[cnt++] = 1;
		id[1] = 0;
		vis[1] = 1;
		dfs2(1,1);
	}
}