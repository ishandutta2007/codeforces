/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
#include <numeric>
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
vector<ll> vec;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll ar[200001],br[200001],cr[200001],dr[200001];
ll ln[200001],rn[200001];
vector<pii(ll)> gt[400001];
vector<ll> buc[400001];
ll used[400001],done[400001];
map<pii(ll),ll> whyy;
void dfs(int x, int p, int d)
{
    used[x]=1;
    for (auto g : gt[x]) if (g!=pii(ll)(p,d))
    {
        if (used[g.fi])
        {
            if (!done[g.se])
            {
                done[g.se]=1;
                buc[x].push_back(g.se);
            }
        }
        else
        {
            dfs(g.fi,x,g.se);
        }
    }
    if (d!=-1)
    {
        if (buc[x].size()%2) buc[x].push_back(d);
        else buc[p].push_back(d);
    }
}
int main()
{
	fio;
    cin>>n;
    for (i=1;i<=n;i++) 
    {
        cin>>ar[i]>>br[i]>>cr[i]>>dr[i];


        u=(ar[i]+br[i])*dr[i];
        v=(cr[i])*br[i];
        a=gcd(u,v);
        u/=a;
        v/=a;
        if (!whyy[{u,v}]) 
        {
            t++;
            whyy[{u,v}]=t;
        }
        ln[i]=whyy[{u,v}];


        u=(ar[i])*dr[i];
        v=(cr[i]+dr[i])*br[i];
        a=gcd(u,v);
        u/=a;
        v/=a;
        if (!whyy[{u,v}]) 
        {
            t++;
            whyy[{u,v}]=t;
        }
        rn[i]=whyy[{u,v}];
        gt[ln[i]].push_back({rn[i],i});
        gt[rn[i]].push_back({ln[i],i});
    }
    for (i=1;i<=t;i++) if (!used[i])
    {
        dfs(i,-1,-1);
    }
    a=0;
    for (i=1;i<=t;i++)
    a+=buc[i].size()/2;
    cout<<a<<endl;
    for (i=1;i<=t;i++)
    {
        for (j=1;j<buc[i].size();j+=2) cout<<buc[i][j-1]<<' '<<buc[i][j]<<endl;
    }
}