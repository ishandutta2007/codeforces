#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
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

set<int>G[100007];
int ile[100007];
pair<int,int> rem[100007];
pair<int,int> add[100007];
bool odw[100007];
vector<int>vec[100007];
bool xd[100007];
int ans,c;

void usun(int u,int v)
{
    rem[++ans]={u,v};
    ile[u]--;
    ile[v]--;
}

void dfs(int v,int o)
{
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
    }
    if(ile[v]>2&&o!=-1)
    {
        usun(v,o);
        xd[v]=1;
    }
    for(auto u:G[v])
    {
        if(u==o||xd[u]) continue;
        if(ile[v]<=2) break;
        usun(v,u);
    }
}

void dfs1(int v,int o)
{
    odw[v]=1;
    if(sz(G[v])<=1) vec[c].pb(v);
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs1(u,v);
    }
}

void clean(int n)
{
    ans=0,c=0;
    for(int i=1;i<=n;i++)
    {
        vec[i].clear();
        G[i].clear();
        odw[i]=0;
        xd[i]=0;
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
        int n,a,b;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].insert(b);
            G[b].insert(a);
        }
        for(int i=1;i<=n;i++) ile[i]=sz(G[i]);
        dfs(1,-1);
        for(int i=1;i<=ans;i++)
        {
            G[rem[i].st].erase(rem[i].nd);
            G[rem[i].nd].erase(rem[i].st);
        }
        for(int i=1;i<=n;i++)
        {
            if(!odw[i])
            {
                c++;
                dfs1(i,-1);
            }
        }
        cout<<ans<<endl;
        for(int i=2;i<=c;i++) add[i-1]={vec[i-1].back(),vec[i][0]};
        for(int i=1;i<=ans;i++) cout<<rem[i].st<<" "<<rem[i].nd<<" "<<add[i].st<<" "<<add[i].nd<<endl;
        clean(n);
    }

    return 0;
}