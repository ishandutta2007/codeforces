/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
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
 
//---------END-------//
const int N=3e5+10,M=1e6+10,Q=6e6+10;
int n,k,tot;
int v[N],sum[N],cnt[M],fir[N];
struct node
{
    int val,pos;
}f[N][20];
inline node max(node a,node b)
{
    if(b.val>a.val) return b;
    else return a;
}
inline int query(int l,int r)
{
    int len=log2(r-l+1);
    return max(f[l][len],f[r-(1<<len)+1][len]).pos;
}
struct ask
{
    int val;
    int tag;
    int nxt;
}e[Q];
inline void add(int x,int y,int z)
{
    if(x) e[++tot].val=z,e[tot].tag=-1,e[tot].nxt=fir[x-1],fir[x-1]=tot;
    e[++tot].val=z,e[tot].tag=1,e[tot].nxt=fir[y],fir[y]=tot;
}
inline void solve(int l,int r)
{
    int mid=query(l,r);
    if(r-mid<mid-l) for(int i=mid;i<=r;i++) add(l-1,mid-1,(sum[i]-v[mid]%k+k)%k);
    else for(int i=l;i<=mid;i++) add(mid,r,(sum[i-1]+v[mid])%k);
    if(l<mid) solve(l,mid-1);
    if(r>mid) solve(mid+1,r);
}
int main()
{
    fio;
    ll ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        f[i][0]=(node){v[i],i};
        sum[i]=(sum[i-1]+v[i])%k;
    }
    for(int j=1;j<=log2(n);j++)
        for(int i=1;i<=n-(1<<j)+1;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    solve(1,n);
    for(int i=0;i<=n;i++)
    {
        cnt[sum[i]]++;
        for(int j=fir[i];j;j=e[j].nxt)
            ans+=cnt[e[j].val]*e[j].tag;
    }
    cout<<ans-n;
}