#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector<int>G[100007];
bool odw[100007];
bool col[100007];
vector<int>ans[2];

void dfs(int v,int d,int o)
{
    odw[v]=1;
    ans[d%2].pb(v);
    for(auto u:G[v])
    {
        if(!odw[u])
        {
            col[u]=!col[v];
            dfs(u,d+1,v);
        }
        else if(col[v]==col[u])
        {
            cout<<-1;
            exit(0);
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
        int n,m,a,b;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(!odw[i]) dfs(i,0,0);
        }
        cout<<ans[0].size()<<endl;
        for(auto v:ans[0]) cout<<v<<" ";
        cout<<endl;
        cout<<ans[1].size()<<endl;
        for(auto v:ans[1]) cout<<v<<" ";
        cout<<endl;
    }

    return 0;
}