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
vector<pii(ll)> gt[100001];
ll n,m,i,j,k,t,t1,u,v,a,b;
ll dis[100001];
vector<ll> bans[100001];
struct cmp
{
    int operator()(pii(ll) a, pii(ll) b)
    {
        if (a.se-b.se) return (a.se>b.se);
        return (a.fi<b.fi);
    }
};
priority_queue<pii(ll),vector<pii(ll)>,cmp> pq;
int main()
{
	fio;
    cin>>n>>m;
    for (i=0;i<m;i++)
    {
        cin>>u>>v>>a;
        gt[u].push_back({v,a});
        gt[v].push_back({u,a});
    }
    for (i=1;i<=n;i++)
    {
        cin>>t;
        a=-1;
        b=-1;
        for (t1=0;t1<t;t1++)
        {
            cin>>u;
            if (a==-1) a=b=u;
            else if (u>b+1) {bans[i].push_back(a); bans[i].push_back(b+1);}
            else b=u;
        }
        {bans[i].push_back(a); bans[i].push_back(b+1);}
    //    cout<<i;
    //    for (auto g : bans[i]) cout<<' '<<g; cout<<endl;
    }
    for (i=1;i<=n;i++) dis[i]=1e18;
    if (bans[1][0]!=0)
    {
    dis[1]=0;
    pq.push({1,0});
    }
    else
    {
        dis[1]=bans[1][1];
        pq.push({1,bans[1][1]});
    }
    while(pq.size())
    {
        auto pp=pq.top(); pq.pop();
        if (pp.se-dis[pp.fi]) continue;
        for (auto g : gt[pp.fi])
        {
            u=pp.se+g.se;
            if (g.fi!=n)
            {
            auto it=upper_bound(bans[g.fi].begin(),bans[g.fi].end(),u)-bans[g.fi].begin()-1;
            if (it%2==0) u=bans[g.fi][it+1];
            }
            if (dis[g.fi]>u)
            {
                dis[g.fi]=u;
                pq.push({g.fi,u});
            }
        }
    }
    if (dis[n]==1e18) cout<<-1; else cout<<dis[n];
}