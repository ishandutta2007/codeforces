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

namespace CPL_NTT
{
	ll Mod=0;
	ll Root=0;
	ll Level=0;
	vector<ll> roots;
	ll inv2;
	ll bow(ll a, ll x, ll p) // exponentation by squaring
	{
		if (!x) return 1;
		ll res=bow(a,x/2,p);
		res*=res;
		res%=Mod;
		if (x%2) res*=a;
		return res%Mod;
	}
	void generate() // Generate roots of unity
	{
		roots.clear();
		ll u=1;
		for (ll i=0;i<Level;i++) 
		{
			roots.push_back(u);
			u*=Root;
			u%=Mod;
		}
		inv2=bow(2,Mod-2,Mod);
	}
	vector<ll> transform(const vector<ll>& vec, int inv) //Fourier ttransform
	{
		if (vec.size()==1) return {vec[0]};
		ll coeff=Level/vec.size(),lvl=log2(vec.size());
		vector<ll> res;
        for (ll i=0;i<vec.size();i++) // Building reverse-bit permutation of original array
        {
            ll u=0;
            for (ll j=0;j<lvl;j++) u^=(((i&(1<<j))>>j)<<(lvl-1-j));
            res.push_back(vec[u]);
        }
        for (ll t=0;t<lvl;t++)
        {
            coeff=Level/(1<<(t+1));
        for (ll i=0;i<vec.size();i+=(1<<(t+1)))
        {   // Apply merge for this segment
            for (ll j=0;j<(1<<t);j++)
            {
                ll a=res[i+j];
                ll b=res[i+j+(1<<t)];
                if (!inv)
                {
                res[i+j]=(a+roots[coeff*j]*b)%Mod;
                res[i+j+(1<<t)]=((a-roots[coeff*j]*b)%Mod+Mod)%Mod;
                }
                else
                {
                res[i+j]=(a+roots[(Level-coeff*j)%Level]*b)%Mod;
                res[i+j+(1<<t)]=((a-roots[(Level-coeff*j)%Level]*b)%Mod+Mod)%Mod;
                }
            }
        }
        }
		if (inv)
		{
            ll mul=bow(inv2,lvl,Mod);
			for (ll i=0;i<res.size();i++) res[i]=(res[i]*(mul))%Mod;
		}
		return res;
	}
	vector<ll> multiply(vector<ll> a, vector<ll> b) // Actual multiplication
	{
		ll u=1;
		while((u<a.size())or(u<b.size())) u*=2;
		u*=2;
		while(a.size()<u) a.push_back(0);
		while(b.size()<u) b.push_back(0);
		//for (auto g : a) cout<<g<<' '; cout<<endl;
		//for (auto g : b) cout<<g<<' '; cout<<endl;
		vector<ll> ra=transform(a,0),rb=transform(b,0);
		for (ll i=0;i<u;i++)
		{
		//	cout<<i<<' '<<ra[i]<<' '<<rb[i]<<endl;
			ra[i]=((ra[i]*rb[i])%Mod);
		}
		vector<ll> res=transform(ra,1);
		return res;
	}
};
using namespace CPL_NTT;

vector<int> vec;
vector<ll> va, vb, vc;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll cl,cr;
ll arr[100001];
ll pw2[100001];
ll pen[100001];
int node[100001];
ll res=0;
ll sum[100001];
void solve(int l, int r) {
	if (l==r) return;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	ll partial=0;
	a=0;
	b=0;
	cl=0;
	for (i=mid;i>=l;i--) {
		sum[i]=a;
		b+=arr[i];
		b%=MOD;
		a+=b;
		a%=MOD;
		if (node[i]) cl++;
	}
	a=0;
	b=0;
	cr=0;
	for (i=mid+1;i<=r;i++) {
		sum[i]=a;
		b+=arr[i];
		b%=MOD;
		a+=b;
		a%=MOD;
		if (node[i]) cr++;
	}
	cl=(pw2[cl]+MOD-1)%MOD;
	cr=(pw2[cr]+MOD-1)%MOD;

	va.clear();
	vb.clear();
	u=0;
	for (i=l;i<=mid;i++) if (node[i]) {
		u++;
		// cout<<"sum "<<i<<' '<<sum[i]<<endl;
		partial+=pw2[u-1]*sum[i]%MOD*cr%MOD;
		partial%=MOD;
		va.push_back(pw2[u-1]);
	}
	else va.push_back(0);
	u=0;
	for (i=r;i>=mid+1;i--) if (node[i]) {
		u++;
		// cout<<"sum "<<i<<' '<<sum[i]<<endl;
		partial+=pw2[u-1]*sum[i]%MOD*cl%MOD;
		partial%=MOD;
		vb.push_back(pw2[u-1]);
	}
	else vb.push_back(0);
	reverse(vb.begin(),vb.end());

	// cout<<"pre-merge "<<l<<' '<<r<<' '<<partial<<endl;
	vc=multiply(va,vb);
	// cout<<"merge "<<l<<' '<<mid<<' '<<r<<endl;
	// for (auto g : va) cout<<g<<' '; cout<<endl;
	// for (auto g : vb) cout<<g<<' '; cout<<endl;
	// for (auto g : vc) cout<<g<<' '; cout<<endl;
	a=0;
	b=0;
	for (i=0;i<mid-l+1;i++) {
		if (i && ((i&1)==0)) {
			b+=arr[mid+1-i/2];
			b%=MOD;
		}
		a+=b;
		a%=MOD;
		u=vc[mid-l-i]*a; u%=MOD;
		partial+=MOD-u; partial%=MOD;
	}
	a=0;
	b=0;
	for (i=0;i<r-mid;i++) {
		if (i && ((i&1)==0)) {
			b+=arr[mid+i/2];
			b%=MOD;
		}
		a+=b;
		a%=MOD;
		u=vc[mid-l+i]*a; u%=MOD;
		partial+=MOD-u; partial%=MOD;
	}
	// cout<<"solve "<<l<<' '<<r<<' '<<partial<<endl;
	cl=m;
	for (i=l;i<=r;i++) if (node[i]) cl--;
	res+=partial*pw2[cl];
	res%=MOD; 
}
int main()
{


	Mod=998244353;
	Root=bow(3,119,Mod);
	Level=(1<<23);
	generate();

	fio;
	cin>>n>>m;
	pw2[0]=1;
	for (i=1;i<=n;i++) {
		pw2[i]=pw2[i-1]*2;
		pw2[i]%=MOD;
	}
	for (i=1;i<=n;i++) {
		cin>>arr[i];
	}
	for (i=1;i<=n;i++) {
		cin>>u;
		node[u]=1;
	}
	solve(1,n);

	a=0;
	b=0;
	u=m;
	for (i=n;i>=1;i--) {
		if (node[i]) {
			u--;
			// cout<<i<<' '<<a<<' '<<u<<' '<<pw2[u]<<endl;
			res+=a*pw2[u];
			res%=MOD;
		}
		b+=arr[i]; b%=MOD;
		a+=b; a%=MOD;
	}



	a=0;
	b=0;
	u=m;
	for (i=1;i<=n;i++) {
		if (node[i]) {
			u--;
			// cout<<i<<' '<<a<<' '<<u<<' '<<pw2[u]<<endl;
			res+=a*pw2[u];
			res%=MOD;
		}
		b+=arr[i]; b%=MOD;
		a+=b; a%=MOD;
	}
	// cout<<res<<endl;
	res*=INV((pw2[m]+MOD-1)%MOD,MOD); res%=MOD;
	cout<<res;
}
// a;