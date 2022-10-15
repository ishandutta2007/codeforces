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
// #include <atcoder/convolution>
// using namespace atcoder;

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
ll n,m,i,j,k,t,t1,u,v,a,b;
ll arr[100001];
ll brr[100001];
vector<ld> lx[2000001];
vector<ld> ly[2000001];
vector<ll> cx,cy;
vector<ll> tta,ttb;
ld res,ra,rb,rc;
ll la,lb,lc;
int main()
{
	fio;
	cin>>n;
	for (i=0;i<n;i++) {
		cin>>arr[i]>>brr[i];
		arr[i]+=1e6;
		brr[i]+=1e6;
	}
	for (j=0;j<n;j++) {
		a=arr[j];
		b=brr[j];
		u=arr[(j+1)%n];
		v=brr[(j+1)%n];
		if (a>u) {swap(a,u); swap(b,v);}
		if (a==u) {
			lx[a].push_back(b);
			lx[a].push_back(v);
		} else {
			for (i=a;i<=u;i++) {
				// cout<<"x "<<i<<endl;
				lx[i].push_back(ld(b)+ld(v-b)/(u-a)*(i-a));
			}
		}
	}
	for (i=0;i<=2e6;i++) if (lx[i].size()) {
		ld l=2e6,r=0;
		for (auto g : lx[i]) {
			l=min(l,g);
			r=max(r,g);
		}
		u=ceil(l);
		v=floor(r);
		// cout<<u<<' '<<v<<endl;
		if (v-u+1) {
			cx.push_back(v-u+1);
		}
		lx[i].clear();
	}
	


	u=0;
	la=0;
	for (auto g : cx) {la+=g; } 
	// for (auto g : cx) { cout<<g<<' ';} cout<<endl;
	// for (auto g : cy) { cout<<g<<' ';} cout<<endl;

	for (i=0;i<cx.size();i++) {
		res+=(ld)cx[i]*i*i*(la-1);
	}
	u=0;
	for (i=0;i<cx.size();i++) {
		u+=i*cx[i];
	}
	for (i=0;i<cx.size();i++) {
		res-=(ld)cx[i]*i*(u-i);
	}
	// cout<<u<<endl;

	cx.clear();



	for (j=0;j<n;j++) {
		a=arr[j];
		b=brr[j];
		u=arr[(j+1)%n];
		v=brr[(j+1)%n];
		if (b>v) {swap(a,u); swap(b,v);}
		if (b==v) {
			ly[b].push_back(a);
			ly[b].push_back(u);
		} else {
			for (i=b;i<=v;i++) {
				// cout<<"y "<<i<<endl;
				ly[i].push_back(ld(a)+ld(u-a)/(v-b)*(i-b));
			}
		}
	}


	for (i=0;i<=2e6;i++) if (ly[i].size()) {
		ld l=2e6,r=0;
		for (auto g : ly[i]) {
			l=min(l,g);
			r=max(r,g);
		}
		u=ceil(l);
		v=floor(r);
		// cout<<u<<' '<<v<<endl;
		if (v-u+1) {
			cy.push_back(v-u+1);
		}
		ly[i].clear();
	}

	for (i=0;i<cy.size();i++) {
		res+=(ld)cy[i]*i*i*(la-1);
	}
	u=0;
	for (i=0;i<cy.size();i++) {
		u+=i*cy[i];
	}
	for (i=0;i<cy.size();i++) {
		res-=(ld)cy[i]*i*(u-i);
	}

	cy.clear();
	// cout<<res<<' '<<la<<endl;
	ra=(ld)la*(la-1);
	// cout<<res<<' '<<la<<endl;
	cout<<fixed<<setprecision(9)<<res/ra;	
}
// N;