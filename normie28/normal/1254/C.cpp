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
ll ask(int a, int b, int c, int d)
{
    cout<<a<<' '<<b<<' '<<c<<' '<<d;
    ll res;
    cout<<endl;
    cin>>res;
    return res;
}
vector<ll> vec;
void answer()
{
    cout<<0;
    for (auto g : vec) cout<<' '<<g;
    cout<<endl;
    exit(0);
}
ll n,m,i,j,k,t,t1,u,v,a,b;
vector<pii(ll)> hu,hd;
vector<pii(ll)> qul,qur,qdl,qdr;
int main()
{
	fio;
    cin>>n;
    for (i=3;i<=n;i++)
    {
        u=ask(1,i,1,2);
        v=ask(2,i,1,2);
        if (v==-1) hd.push_back({i,u});
        else hu.push_back({i,u});
    }
    vec.push_back(1);
    if (hd.size())
    {
        sort(hd.begin(),hd.end(),[](pii(ll) a, pii(ll) b){return (a.se<b.se);});
        for (i=0;i<hd.size()-1;i++) if (ask(2,1,hd[i].fi,hd[hd.size()-1].fi)==1) qdl.push_back(hd[i]);
        else qdr.push_back(hd[i]);
        for (i=0;i<qdl.size();i++) vec.push_back(qdl[i].fi);
        vec.push_back(hd[hd.size()-1].fi);
        for (i=qdr.size()-1;i>=0;i--) vec.push_back(qdr[i].fi);
    }
    vec.push_back(2);
    if (hu.size())
    {
        sort(hu.begin(),hu.end(),[](pii(ll) a, pii(ll) b){return (a.se<b.se);});
        for (i=0;i<hu.size()-1;i++) if (ask(2,1,hu[i].fi,hu[hu.size()-1].fi)==1) qur.push_back(hu[i]);
        else qul.push_back(hu[i]);
        for (i=0;i<qur.size();i++) vec.push_back(qur[i].fi);
        vec.push_back(hu[hu.size()-1].fi);
        for (i=qul.size()-1;i>=0;i--) vec.push_back(qul[i].fi);
    }
    answer();
}