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
ll par[500001],dep[500001];
ll used[500001],ans[500001],anss[500001];
ll n,m,i,j,k,t,t1,u,v,a,b,root;
vector<piii(ll)> sta[500001];
vector<ll> gt[500001];
vector<pii(ll)> diff[500001];
ll calc(ll x)
{
    dep[x]=dep[par[x]]+1;
    vector<ll> vec;
    for (auto g : gt[x]) vec.push_back(calc(g));
    if (vec.size()==0)
    {
        sta[x].push_back({1,{x,dep[x]}}); 
        return x;
    }
    else
    {
        sort(vec.begin(),vec.end(),[](ll a, ll b){
            return (sta[a].size()>sta[b].size());
        });
        if (vec.size()>1)
        {
            vector<ll> vec2(sta[vec[1]].size(),0);
            for (ll i=0;i<vec.size();i++)
            for (ll j=0;j<min(sta[vec[i]].size(),sta[vec[1]].size());j++)
            {
                vec2[j]+=sta[vec[i]][sta[vec[i]].size()-1-j].fi;
            }
            for (ll i=0;i<vec.size();i++)
            for (ll j=0;j<min(sta[vec[i]].size(),sta[vec[1]].size());j++)
            {
                sta[vec[i]][sta[vec[i]].size()-1-j].se.se+=(vec2[j]-sta[vec[i]][sta[vec[i]].size()-1-j].fi)*dep[x];
                if (i==0)
                {
                sta[vec[i]][sta[vec[i]].size()-1-j].fi=vec2[j];
                }
                else
                {
                    auto pp1=sta[vec[i]][sta[vec[i]].size()-1-j];
                    auto pp2=sta[vec[0]][sta[vec[0]].size()-1-j];
                    diff[pp1.se.fi].push_back({pp2.se.fi,pp2.se.se-pp1.se.se});
                    diff[pp2.se.fi].push_back({pp1.se.fi,pp1.se.se-pp2.se.se});
                }
            }
        }
        {
            sta[vec[0]].push_back({1,{x,dep[x]}});
        }
        return vec[0];
    }
}
void dfs(ll x, ll d)
{
    used[x]=1;
    anss[x]=d;
    for (auto g : diff[x]) if (!used[g.fi]) dfs(g.fi,d+g.se);
}
void finl(ll x)
{
    ans[x]=ans[par[x]]+anss[x];
    for (auto g : gt[x]) finl(g);
}
int main()
{
	fio;
    cin>>n;
    for (i=1;i<=n;i++) {cin>>par[i]; gt[par[i]].push_back(i);}
    for (i=1;i<=n;i++) if (par[i]==0) break;
    root=i;
    
    for (auto g : sta[calc(root)] ) 
    {
        used[g.se.fi]=1;
        anss[g.se.fi]=g.se.se;
        dfs(g.se.fi,anss[g.se.fi]);
    }
    finl(root);
    for (i=1;i<=n;i++) cout<<ans[i]-dep[i]<<' ';
}