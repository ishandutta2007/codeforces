#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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

vector<int>G[200007];
int p[200007];

void dfs(int v,int o)
{
    p[v]=o;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
    }
}
int ile[200007];
int deg[200007];

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
        int ans;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1,-1);
        ans=0;
        deque<int>Q;
        for(int i=1;i<=n;i++) ile[i]=0;
        for(int i=1;i<=n;i++)
        {
            deg[i]=sz(G[i]);
            if(i==1) continue;
            if(deg[i]!=1) ile[p[i]]++;
            else
            {
                ans++;
                ile[i]=inf;
            }
        }
        ile[1]=inf;
        for(int i=2;i<=n;i++) if(ile[i]==0) Q.pb(i);
        while(!Q.empty())
        {
            int v=Q[0];
           // cout<<v<<endl;
            Q.pop_front();
            ans--;
            deg[p[v]]--;
            ile[p[v]]--;
            if(p[v]==1) continue;
            if(deg[p[v]]==1)
            {
                ans++;
                ile[p[p[v]]]--;
                if(p[p[v]]!=1&&ile[p[p[v]]]==0) Q.pb(p[p[v]]);
            }
            else
            {
                if(ile[p[v]]==0) Q.pb(p[v]);
            }
        }
        if(deg[1]==0) ans++;
        cout<<ans<<endl;
        for(int i=1;i<=n;i++) G[i].clear();
    }

    return 0;
}