/*
khoi orz, go check out his algo
-normie-
Tested with library-checker.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "birds.inp"
#define FILE_OUT "birds.out"
#define prev prv
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
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define ll long long
#define pi 3.1415926535897
//------START-----------//
ll n,m,i,j,k,u,v,a,b,ress=0;
vector<ll> gt[1000001];
ll dep[1000001];
map<ll,ll> depcnt[1000001];
ll maxind[1000001];
ll ncnt[1000001];
ll res[1000001];
ll dfs (ll x, ll d)
{
    dep[x]=d;
    depcnt[x][d]++;
    ncnt[x]++;
    if ((depcnt[x][d]>depcnt[x][maxind[x]])
    or((depcnt[x][d]==depcnt[x][maxind[x]])and(d<maxind[x])))
    maxind[x]=d;
    vector<ll> cand={x};
    for (ll g : gt[x]) if (!dep[g])
    {
        cand.push_back(dfs(g,d+1));
    }
    sort(cand.begin(),cand.end(),[](ll a, ll b){return (ncnt[a]>ncnt[b]);});
    ll v=cand[0];
    for (i=1;i<cand.size();i++)
    {
        ll g=cand[i];
        for (pii pp : depcnt[g])
        {
            depcnt[v][pp.fi]+=pp.se;
            ncnt[v]+=pp.se;
            
            if ((depcnt[v][pp.fi]>depcnt[v][maxind[v]])
            or((depcnt[v][pp.fi]==depcnt[v][maxind[v]])and(pp.fi<maxind[v])))
            maxind[v]=pp.fi;
        }
        depcnt[g].clear();
    }
    res[x]=maxind[v]-d;
    return v;
}
//------END-----------//
int main()
{
//    ofile;
    fio;
    cin>>n;
    for (i=1;i<n;i++)
    {
        cin>>u>>v;
        gt[u].push_back(v);
        gt[v].push_back(u);
    }
    dfs(1,1);
    for (i=1;i<=n;i++) cout<<res[i]<<endl;
}