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

const bool multi=0;

vector<int>G[507*507];
int color[507*507];
int ans[507][507];
char g[507][507];

void Union(int u,int v)
{
    G[u].pb(v);
    G[v].pb(u);
}

void gg()
{
    cout<<"NO";
    exit(0);
}
int n,m;
int p(int x,int y) {return (x-1)*m+y;}

void dfs(int v)
{
    for(auto u:G[v])
    {
        if(color[u])
        {
            if(color[u]!=3-color[v]) exit(2137);
            continue;
        }
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
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(g[i][j]=='.') continue;
                vector<int>x;
                if(g[i-1][j]=='.') x.pb(p(i-1,j));
                if(g[i][j+1]=='.') x.pb(p(i,j+1));
                if(g[i+1][j]=='.') x.pb(p(i+1,j));
                if(g[i][j-1]=='.') x.pb(p(i,j-1));
                if(sz(x)%2==1) gg();
                ans[i][j]=sz(x)/2*5;
                if(sz(x)>0) Union(x[0],x[1]);
                if(sz(x)==4) Union(x[2],x[3]);
            }
        }
        for(int i=1;i<=n*m;i++)
        {
            if(color[i]) continue;
            color[i]=1;
            dfs(i);
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(g[i][j]=='.')
                {
                    if(color[p(i,j)]==1) ans[i][j]=4;
                    else ans[i][j]=1;
                }
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}