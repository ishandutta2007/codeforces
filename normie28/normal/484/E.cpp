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

struct seg {
	int val[262150];
	void reset(int c, int l, int r) {
		if (l==r) val[c]=0;
		else {
			int mid=(l+r)/2;
			reset((c<<1),l,mid);
			reset((c<<1)+1,mid+1,r);
			val[c]=0;
		}
	}
	void upd(int c, int l, int r, int t, int x) {
		if (l<=t && t<=r) {
			if (l==r) {
				// cout<<"updt "<<c<<' '<<x<<endl;
				val[c]=x;
			}
			else {
				int mid=(l+r)/2;
				upd((c<<1),l,mid,t,x);
				upd((c<<1)+1,mid+1,r,t,x);
				val[c]=max(val[(c<<1)],val[(c<<1)+1]);
			}
		}
	}
	int get(int c, int l, int r, int tl, int tr) {
		if (tl>tr) return 0;
		if (l>tr || r<tl) return 0;
		if (l>=tl && r<=tr) return val[c];
		else {
			int mid=(l+r)/2;
			int b=get((c<<1),l,mid,tl,tr);
			int a=get((c<<1)+1,mid+1,r,tl,tr);
			return max(a,b);
		}
	}
};
seg st;
set<int> lmao;

vector<int> ord;
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
set<int> set; 
int ql[100001],qr[100001],qw[100001],qa[100001];
int h[100001];

void proc(int l, int r, vector<int> cur) {
	// cout<<"proc "<<l<<' '<<r<<' '<<endl;
	if (r==l+1) {
		for (auto g : cur) qa[g]=h[ord[l]];
		return;
	}
	int mid=(l+r)/2,i,j,k,u,v,a,b;
	vector<int> vl,vr;
	
	for (i=l;i<mid;i++) {
		auto it = lmao.lower_bound(ord[i]);
		it--;
		u=(*it);
		it++; it++; 
		v=(*it);
		it--;
		lmao.erase(it);
		// cout<<"upd "<<u+1<<' '<<v-u-1<<endl;
		// cout<<"upd "<<ord[i]+1<<' '<<0<<endl;
		st.upd(1,1,n,u+1,v-u-1);
		st.upd(1,1,n,ord[i]+1,0);
	}

	// cout<<"proc "<<l<<' '<<r<<' '<<endl;
	// for (auto g : lmao) cout<<g<<' '; cout<<endl;
	for (auto g : cur) {
		auto it = lmao.lower_bound(ql[g]);
		u=(*it);
		it=lmao.upper_bound(qr[g]);
		it--;
		v=(*it);
		a=0;
		a=max(a,u-ql[g]);
		a=max(a,qr[g]-v);
		if (u>qr[g]) a=max(a,qr[g]-ql[g]+1);
		b=st.get(1,1,n,u,v);
		
		// cout<<g<<' '<<u<<' '<<v<<' '<<b<<endl;

		a=max(a,b);
		if (a>=qw[g]) vl.push_back(g); else vr.push_back(g);
	}

	// cout<<"proc "<<l<<' '<<r<<' '<<endl;
	proc(mid,r,vr);

	
	for (i=l;i<mid;i++) {
		auto it = lmao.insert(ord[i]).fi;
		it--;
		u=(*it);
		it++; it++; 
		v=(*it);
		st.upd(1,1,n,u+1,ord[i]-u-1);
		st.upd(1,1,n,ord[i]+1,v-ord[i]-1);
	}

	
	proc(l,mid,vl);
}

int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++) {cin>>h[i]; ord.push_back(i);}
	cin>>m;
	for (i=1;i<=m;i++) {
		cin>>ql[i]>>qr[i]>>qw[i];
		vec.push_back(i);
	}
	sort(ord.begin(), ord.end(), [](int a, int b){
		return (h[a]>h[b]);
	});
	lmao.insert(0);
	lmao.insert(n+1);
	st.reset(1,1,n);
	for (i=1;i<=n;i++) {
		lmao.insert(i);
	}
	proc(0,n,vec);
	for (i=1;i<=m;i++) cout<<qa[i]<<endl;
}