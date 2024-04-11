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
vector<pii(int)> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
int dis[501];
pii(int) fir[501];
deque<int> lmao;
vector<int> in,ou;
vector<int> in2,ou2;
int main()
{
	fio;
    cin>>n>>m;
    dis[0]=0;
    for (i=1;i<=n;i++) dis[i]=1e9;
    lmao.push_back(0);
    while(lmao.size())
    {
        u=lmao.front();
        lmao.pop_front();
        for (i=0;i<=m;i++) if ((i<=u)and(m-i<=n-u)and(dis[u-i+(m-i)]==1e9))
        {
            dis[u-i+(m-i)]=dis[u]+1;
            fir[u-i+(m-i)]={u,i};
            lmao.push_back(u-i+(m-i));
        }
    }
    if (dis[n]==1e9)
    {
        cout<<-1<<endl;
    }
    else
    {
        u=n;
        while(u)
        {
            vec.push_back(fir[u]);
            u=fir[u].fi;
        }
        reverse(vec.begin(),vec.end());
        a=0;
        for (i=1;i<=n;i++) ou.push_back(i); 
        for (auto g : vec)
        {
            cout<<"?";
            in2.clear();
            for (i=0;i<g.se;i++)
            {
                in2.push_back(in.back());
                cout<<' '<<in.back();
                in.pop_back();
            }
            ou2.clear();
            for (i=0;i<m-g.se;i++)
            {
                ou2.push_back(ou.back());
                cout<<' '<<ou.back();
                ou.pop_back();
            }
            cout<<endl;
            cin>>b;
            a^=b;
            for (auto g : in2) ou.push_back(g);
            for (auto g : ou2) in.push_back(g);
        }
        cout<<"! "<<a<<endl;
    }
}