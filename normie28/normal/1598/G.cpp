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
const ll p[2]={1962415409,1085071919};
vector<int> vec;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll hah[500001][2];
ll p10[500001][2];
ll i10[500001][2];
ll tar[2];
string s1,s2;
string s;
ll zarr[800001];
ll zl,zr;

ll get(ll l, ll r, ll k) {
	//  cout<<"get "<<l<<' '<<r<<' '<<k<<' '<<(hah[r][k]+p[k]-(hah[l][k]*p10[r-l][k])%p[k])%p[k]<<endl;
	return (hah[r][k]+p[k]-(hah[l][k]*p10[r-l][k])%p[k])%p[k];
}
void tri(ll a, ll b, ll c) {
	// cout<<"tri "<<a<<' '<<b<<' '<<c<<endl;	 
	if ((get(a,b,0)+get(b,c,0))%p[0]==tar[0] && (get(a,b,1)+get(b,c,1))%p[1]==tar[1])
	{
		cout<<a+1<<' '<<b<<endl<<b+1<<' '<<c;
		exit(0);
	}
}
int main()
{
	fio;
	cin>>s1>>s2;
	n=s1.length();
	m=s2.length();
	n=s1.length();
	m=s2.length();
	s=s2+"#"+s1;
	zl=zr=0;
	
	
	n+=m+1;
	for (i=1;i<n;i++) {
        if (i<=zr) {
            zarr[i]=min(zarr[i-zl],zr-i+1);
        }
		for (j=zarr[i]+1;j+i-1<n;j++) if (s[0+j-1]!=s[i+j-1]) break;
		j--;
		zarr[i]=j;
		if (i+zarr[i]-1>zr) {
			zl=i;
			zr=i+zarr[i]-1;
		}
 		// cout<<i<<' '<<zarr[i]<<endl;
    }
	n-=m+1;

	p10[0][1]=p10[0][0]=i10[0][0]=i10[0][1]=1;
	for (i=1;i<=n;i++) {
		p10[i][0]=p10[i-1][0]*10;
		p10[i][0]%=p[0];
		p10[i][1]=p10[i-1][1]*10;
		p10[i][1]%=p[1];
	}
	i10[n][0]=INV(p10[n][0],p[0]);
	i10[n][1]=INV(p10[n][1],p[1]);
	for (i=n-1;i>=1;i--) {
		i10[i][0]=i10[i+1][0]*10;
		i10[i+1][0]%=p[0];
		i10[i][1]=i10[i+1][1]*10;
		i10[i+1][1]%=p[1];
	}
	tar[0]=0;
	tar[1]=0;
	for (auto g : s2) {
		tar[0]*=10; 
		tar[0]+=g-48;
		tar[0]%=p[0];
		tar[1]*=10; 
		tar[1]+=g-48;
		tar[1]%=p[1];
	}
	hah[0][0]=0;
	hah[0][1]=0;
	for (i=1;i<=n;i++) {
		hah[i][0]=(hah[i-1][0]*10+s1[i-1]-48)%p[0];
		hah[i][1]=(hah[i-1][1]*10+s1[i-1]-48)%p[1];
	}
	for (i=0;i+m<=n;i++) {
		j=m-zarr[i+m+1];
		for (k=max(1,j-2);k<=min(m,j+2);k++) {
			if (i-k>=0) tri(i-k,i,i+m);
			if (i+m+k<=n) tri(i,i+m,i+m+k);
		}
	}
	if (m>=1)
	for (i=0;i+2*(m-1)<=n;i++) {
		tri(i,i+(m-1),i+2*(m-1));
	}
	if (m>=2) 
	for (i=0;i+(m-2)+(m-1)<=n;i++) {
		tri(i,i+(m-2),i+(m-2)+(m-1));
		tri(i,i+(m-1),i+(m-2)+(m-1));
	}
	
}