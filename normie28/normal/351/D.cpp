
// Problem : D. Jeff and Removing Periods
// Contest : Codeforces - Codeforces Round #204 (Div. 1)
// URL : https://codeforces.com/problemset/problem/351/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define F first
#define S second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef pair <ll,ll> pll;
//---------END-------//
const ll N=1e5+10,SQ=450,inf=1e5+10;
ll n,m,q,l,r,a[N],f[N],fa[N],b[N],c[N],res[N],vq[10000];
pll p,g[N];
vector <pll> v[N];
 
void add(ll v,ll c)
{
    for(; v<N; v+=v&-v)
        fa[v]+=c;
}
 
ll gets(ll ind)
{
    ll ret=0;
    for(; ind; ind-=ind&-ind)
        ret+=fa[ind];
    return ret;
}
 
void upd(ll s)
{
    ll id=s/SQ;
    vq[id]=inf;
    for(int i=id*SQ; i<(id+1)*SQ && i<n; i++)
        vq[id]=min(vq[id],c[i]);
}
 
ll get(ll s,ll e)
{
    ll l=s/SQ,r=e/SQ,ret=inf;
    l++;
    for(int i=l; i<r; i++)
        ret=min(ret,vq[i]);
    if(l-r==1)
    {
        for(int i=s; i<=e; i++)
            ret=min(ret,c[i]);
        return ret;
    }
    for(int i=s; i<l*SQ; i++)
        ret=min(ret,c[i]);
    for(int i=r*SQ; i<=e; i++)
        ret=min(ret,c[i]);
    return ret;
}
 
 
int main()
{
	fio;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    fill(b,b+N,-1);
    cin >> q;
    for(int i=1; i<=q; i++)
    {
        cin >> l >> r;
        v[r-1].push_back({l-1,i});
    }
    for(int i=0; i<n; i++)
    {
        f[i]=b[a[i]];
        b[a[i]]=i;
        add(i+1,1);
        g[i]=make_pair(-1,0);
        if(f[i]!=-1)
        {
            add(f[i]+1,-1);
            if(g[f[i]].S==0 || g[f[i]].S!=i-f[i]) g[i]=make_pair(f[f[i]],i-f[i]);
            else    if(g[f[i]].S==i-f[i])   g[i]=g[f[i]];
            c[f[i]]=inf;
            upd(f[i]);
        }
        c[i]=g[i].F;
        upd(i);
        r=i;
        for(auto y:v[i])
        {
                l=y.F;
                res[y.S]=gets(r+1)-gets(l);
                if(get(l,r)>=l)
                    res[y.S]++;
        }
    }
    for(int i=1; i<=q; i++)
        cout << res[i] << endl;
}