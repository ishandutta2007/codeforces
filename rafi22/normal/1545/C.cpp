#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int p[1007][1007];
set<int>xd[1007][1007];
int color[1007];
bool odw[1007];
vector<int>G[1007];

void dfs(int v)
{
    for(auto u:G[v])
    {
        if(color[u]) continue;
        color[u]=3-color[v];
        dfs(u);
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
        int n;
        cin>>n;
        for(int i=1;i<=2*n;i++)
        {
            G[i].clear();
            color[i]=0;
            odw[i]=0;
        }
        for(int i=1;i<=2*n;i++)
        {
            for(int j=1;j<=n;j++) cin>>p[i][j];
        }
        deque<int>Q;
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=2*n;i++) xd[j][p[i][j]].insert(i);
            for(int i=1;i<=n;i++)
            {
                if(sz(xd[j][i])==1)
                {
                    int x=*xd[j][i].begin();
                    color[x]=1;
                    Q.pb(x);
                }
            }
        }
        while(!Q.empty())
        {
            int x=Q[0];
            Q.pop_front();
            if(odw[x]) continue;
            odw[x]=1;
            for(int j=1;j<=n;j++)
            {
                xd[j][p[x][j]].erase(x);
                if(color[x]==1)
                {
                    for(auto y:xd[j][p[x][j]])
                    {
                        color[y]=2;
                        Q.pb(y);
                    }
                    xd[j][p[x][j]].clear();
                }
                if(sz(xd[j][p[x][j]])==1)
                {
                    int y=*xd[j][p[x][j]].begin();
                    color[y]=1;
                    Q.pb(y);
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(sz(xd[j][i])==2)
                {
                    int x=*xd[j][i].begin(),y=*++xd[j][i].begin();
                    G[x].pb(y);
                    G[y].pb(x);
                }
                xd[j][i].clear();
            }
        }
        mod=mod1;
        int ans=1;
        for(int i=1;i<=2*n;i++)
        {
            if(!color[i])
            {
                ans=ans*2%mod;
                color[i]=1;
                dfs(i);
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=2*n;i++) if(color[i]==1) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}