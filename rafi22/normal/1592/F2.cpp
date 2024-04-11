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

const bool multi=0;

bool is[507][507];
bool g[507][507];
vector<int>G[1007];
bool odw[1007];
int Pair[1007];

bool match(int v)
{
    if(odw[v]) return 0;
    odw[v]=1;
    for(auto u:G[v])
    {
        if(!Pair[u]&&!odw[u])
        {
            Pair[u]=v;
            Pair[v]=u;
            return 1;
        }
    }
    for(auto u:G[v])
    {
        if(!odw[u]&&match(Pair[u]))
        {
            Pair[u]=v;
            Pair[v]=u;
            return 1;
        }
    }
    return 0;
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
        char c;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='B') g[i][j]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                is[i][j]=(g[i][j]+g[i+1][j]+g[i][j+1]+g[i+1][j+1])%2;
                ans+=is[i][j];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(is[i][j]&&is[i][m]&&is[n][j])
                {
                    G[i].pb(n+j);
                    G[n+j].pb(i);
                }
            }
        }
        while(true)
        {
            memset(odw,0,sizeof odw);
            bool xd=0;
            for(int i=1;i<=n+m;i++) if(!Pair[i]) xd|=match(i);
            if(!xd) break;
        }
        int C=0;
        for(int i=1;i<=n;i++) if(Pair[i]) C++;
        if(is[n][m]) ans-=2*(C/2+C%2);
        else ans-=2*(C/2);
        cout<<ans;
    }

    return 0;
}