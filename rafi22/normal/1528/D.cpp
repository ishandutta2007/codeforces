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

const bool multi=0;

int d[607][607];
bool odw[607];
vector<pair<int,int>>G[607];
int D[607];

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
        int n,m,a,b,c;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                d[i][j]=inf;
            }
        }
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            G[a].pb({b,c});
        }
        for(int i=0;i<n;i++)
        {
            d[i][i]=0;
            memset(odw,0,sizeof odw);
            for(int l=0;l<n;l++)
            {
                int mn=inf,u=-1;
                for(int j=0;j<n;j++)
                {
                    if(!odw[j]&&d[i][j]<mn)
                    {
                        mn=d[i][j];
                        u=j;
                    }
                    D[j]=inf;
                }
                odw[u]=1;
                for(auto v:G[u])
                {
                    int x=(v.st+d[i][u])%n;
                    D[x]=min(D[x],v.nd);
                    D[0]=min(D[0],v.nd+n-x);
                }
                for(int j=1;j<n;j++) D[j]=min(D[j],D[j-1]+1);
                for(int j=0;j<n;j++) d[i][j]=min(d[i][j],d[i][u]+D[j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<d[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}