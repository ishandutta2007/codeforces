#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;
vector<int>G[100007];
int mx;
int DP[100007];
int d[100007];

void dfs(int v,int o)
{
    DP[v]=0;
    vector<int>xd;
    for(auto u:G[v])
    {
        if(u!=o)
        {
            dfs(u,v);
            xd.pb(DP[u]);
        }
    }
    sort(xd.begin(),xd.end(),greater<int>());
    if(sz(xd)>1) mx=max(mx,xd[0]+xd[1]+2);
    if(sz(xd)>0) DP[v]=xd[0]+1;
    mx=max(DP[v],mx);
}
void dfs1(int v,int o)
{
    for(auto u:G[v])
    {
        if(u!=o)
        {
            d[u]=d[v]+1;
            dfs1(u,v);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,a,b,da,db;
        cin>>n>>a>>b>>da>>db;
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            G[x].pb(y);
            G[y].pb(x);
        }
        if(2*da>=db) cout<<"Alice"<<endl;
        else
        {
            mx=0;
            dfs(1,-1);
            d[a]=0;
            dfs1(a,-1);
            if(2*da>=mx||d[b]<=da) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
        for(int i=1;i<=n;i++) G[i].clear();
    }

    return 0;
}