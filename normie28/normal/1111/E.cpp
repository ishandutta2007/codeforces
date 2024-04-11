
// Problem : E. Tree
// Contest : Codeforces - CodeCraft-19 and Codeforces Round #537 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1111/E
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
#define index indexx
//---------END-------//
const int maxn=1e5+10;
const ll mod=1e9+7;
 
int in[maxn],out[maxn],fa[maxn][21],deep[maxn],index;
vector<int> g[maxn];
int a[maxn],v[maxn],h[maxn];
int d[maxn],dp[maxn],n,q;
 
void dfs(int u,int pre)
{
    in[u]=++index;
    deep[u]=deep[pre]+1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==pre) continue;
        fa[v][0]=u;
        dfs(v,u);
    }
    out[u]=index;
}
void anc()
{
    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=n;j++)
            fa[j][i]=fa[fa[j][i-1]][i-1];
    }
}
 
int GetLca(int u,int v)
{
    if(u==v) return u;
    if(deep[u]<deep[v]) swap(u,v);
    for(int i=18;i+1;i--)
    {
        if(deep[fa[u][i]]>=deep[v]) u=fa[u][i];
    }
    if(u==v) return u;
    for(int i=18;i+1;i--)
    {
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    }
 
    return fa[u][0];;
}
void add(int x,int val)
{
    while(x<=n)
    {
        d[x]+=val;
        x+=x&-x;
    }
}
 
int get(int x)
{
    int ret=0;
    while(x)
    {
        ret+=d[x];
        x-=x&-x;
    }
    return ret;
}
 
int main()
{
	fio;
	cin>>n>>q;
 
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    index=0;
    deep[0]=0;
    dfs(1,0); anc();
 
    while(q--)
    {
        int k,m,rt;
        cin>>k>>m>>rt;
        for(int i=1;i<=k;i++)
        {
        	cin>>a[i];
            v[a[i]]=1;
            add(in[a[i]],1);
            add(out[a[i]]+1,-1);
        }
 
        int root=get(in[rt]);
        for(int i=1;i<=k;i++)
        {
            int lca=GetLca(rt,a[i]);
            h[i]=get(in[a[i]])+root-2*get(in[lca])+(v[lca]==1)-1;
        }
        sort(h+1,h+k+1);
        for(int i=1;i<=k;i++)
        {
            add(in[a[i]],-1);
            add(out[a[i]]+1,1);
            v[a[i]]=0;
        }
        if(h[k]>=m) {cout<<0<<endl; continue;}
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=k;i++)
            for(int j=min(m,i);j>=0;j--)
        {
            if(j<=h[i]) dp[j]=0;
            else dp[j]=dp[j-1]%mod+(ll)dp[j]*(j-h[i])%mod;
        }
        ll res=0;
 
        for(int i=1;i<=m;i++)
            res=(res+dp[i])%mod;
            cout<<res<<endl;
    }
}