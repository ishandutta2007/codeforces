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
vector<ll> vec;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll eu[200001];
ll ev[200001];
ll ew[200001];
map<pii(ll),ll> ntoe;

struct cmp {
    int operator() (ll a, ll b) const {
        if (ew[a]-ew[b]) return (ew[a]<ew[b]); 
        return (a<b);
    }
};
////////////////////////////////

set<ll,cmp> inn[100001],l3[100001],rest[100001];
set<pii(ll)> sum;
map<ll,ll> cnt;
set<ll,cmp> whole;

ll res;

void add(ll e, ll v) {
    if (l3[v].size()==3) {
        ll summ=0;
        for (auto g : l3[v]) summ+=ew[g];
        sum.erase({summ,v}); 
    }


    l3[v].insert(e);
    cnt[e]++;
    if (cnt[e]==2) {
        inn[eu[e]].insert(e);
        inn[ev[e]].insert(e);
        whole.insert(e);
    }
    if (l3[v].size()>3) {
        auto it=l3[v].end();
        it--;
        auto bruh=(*it);
        l3[v].erase(bruh);
        rest[v].insert(bruh);
        cnt[bruh]--;
        if (cnt[bruh]==1) {
            inn[eu[bruh]].erase(bruh);
            inn[ev[bruh]].erase(bruh);
            whole.erase(bruh);
        }
    }


    if (l3[v].size()==3) {
        ll summ=0;
        for (auto g : l3[v]) summ+=ew[g];
        sum.insert({summ,v}); 
    }
}

void del(ll e, ll v) {
    // cout<<"del\n";
    // cout<<e<<' '<<v<<endl;
    if (l3[v].size()==3) {
        // cout<<"d\n";
        // for (auto g : l3[v]) cout<<g<<' '; cout<<endl;
        // for (auto g : rest[v]) cout<<g<<' '; cout<<endl;
        ll summ=0;
        for (auto g : l3[v]) summ+=ew[g];
        sum.erase({summ,v}); 
    }


    if (cnt[e]==2) {
        inn[eu[e]].erase(e);
        inn[ev[e]].erase(e);
        whole.erase(e);
    }

    auto it = rest[v].lower_bound(e);
    if (it != rest[v].end() && (*it)==e ) {
        rest[v].erase(e);
    } else {
        l3[v].erase(e);
        if (rest[v].size()) {
            auto bruh=(*(rest[v].begin()));
            rest[v].erase(bruh);
            l3[v].insert(bruh);
            cnt[bruh]++;
            if (cnt[bruh]==2) {
                inn[eu[bruh]].insert(bruh);
                inn[ev[bruh]].insert(bruh);
                whole.insert(bruh);
            }
        }
    }


    if (l3[v].size()==3) {
        // cout<<"a\n";
        // for (auto g : l3[v]) cout<<g<<' '; cout<<endl;
        ll summ=0;
        for (auto g : l3[v]) summ+=ew[g];
        sum.insert({summ,v}); 
    }
}

void calc1(ll x) {
    for (auto g : whole) {
        if (eu[x]-eu[g] && eu[x]-ev[g] && ev[x]-eu[g] && ev[x]-ev[g]) {
            // cout<<x<<' '<<g<<endl;
            // cout<<ew[x]<<"   "<<ew[g]<<endl; cout<<e<<' '<<v<<endl;
            res=min(res,ew[x]+ew[g]);
            return;
        }
    }
}

void calc() {
    res=1e18;
    // for (auto g : sum) cout<<'('<<g.fi<<','<<g.se<<')'<<' '; cout<<endl;
    if (sum.size()) {
        res=min(res,(sum.begin())->fi);
    }
    if (whole.size()) {
        auto bruh=(*(whole.begin()));
        calc1(bruh);
        for (auto g : inn[eu[bruh]]) calc1(g);    
        for (auto g : inn[ev[bruh]]) calc1(g);    
    }
    cout<<res<<endl;
}

int main()
{
	fio;
    cin>>n>>m;
    for (i=1;i<=m;i++) {
        cin>>eu[i]>>ev[i]>>ew[i];
        if (eu[i]>ev[i]) swap(eu[i],ev[i]);
        ntoe[{eu[i],ev[i]}]=i;
        add(i,eu[i]);
        add(i,ev[i]);
    }
    calc();
    cin>>t;
    for (i=m+1;i<=m+t;i++)
    {
        cin>>b;
        if (b==0) {
            cin>>u>>v;
            if (u>v) swap(u,v);
            a = ntoe[{u,v}];
            del(a,u);
            del(a,v);
        } else {
            cin>>eu[i]>>ev[i]>>ew[i];
            if (eu[i]>ev[i]) swap(eu[i],ev[i]);
            ntoe[{eu[i],ev[i]}]=i;
            add(i,eu[i]);
            add(i,ev[i]);
        }
        calc();
    }
}
// N;