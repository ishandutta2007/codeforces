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
unordered_map<int,vector<int>> lulmp;
vector<vector<int>> lul;
int n,m,i,j,k,t,t1,u,v,a,b;
int arr[1001];
int halt=0;
void tri(int x, int mk, int sum) {
	if (halt) return;
	if (x==t) {
		if (__builtin_popcount(mk)==m) {
			lulmp[sum].push_back(mk);
			if (lulmp[sum].size()>=2) halt=1;
			// cout<<mk<<' '<<sum<<endl;
		} 
	}
	else {
		tri(x+1,mk,sum);
		if (halt) return;
		if (__builtin_popcount(mk)<m) {
			tri(x+1,mk^(1<<x),sum+arr[x+1]);
		}
		if (halt) return;
	}
} 
vector<int> vecu,vecv;
int done[1001];
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++) cin>>arr[i]; 
	if (n==2) {
		if (arr[1]==arr[2]) {
			cout<<"YES\n";
			cout<<0<<' '<<arr[1];
		} else {
			cout<<"NO";
		}
	} else if (n==3) {
		if (arr[1]==arr[2]) {
			cout<<"YES\n";
			cout<<0<<' '<<arr[1]<<' '<<arr[3];
		} else if (arr[2]==arr[3]) {
			cout<<"YES\n";
			cout<<0<<' '<<arr[2]<<' '<<arr[1];
		} else if (arr[3]==arr[1]) {
			cout<<"YES\n";
			cout<<0<<' '<<arr[1]<<' '<<arr[2];
		} else if ((arr[1]+arr[2]+arr[3])%2==0) {
			cout<<"YES\n";
			u=(arr[1]+arr[2]+arr[3])/2;
			cout<<u-arr[1]<<' '<<u-arr[2]<<' '<<u-arr[3];
		} else {
			cout<<"NO";
		}
	} else {
		for (i=1;i<=n;i++) if (arr[i]%2==0) break;
		if (i<=n) {
			for (j=1;j<=n;j++) {for (k=1;k<=n;k++) if (i-j && j-k && i-k && (arr[i]+arr[j]+arr[k])%2==0) break; if (k<=n) break;}
			u=(arr[i]+arr[j]+arr[k])/2;
			cout<<"YES\n";
			cout<<u-arr[i]<<' '<<u-arr[j]<<' '<<u-arr[k];
			for (t=1;t<=n;t++) if (t-i && t-j && t-k) {
				cout<<' '<<arr[t]-(u-arr[i]);
			}
		}
		else {
			m=min(13,n/2);
			t=min(26,n);
			{
				tri(0,0,0);
				if (!halt) {
					cout<<"NO";
				} else {
					for (auto g : lulmp) if (g.se.size()>=2) {
						u=g.se[0];
						v=g.se[1];
						break;
					}
					a=u&v;
					u^=a;
					v^=a;
					// cout<<u<<' '<<v<<endl;
					for (i=0;i<t;i++) {
						if (u&(1<<i)) {vecu.push_back(i+1); done[i+1]=1;}
						if (v&(1<<i)) {vecv.push_back(i+1); done[i+1]=1;}
					}
					a=0;
					cout<<"YES\n";
					for (i=0;i<vecu.size();i++) {
						a=arr[vecu[i]]-a;
						cout<<' '<<a;
						a=arr[vecv[i]]-a;
						cout<<' '<<a;
					}
					for (i=1;i<=n;i++) if (!done[i]) cout<<' '<<arr[i];
				}
			} 
		}
	} 
}
// N;