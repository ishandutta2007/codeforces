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
const vector<vector<ll>> vecA= {
	{1,0,1000000000},
	{1000000000,0,1},
	{1000000000,1000000000,0}
};

const vector<vector<ll>> vecB= {
	{0,1,1000000000},
	{1000000000,1,0},
	{1000000000,1000000000,0}
};


const vector<vector<ll>> vecC= {
	{0,1,1000000000},
	{1000000000,0,1},
	{1000000000,1000000000,1}
};


const vector<vector<ll>> vecD= {
	{1000000000,1000000000,1000000000},
	{1000000000,1000000000,1000000000},
	{1000000000,1000000000,1000000000}
};

char star[100001];

struct seg
{
    vector<vector<ll>> val[270000];

    void reset(ll c, ll l, ll r)
    {
        if (l<r)
        {
            ll mid=(l+r)/2;
            reset((c<<1),l,mid);
            reset((c<<1)+1,mid+1,r);
            val[c]=vecD;
            for (int i=0;i<3;i++) for (int j=0;j<3;j++) for (int k=0;k<3;k++) {
            	val[c][i][j]=min(val[c][i][j],val[c<<1][i][k]+val[(c<<1)+1][k][j]);
            }
        }
        else {
        	if (star[l]=='a') val[c]=vecA;
        	if (star[l]=='b') val[c]=vecB;
        	if (star[l]=='c') val[c]=vecC;
        }
    }
    void upd(ll c, ll l, ll r, ll x, char t)
    {
        if ((l<=x)and(x<=r))
        {
            if (l==r) {
            	if (t=='a') val[c]=vecA;
            	if (t=='b') val[c]=vecB;
            	if (t=='c') val[c]=vecC;
            }
            else
            {
                ll mid=(l+r)/2;
                upd((c<<1),l,mid,x,t);
                upd((c<<1)+1,mid+1,r,x,t);
	            val[c]=vecD;
	            for (int i=0;i<3;i++) for (int j=0;j<3;j++) for (int k=0;k<3;k++) {
	            	val[c][i][j]=min(val[c][i][j],val[c<<1][i][k]+val[(c<<1)+1][k][j]);
	            }
            }
        }
    }
};
seg st;

vector<int> sus;
ll n,m,i,j,k,t,t1,u,v,a,b,c;
ll pr[1000001];
ll arr[1000001];
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++) {
		cin>>star[i];
	}
	st.reset(1,1,n);
	for (i=1;i<=m;i++) {
		char ch;
		cin>>u>>ch;
		st.upd(1,1,n,u,ch);
		a=1e9;
		a=min(a,st.val[1][0][0]);
		a=min(a,st.val[1][0][1]);
		a=min(a,st.val[1][0][2]);
		cout<<a<<endl;
	}
}