/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
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
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
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
#define MOD (ll(1000000007))
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
vector<pii(ll)> vec;
ll n,m,i,j,k,t,t1,u,v,a,b,c,d;
ll dp[2011][23];
ll fac[200001];
ll inv[200001];
int main()
{
	fio;
    vec.clear();
    cin>>n>>m>>k>>t;
    for (i=1;i<=k;i++)
    {
        cin>>u>>v;
        if ((u==1)and(v==1)) d++;
        else if ((u==n)and(v==m)) d++;
        else vec.push_back({u,v});
    }
    fac[0]=1;
    inv[0]=1;
    for (i=1;i<=200000;i++)
    {
        fac[i]=(fac[i-1]*i)%MOD;
        inv[i]=INV(fac[i],MOD);
    }
    vec.push_back({n,m});
    sort(vec.begin(),vec.end(),[](pii(ll) a, pii(ll) b){
        return (a.fi+a.se)<(b.fi+b.se);
    });
    for (i=0;i<vec.size();i++) for (j=0;j<23;j++)
    {
        u=fac[vec[i].fi-1+vec[i].se-1];
        u*=inv[vec[i].fi-1]; u%=MOD;
        u*=inv[vec[i].se-1]; u%=MOD;
        for (int l=0;l<j;l++)
        {
            u-=dp[i][l];
            u+=MOD;
            u%=MOD;
        }
        for (int l=0;l<i;l++) if ((vec[l].fi<=vec[i].fi)and(vec[l].se<=vec[i].se))
        {

            v=fac[vec[i].fi-vec[l].fi+vec[i].se-vec[l].se];
            v*=inv[vec[i].fi-vec[l].fi]; v%=MOD;
            v*=inv[vec[i].se-vec[l].se]; v%=MOD;
            u-=dp[l][j]*v%MOD;
            u+=MOD;
            u%=MOD;
        }
        dp[i][j]=u;
//        cout<<i<<' '<<vec[i].fi<<' '<<vec[i].se<<' '<<j<<' '<<dp[i][j]<<endl;
    }
    ll res=0;
        u=fac[n-1+m-1];
        u*=inv[n-1]; u%=MOD;
        u*=inv[m-1]; u%=MOD;
    for (i=0;i<23;i++)
    {
        if (i>=d)
        {
            res+=dp[vec.size()-1][i-d]*t;
            u-=dp[vec.size()-1][i-d];
            u+=MOD;
            res%=MOD;
            u%=MOD;
        }
        t=ceil(ld(t)/2);
    }
    res+=u;
    res%=MOD;
        u=fac[n-1+m-1];
        u*=inv[n-1]; u%=MOD;
        u*=inv[m-1]; u%=MOD;
    res*=INV(u,MOD);
    res%=MOD;
    cout<<res;
}