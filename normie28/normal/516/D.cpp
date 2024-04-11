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
int head[100005],nxt[200005],pnt[200005],len[200005],E;
ll dp[100005][2],n;
int siz[100005],fa[100005],a[100005],vis[100005],ans;
void add_edge(int u,int v,int w)
{
    pnt[E]=v;
    nxt[E]=head[u];
    len[E]=w;
    head[u]=E++;
}
int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if (xx==yy) return;
    fa[xx]=yy;
    siz[yy]+=siz[xx];
    ans=max(ans,siz[yy]);
}
bool cmp(int x,int y)
{
    return dp[x][0]>dp[y][0];
}
void dfs1(int u,int pre)
{
    for (int i=head[u];i!=-1;i=nxt[i])
    {
        int v=pnt[i];
        if (v==pre) continue;
        dfs1(v,u);
        if (dp[v][0]+len[i]>=dp[u][0])
        {
            dp[u][1]=dp[u][0];
            dp[u][0]=dp[v][0]+len[i];
        }
        else if (dp[v][0]+len[i]>dp[u][1]) dp[u][1]=dp[v][0]+len[i];
    }
}
void dfs2(int u,int pre)
{
    for (int i=head[u];i!=-1;i=nxt[i])
    {
        int v=pnt[i];
        if (v==pre) continue;
        ll tmp=0;
        if (dp[u][0]==dp[v][0]+len[i]) tmp=dp[u][1]+len[i];
        else tmp=dp[u][0]+len[i];
        if (tmp>=dp[v][0]) dp[v][1]=dp[v][0],dp[v][0]=tmp;
        else if (tmp>dp[v][1]) dp[v][1]=tmp;
        dfs2(v,u);
    }
}
int main()
{
    memset(head,-1,sizeof(head));
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    dfs1(1,0);
    dfs2(1,0);
    for (int i=1;i<=n;i++)
        a[i]=i;
    sort(a+1,a+n+1,cmp);
    int Q;
    cin>>Q;
    while(Q--)
    {
        ll x;
        cin>>x;
        int L=1,R=1;
        for (int i=1;i<=n;i++)
            fa[i]=i,siz[i]=1;
        memset(vis,0,sizeof(vis));
        ans=1;
        for (L=1;L<=n;L++)
        {
            while(R<=n&&dp[a[L]][0]-dp[a[R]][0]<=x)
            {
                vis[a[R]]=1;
                int u=a[R];
                for (int i=head[u];i!=-1;i=nxt[i])
                {
                    int v=pnt[i];
                    if (vis[v]) merge(u,v);
                }
                R++;
            }
            vis[a[L]]=0;
            int tmp=find(a[L]);
            siz[tmp]--;
        }
        cout<<ans<<endl;
    }
}