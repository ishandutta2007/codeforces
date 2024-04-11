#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
 
// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
// template<typename T>
// __attribute__((always_inline)) void chkmin(T& a, const T& b) {
//     a=(a<b)?a:b;
// }
 
// template<typename T>
// __attribute__((always_inline)) void chkmax(T& a, const T& b) {
//     a=(a>b)?a:b;
// }
 
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
#endif
namespace SAT {
	vector<int> gt[2200101],gtr[2200101],tout;
	int res[2200101];
	int reg[2200101];
	int n,m,i,j,k,t,t1,u,v,a,b;
	void dfs1(int x)
	{
		reg[x]=1;
		for (auto g : gt[x]) if (!reg[g]) dfs1(g);
		tout.push_back(x);
	}
	void dfs2(int x, int& t)
	{
		reg[x]=t;
		for (auto g : gtr[x]) if (!reg[g]) dfs2(g,t);
	}
	int solveSAT(int n)
	{
		int i;
		int t;
		for (i=0;i<2*n;i++) gtr[i].clear();
		for (i=0;i<2*n;i++) for (auto g : gt[i]) gtr[g].push_back(i);
		tout.clear();
		for (i=0;i<2*n;i++) reg[i]=0;
		for (i=0;i<2*n;i++) if (!reg[i]) dfs1(i);
		for (i=0;i<2*n;i++) reg[i]=0;
		t=0;
		for (i=2*n-1;i>=0;i--) if (!reg[tout[i]])
		{
			t++;
			dfs2(tout[i],t);
		}
		for (i=0;i<n;i++) if (reg[i*2]==reg[i*2+1]) return 0;
		for (i=0;i<2*n;i++) res[i]=-1;
		for (i=0;i<2*n;i++) if (res[tout[i]]==-1)
		{
			res[tout[i]]=1;
			res[tout[i]^1]=0;
		}
		return 1;
	}
 
	void add(int u, int v)
	{
		// cout<<"add "<<(u/2)<<' '<<(u&1)<<' '<<(v/2)<<' '<<(v&1)<<endl;
		gt[u].push_back(v);
		gt[v^1].push_back(u^1);
	}
}
 
 
vector<int> vec[2];
vector<int> val[2];
int n,m,i,j,k,t,t1,u,v,a,b;
int L,R;
int l[100001],r[100001];
int main()
{
	fio;
	cin>>L>>R>>n>>m;
	for (i=1;i<=n;i++) {
		cin>>l[i]>>r[i];
		vec[0].push_back(l[i]);
		vec[0].push_back(r[i]+1);
	}
	vec[0].push_back(0);
	sort(vec[0].begin(), vec[0].end());
	vec[0].erase(unique(vec[0].begin(), vec[0].end()),vec[0].end());
	for (auto g : vec[0]) val[0].push_back(g);
	for (auto g : vec[0]) if (g) val[0].push_back(g-1);
 
	sort(val[0].begin(), val[0].end());
	val[0].erase(unique(val[0].begin(), val[0].end()),val[0].end());
 
	vec[1]=vec[0];
	for (auto g : vec[0]) {
		if (R-g+1>=0) vec[1].push_back(R-g+1);
	}
	for (auto g : vec[0]) if (g) {
		if (L-g+1>=0) vec[1].push_back(L-g+1);
	}
 
	sort(vec[1].begin(), vec[1].end());
	vec[1].erase(unique(vec[1].begin(), vec[1].end()),vec[1].end());
	val[1]=vec[1];
 
	val[0].clear();
	val[0]=vec[0];


	vec[0].clear();
	vec[1].clear();
	// for (auto g : val[0]) cout<<g<<' '; cout<<endl;
	// for (auto g : val[1]) cout<<g<<' '; cout<<endl;
 
	a=val[0].size();
	b=val[1].size();
	
	SAT::add((0)*2+1,(0)*2+0);
	SAT::add((a)*2+0,(a)*2+1);
	SAT::add((a+1)*2+1,(a+1)*2+0);
	SAT::add((a+1+b)*2+0,(a+1+b)*2+1);
	for (i=1;i<=a;i++) {
		SAT::add((i)*2+0,(i-1)*2+0);
	}
	for (i=a+2;i<=a+b+1;i++) {
		SAT::add((i)*2+0,(i-1)*2+0);
	}
 
 
 
	j=k=a;
	j--;
	for (i=0;i<b;i++) {
		while(j && val[0][j]>L-val[1][i]) j--;
		while(k && val[0][k-1]>R-val[1][i]) k--;
		// cout<<i<<' '<<j<<' '<<k<<endl;
		SAT::add((a+1+i)*2,(k)*2+1);
		SAT::add((a+1+i+1)*2+1,(j)*2);
	}
	for (i=1;i<=n;i++) {
		j=upper_bound(val[0].begin(),val[0].end(),l[i])-val[0].begin()-1;
		j=max(j,0);
		k=upper_bound(val[0].begin(),val[0].end(),r[i])-val[0].begin();
		SAT::add((a+1+b+1+i-1)*2+1,(k)*2+1);
		SAT::add((a+1+b+1+i-1)*2+1,(j)*2);
		j=lower_bound(val[1].begin(),val[1].end(),l[i])-val[1].begin();
		k=upper_bound(val[1].begin(),val[1].end(),r[i])-val[1].begin();
		SAT::add((a+1+b+1+i-1)*2,(a+1+k)*2+1);
		SAT::add((a+1+b+1+i-1)*2,(a+1+j)*2);
	}
 
	// cin>>m;
	for (i=1;i<=m;i++) {
		cin>>u>>v;
		SAT::add((a+1+b+1+u-1)*2,(a+1+b+1+v-1)*2+1);
		SAT::add((a+1+b+1+u-1)*2+1,(a+1+b+1+v-1)*2);
	}
	// if (n>10000) return 0; 
 
	if (SAT::solveSAT(a+1+b+1+n)) {
		cout<<"POSSIBLE\n";
		ll ra,rb;
		for (i=0;i<a;i++) if (SAT::res[(i)*2]==1 && SAT::res[(i+1)*2]==0) ra=val[0][i];
		for (i=0;i<b;i++) if (SAT::res[(a+1+i)*2]==1 && SAT::res[(a+1+i+1)*2]==0) rb=val[1][i];
		cout<<max(ra,L-rb)<<' '<<rb;
		cout<<endl;
		for (i=1;i<=n;i++) cout<<SAT::res[(a+1+b+1+i-1)*2]+1;
	}
	else {
		cout<<"IMPOSSIBLE\n";
	}
}
// a;
// R-end+1=x
// R-x=g-1
// L-x=g-1