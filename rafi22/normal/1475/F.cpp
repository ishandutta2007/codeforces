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

vector<int> G[4007];
int color[4007];
char g1[1007][1007];
char g2[1007][1007];

void dfs(int v,int c)
{
    color[v]=c;
    for(auto u:G[v])
    {
        if(!color[u]) dfs(u,c);
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
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>g1[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>g2[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((g1[i][j]-48)^(g2[i][j]-48))
                {
                    G[2*i].pb(2*(n+j)+1);
                    G[2*(n+j)+1].pb(2*i);
                    G[2*(n+j)].pb(2*i+1);
                    G[2*i+1].pb(2*(n+j));
                }
                else
                {
                    G[2*i].pb(2*(n+j));
                    G[2*(n+j)].pb(2*i);
                    G[2*(n+j)+1].pb(2*i+1);
                    G[2*i+1].pb(2*(n+j)+1);
                }
            }
        }
        int it=0;
        for(int i=2;i<=4*n+1;i++)
        {
            if(!color[i]) dfs(i,++it);
        }
        bool ans=1;
        for(int i=1;i<=2*n;i++)
        {
            if(color[2*i]==color[2*i+1]) ans=0;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for(int i=0;i<=4*n+3;i++)
        {
            color[i]=0;
            G[i].clear();
        }
    }

    return 0;
}