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

const int N=507;

int G[N][N];
int d[N][N];

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
        int n,m,a,b,w;
        cin>>n>>m;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) G[i][j]=inf;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=inf;
        while(m--)
        {
            cin>>a>>b>>w;
            G[a][b]=min(G[a][b],w);
            G[b][a]=min(G[b][a],w);
            d[a][b]=1;
            d[b][a]=1;
        }
        for(int i=1;i<=n;i++) d[i][i]=0;
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
        int ans=inf;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(G[i][j]==inf) continue;
                ans=min(ans,(d[1][i]+d[j][n]+1)*G[i][j]);
                for(int k=1; k<=n; k++)
                {
                    ans=min(ans,(d[1][k]+d[k][i]+1+d[k][n]+1)*G[i][j]);
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}