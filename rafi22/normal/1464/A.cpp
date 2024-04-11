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

int row[100007];
int col[100007];
vector<int> G[100007];
bool odw[100007];
int ans,cnt;

void edge(int u,int v)
{
   // cout<<u<<" "<<v<<endl;
    cnt++;
    G[u].pb(v);
    G[v].pb(u);
}

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u]) dfs(u);
        else ans++;
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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            if(x==y) continue;
            ans++;
            if(row[y]>0) edge(row[y],i);
            if(col[x]>0) edge(col[x],i);
            row[x]=i;
            col[y]=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(!odw[i]) dfs(i);
        }
        cout<<ans-cnt<<endl;
        ans=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            odw[i]=0;
            G[i].clear();
            row[i]=0;
            col[i]=0;
        }
    }

    return 0;
}