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
vector<pii(ll)> gt[100001];
ll n,m,i,j,k,t,t1,u,v,a,b;
ll dep[200001],ord[200001],pos[200001];
ll spa[200001][20];
ll og2[200001];
struct cmp
{
	ll operator()(ll a, ll b)
	{
		return (pos[a]<pos[b]);
	}
};
void dfs(ll x, ll d, ll p)
{
//	cout<<"dfs "<<x<<' '<<d<<' '<<p<<endl;
	pos[x]=t+1;
	dep[x]=d;
	t++;
	ord[t]=x;
	for (auto g : gt[x]) if (g.fi!=p)
	{
		dfs(g.fi,d+g.se,x);
		t++;
		ord[t]=x;
	}
}
ll dist(ll u, ll v)
{
	ll res=dep[u]+dep[v];
//	cout<<"dist "<<u<<' '<<v<<' '<<res<<endl;
	u=pos[u];
	v=pos[v];
	if (u>v) swap(u,v);
	ll a=floor(log2(v-u+1));
	res-=2*min(spa[u][a],spa[v-(1<<a)+1][a]);
//	cout<<"dist "<<u<<' '<<v<<' '<<res<<endl;
	return res;
}
set<ll,cmp> nodes; ll cur;
void n_add(ll x)
{
//	cout<<"n_add "<<x<<endl;
	nodes.insert(x);
//	for (auto g : nodes) cout<<g<<' '; cout<<endl;
	auto it=nodes.lower_bound(x);
	if (nodes.size()==1) return;
	ll prv=-1,nxt=-1;
	if (it==nodes.begin());
	else
	{
		it--;
		prv=(*it);
		it++;
	}
	it++;
	if (it!=nodes.end()) nxt=(*it);
	it--;
	if (prv==-1) prv=*(--nodes.end());
	if (nxt==-1) nxt=*(nodes.begin());
//	cout<<prv<<' '<<nxt<<endl;
	cur+=dist(prv,x);
	cur+=dist(x,nxt);
	cur-=dist(prv,nxt);
}
void n_del(ll x)
{
//	cout<<"n_del "<<x<<endl;
	if (nodes.size()>1)
	{
//	for (auto g : nodes) cout<<g<<' '; cout<<endl;
	auto it=nodes.lower_bound(x);
	if (nodes.size()==1) return;
	ll prv=-1,nxt=-1;
	if (it==nodes.begin());
	else
	{
		it--;
		prv=(*it);
		it++;
	}
	it++;
	if (it!=nodes.end()) nxt=(*it);
	it--;
	if (prv==-1) prv=*(--nodes.end());
	if (nxt==-1) nxt=*(nodes.begin());
//	cout<<prv<<' '<<nxt<<endl;
	cur-=dist(prv,x);
	cur-=dist(x,nxt);
	cur+=dist(prv,nxt);
	}
	nodes.erase(x);
}
int main()
{
	fio;
	cin>>n;
	t=0;
	for (i=1;i<n;i++)
	{
		cin>>a>>b>>v;
		gt[a].push_back({b,v});
		gt[b].push_back({a,v});
	}
	dfs(1,0,-1);
	for (i=1;i<2*n;i++) {spa[i][0]=dep[ord[i]]; }
	for (i=1;i<=19;i++)
	{
		for (j=1;j<2*n;j++)
		{
			spa[j][i]=spa[j][i-1];
			if (j+(1<<(i-1))<=2*n) spa[j][i]=min(spa[j][i],spa[j+(1<<(i-1))][i-1]);
		}
	}
	cin>>m;
	for (i=1;i<=m;i++)
	{
		char c;
		cin>>c;
		if (c=='?') cout<<cur/2<<endl;
		else if (c=='+')
		{
			cin>>a;
			n_add(a);
		}
		else
		{
			cin>>a;
			n_del(a);
		}
	}
}