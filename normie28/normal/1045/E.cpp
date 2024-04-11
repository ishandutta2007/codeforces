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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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
#endif
vector<int> vec;
vector<int> hull;
int n,m,i,j,k,t,t1,u,v,a,b;
vector<int> buc[2];
int x[1001],y[1001],c[1001];
int cw(int a, int b, int c) {
	return (((x[b]-x[a])*(y[c]-y[b])-(y[b]-y[a])*(x[c]-x[b]))<0);
}
int tri(int a, int b, int c, int x) {
	// cout<<"tri "<<a<<' '<<b<<' '<<c<<' '<<x<<endl;
	int u=cw(x,a,b);
	int v=cw(x,b,c);
	int w=cw(x,c,a);
	// cout<<u<<' '<<v<<' '<<w<<endl;
	return (u==v && v==w);
}
void solve(int pa, int pb, int pd) {
	// cout<<"solve "<<pa<<' '<<pb<<' '<<pd<<endl;
	int i,j,k,t,t1,u,v,a,b;
	vector<int> sus;
	for (i=0;i<n;i++) if (i-pa && i-pb && i-pd && tri(pa,pb,pd,i)) {
		sus.push_back(i);
		// cout<<"sus "<<i<<endl;
	}
	if (sus.size()==0) return;
	for (i=0;i<sus.size();i++) if (c[sus[i]]==c[pd]) break;
	if (i<sus.size()) {
		cout<<sus[i]<<' '<<pd<<endl;
		solve(sus[i],pd,pa);
		solve(sus[i],pd,pb);
		solve(pa,pb,sus[i]);
	}
	else {
		sus.push_back(pa);
		sort(sus.begin(),sus.end(),[](int a, int b){
			return (x[a]<x[b]);
		});
		for (i=1;i<sus.size();i++) {
			cout<<sus[i-1]<<' '<<sus[i]<<endl;
		}
	}
}
int main()
{
	fio;
	cin>>n;
	for (i=0;i<n;i++) {
		cin>>x[i]>>y[i]>>c[i];
		buc[c[i]].push_back(i);
		vec.push_back(i);
	}
	if (buc[0].size()==0) {
		sort(buc[1].begin(),buc[1].end(),[](int a, int b){
			return (x[a]<x[b]);
		});
		cout<<n-1<<endl;
		for (i=1;i<n;i++) {
			cout<<buc[1][i-1]<<' '<<buc[1][i]<<endl;
		}
	}
	else if (buc[1].size()==0) {
		sort(buc[0].begin(),buc[0].end(),[](int a, int b){
			return (x[a]<x[b]);
		});
		cout<<n-1<<endl;
		for (i=1;i<n;i++) {
			cout<<buc[0][i-1]<<' '<<buc[0][i]<<endl;
		}
	}
	else {
		sort(vec.begin(),vec.end(),[](int a, int b){
			if (x[a]-x[b]) return (x[a]<x[b]);
			return (y[a]<y[b]);
		});
		u=vec[0];
		sort(vec.begin()+1,vec.end(),[](int a, int b){
			return cw(u,a,b);
		});
		if (vec.size()==2) {
			cout<<0;
			return 0;
		}
		hull.push_back(u);
		hull.push_back(vec[1]);
		for (i=2;i<n;i++) {
			while(!cw(hull[hull.size()-2],hull[hull.size()-1],vec[i])) hull.pop_back();
			hull.push_back(vec[i]);
		}
		a=0;
		m=hull.size();
		for (i=0;i<m;i++) {
			a+=(c[hull[i]])^(c[hull[(i+1)%m]]);
		}	
		if (a>2) {
			cout<<"Impossible";
			return 0;
		}
		cout<<n-2<<endl;
		if (a==0) {
			for (i=1;i<m;i++) {
				cout<<hull[i-1]<<' '<<hull[i]<<endl;
			}
			for (j=0;j<n;j++) if (c[j]!=c[hull[0]]) break;
			for (i=0;i<m;i++) {
				solve(hull[i],hull[(i+1)%m],j);
			}
		}
		else {
			// cout<<"hull\n";
			// for (auto g : hull) cout<<g<<' ';
			// cout<<endl;
			a=-1;
			b=-1;
			for (i=0;i<m;i++) if (c[hull[i]]==c[hull[(i+1)%m]]) {
				cout<<hull[i]<<' '<<hull[(i+1)%m]<<endl;
			}
			else {
				if (a==-1) a=i;
				else b=i;
			}
			for (i=(a+1)%m;i!=b;i=(i+1)%m) {
				solve(hull[i],hull[(i+1)%m],hull[a]);
			}
			for (i=(b+1)%m;i!=a;i=(i+1)%m) {
				solve(hull[i],hull[(i+1)%m],hull[b]);
			}
		}
	}
}
// N;