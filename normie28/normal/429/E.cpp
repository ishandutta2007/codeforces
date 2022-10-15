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
vector<int> vec,sta;
int n,m,i,j,k,t,t1,u,v,a,b;
struct cmp
{
    int operator()(pii(int) a, pii(int) b) const{
        if (a.fi-b.fi) return (a.fi<b.fi);
        return (a.se<b.se);
    };
};
map<int,set<pii(int),cmp>> gt;
int res[100001];
int main()
{
    fio;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>u>>v;
        gt[u].insert({v+1,i});
        gt[v+1].insert({u,i});
    }
    vec.clear();
    for (auto& g : gt) if (g.se.size()%2) vec.push_back(g.fi);
    for (i=0;i<vec.size();i+=2)
    {
        gt[vec[i]].insert({vec[i+1],0});
        gt[vec[i+1]].insert({vec[i],0});
    }
    vec.clear();
    for (auto& g : gt) if (g.se.size()%2==0) vec.push_back(g.fi);
    for (auto g : vec) if (gt[g].size())
    {
        sta.push_back(g);
        while(sta.size())
        {
            u=sta[sta.size()-1];
            if (!gt[u].size()) sta.pop_back();
            else
            {
                auto pp=*(gt[u].begin());
                if (u<pp.fi) res[pp.se]=0;
                else res[pp.se]=1;
                gt[u].erase(pp);
                gt[pp.fi].erase({u,pp.se});
                sta.push_back(pp.fi);
            }
        }
    }
    for (i=1;i<=n;i++) cout<<res[i]<<' ';
}