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

ll sta[300001];

// A list of preset merge functions.
ll cmpg(ll a, ll b){if (a>b) return a; else return b;}
ll cmpl(ll a, ll b){if (a>b) return b; else return a;}
ll sum(ll a, ll b){return (a+b);}
ll summ(ll a, ll b){return (a+b)%MOD;}
ll prod(ll a, ll b){return (a*b);}
ll prodm(ll a, ll b){return (a%MOD*b)%MOD;}
ll bAND(ll a, ll b){return (a&b);}
ll bOR(ll a, ll b){return (a|b);}
ll bXOR(ll a, ll b){return (a^b);}
//The segement tree itself.
struct seg
{
    ll val[1200001];
    ll def=0;
    ll (*merg)(ll,ll); // Merge function. It must be associative.
    ll why=0;
    void reset(int c, int l, int r)
    {
        if (l<r)
        {
            ll mid=(l+r)/2;
            reset((c<<1),l,mid);
            reset((c<<1)+1,mid+1,r);
            val[c]=(val[(c<<1)]+val[(c<<1)+1]);
        }
        else val[c]=sta[l];
    }
    void upd(int c, int l, int r, int x, ll t)
    {
        if ((l<=x)and(x<=r))
        {
            if (l==r) val[c]=t;
            else
            {
                int mid=(l+r)/2;
                upd((c<<1),l,mid,x,t);
                upd((c<<1)+1,mid+1,r,x,t);
                val[c]=(val[(c<<1)]+val[(c<<1)+1]);
            }
        }
    }
    void get(int c, int l, int r, int tl, int tr)
    {
        if ((tl>r)or(tr<l)) return;
        if ((tl<=l)and(tr>=r)) why+=val[c];
        else 
        {
            int mid=(l+r)/2;
            get((c<<1),l,mid,tl,tr);
            get((c<<1)+1,mid+1,r,tl,tr);
            
        }
    }
};


struct seg2
{
    ll val[1200001];
    ll def=0;
    ll (*merg)(ll,ll); // Merge function. It must be associative.
    void reset(int c, int l, int r)
    {
        if (l<r)
        {
            int mid=(l+r)/2;
            reset((c<<1),l,mid);
            reset((c<<1)+1,mid+1,r);
        }
        val[c]=0;
    }
    void upd(int c, int l, int r, int xl, int xr, ll t)
    {
        if ((r<xl)or(xr<l)) return;
        if ((l>=xl)and(r<=xr))
        {
            val[c]+=t;
        }
        else
        {
            int mid=(l+r)/2;
            upd((c<<1),l,mid,xl,xr,t);
            upd((c<<1)+1,mid+1,r,xl,xr,t);
        }
    }
    ll get(int c, int l, int r, ll t)
    {
    //    cout<<"get "<<c<<' '<<l<<' '<<r<<' '<<t<<endl;
        if ((t>r)or(t<l)) return def;
        else
        {
            ll a=val[c];
            int mid=(l+r)/2;
            if (l<r)
            {
                ll b=get((c<<1),l,mid,t);
                ll cc=get((c<<1)+1,mid+1,r,t);
                return a+b+cc;
            }
            else return a;
        }
    }
};

seg sts,stc;
seg2 st3;

vector<int> vec;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll arr[200001];
ll res[200001];
int main()
{
	fio;
    cin>>n;
    for (i=1;i<=n;i++) cin>>arr[i];
    sts.merg=stc.merg=st3.merg=sum;
    sts.reset(1,1,300000);
    stc.reset(1,1,300000);
    st3.reset(1,1,300000);
    for (i=1;i<=n;i++)
    {
        for (j=0;j*arr[i]<=300000;j++)
        {
            u=j*arr[i];
            v=u+arr[i];
            v--;
            v=min(v,300000);
            sts.why=0;
            sts.get(1,1,300000,u,v);
            stc.why=0;
            stc.get(1,1,300000,u,v);
            res[i]+=sts.why-stc.why*j*arr[i];
        }
        sts.upd(1,1,300000,arr[i],arr[i]);
        stc.upd(1,1,300000,arr[i],1);
    }
    
    for (i=n;i>=1;i--)
    {
        for (j=0;j*arr[i]<=300000;j++)
        {
            u=j*arr[i];
            v=u+arr[i];
            v--;
            v=min(v,300000);
            st3.upd(1,1,300000,u,v,j*arr[i]);
        }
        res[i]+=st3.get(1,1,300000,arr[i]);
    }
    
    for (i=n;i>=1;i--)
    {
        res[i]-=st3.get(1,1,300000,arr[i]);
        res[i]+=arr[i]*(i-1);
    }
    u=0;
    for (i=1;i<=n;i++)
    {
        u+=res[i];
        cout<<u<<' ';
    }
}