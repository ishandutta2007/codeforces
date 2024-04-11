#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.4
	Changes:
    Added include-guards to help with writing in multiple source files.
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
ll sta[200001];

// A list of preset merge functions.
ll cmpg(ll a, ll b){if (a>b) return a; else return b;}
ll cmpl(ll a, ll b){if (a>b) return b; else return a;}
ll sum(ll a, ll b){return (a+b);}
ll summ(ll a, ll b){return (a+b)%MOD;}
ll prod(ll a, ll b){return (a*b);}
ll prodm(ll a, ll b){return (a%MOD*b)%MOD;}

//The segement tree itself.
struct seg
{
    ll val[800001];
    ll def=0;
    ll (*merg)(ll,ll); // Merge function. It must be associative.
    void reset(ll c, ll l, ll r)
    {
        if (l<r)
        {
            ll mid=(l+r)/2;
            reset((c<<1),l,mid);
            reset((c<<1)+1,mid+1,r);
            val[c]=merg(val[(c<<1)],val[(c<<1)+1]);
        }
        else val[c]=sta[l];
    }
    void upd(ll c, ll l, ll r, ll x, ll t)
    {
        if ((l<=x)and(x<=r))
        {
            if (l==r) val[c]=t;
            else
            {
                ll mid=(l+r)/2;
                upd((c<<1),l,mid,x,t);
                upd((c<<1)+1,mid+1,r,x,t);
                val[c]=merg(val[(c<<1)],val[(c<<1)+1]);
            }
        }
    }
    ll get(ll c, ll l, ll r, ll tl, ll tr)
    {
        if ((tl>r)or(tr<l)) return def;
        if ((tl<=l)and(tr>=r)) return val[c];
        else 
        {
            ll mid=(l+r)/2;
            ll a=get((c<<1),l,mid,tl,tr);
            ll b=get((c<<1)+1,mid+1,r,tl,tr);
            return merg(a,b);
        }
    }
};
seg stminl,stmaxl,stminr,stmaxr;

vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
int kk[100001],al[100001],bl[100001],ar[100001],br[100001];
int latest[2],bound[2],latest_tmp[2];
int dp[100001][2];
int main()
{
	fio;
    stminl.merg=cmpg; stminl.def=-1;
    stmaxl.merg=cmpl; stmaxl.def=1e9;
    stminr.merg=cmpg; stminr.def=-1;
    stmaxr.merg=cmpl; stmaxr.def=1e9;
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>kk[i]>>al[i]>>bl[i]>>ar[i]>>br[i];
    }
    for (i=1;i<=n;i++) sta[i]=al[i]; stminl.reset(1,1,n);
    for (i=1;i<=n;i++) sta[i]=ar[i]; stminr.reset(1,1,n);
    for (i=1;i<=n;i++) sta[i]=bl[i]; stmaxl.reset(1,1,n);
    for (i=1;i<=n;i++) sta[i]=br[i]; stmaxr.reset(1,1,n);
    latest[0]=n;
    latest[1]=n;
    bound[0]=n;
    bound[1]=n;
    for (i=n-1;i>=0;i--)
    {
        memcpy(latest_tmp,latest,sizeof(latest));
        if ((kk[i+1]<ar[i+1])or(kk[i+1]>br[i+1])) bound[1]=i;
        if (i==0) u=0; else u=kk[i];
        a=stminl.get(1,1,n,i+1,latest[1]);
        b=stmaxl.get(1,1,n,i+1,latest[1]);
     //   cout<<"test 0 "<<a<<' '<<b<<' '<<u<<' '<<latest[1]<<' '<<bound[1]<<endl;
        if ((a<=u)and(u<=b)and(bound[1]>=latest[1])) {latest_tmp[0]=i; dp[i][0]=latest[1];} else dp[i][0]=-1;


        if ((kk[i+1]<al[i+1])or(kk[i+1]>bl[i+1])) bound[0]=i;
        if (i==0) u=0; else u=kk[i];
        a=stminr.get(1,1,n,i+1,latest[0]);
        b=stmaxr.get(1,1,n,i+1,latest[0]);
       // cout<<"test 1 "<<a<<' '<<b<<' '<<u<<' '<<latest[0]<<' '<<bound[0]<<endl;
        if ((a<=u)and(u<=b)and(bound[0]>=latest[0])) {latest_tmp[1]=i; dp[i][1]=latest[0];} else dp[i][1]=-1;
        memcpy(latest,latest_tmp,sizeof(latest));
       // cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<endl;
    }
    if (dp[0][0]>=0)
    {
        cout<<"Yes\n";
        i=0;
        j=0;
        while(i<n)
        {
            for (k=i;k<dp[i][j];k++) cout<<1-j<<' ';
            i=dp[i][j];
            j=1-j;
        }
    }
    else if (dp[0][1]>=0)
    {
        cout<<"Yes\n";
        i=0;
        j=1;
        while(i<n)
        {
            for (k=i;k<dp[i][j];k++) cout<<1-j<<' ';
            i=dp[i][j];
            j=1-j;
        }
    }
    else cout<<"No";
}