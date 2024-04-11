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
#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"
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
vector<int> vec;
string s;
int n,m,i,j,k,t,t1,u,v,a,b;
int arr[201],brr[201],cnt[2];
int cntb[201][3];
int main()
{
    ofile;
	fio;
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        cin>>u;
        arr[u]=1;
        cnt[1]++;
    }
    cnt[0]=n-m;
    cin>>k;
    for (i=1;i<=k;i++)
    {
        cin>>s;
        cin>>t;   
        brr[i]=t;
        for (t1=0;t1<t;t1++)
        {
            cin>>u;
            if (u==0)
            {
                cntb[i][2]++;
            } 
            else cntb[i][arr[u]]++;
        }
        
    //    cout<<cntb[i][0]<<' '<<cntb[i][1]<<' '<<cntb[i][2]<<' '<<brr[i]<<endl;
    //    cout<<min(cnt[1],cntb[i][2]+cntb[i][1])<<' '<<brr[i]-min(cnt[0],cntb[i][2]+cntb[i][0])<<endl;
    }
    for (i=1;i<=k;i++)
    {
        v=2;
        u=1;
        for (j=1;j<=k;j++) if ((i-j)and(min(cnt[1],cntb[j][2]+cntb[j][1])>brr[i]-min(cnt[0],cntb[i][2]+cntb[i][0]))) u=0;
        if (u) v=0;
        u=1;
        for (j=1;j<=k;j++) if ((i-j)and(min(cnt[1],cntb[i][2]+cntb[i][1])<brr[j]-min(cnt[0],cntb[j][2]+cntb[j][0]))) u=0;
        if (u==0) v=1;
        cout<<v<<endl;
    }
}