#include<bits/stdc++.h>
using namespace std;

const int N=511;

int T;

int n,m;

int u[N*N],v[N*N],w[N*N];

long long f[N][N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=(i==j?0:1e9);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
            f[u[i]][v[i]]=f[v[i]][u[i]]=1;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        long long ans=1e18;
        for(int i=1;i<=m;i++)
        {
            for(int p=1;p<=n;p++)
            {
                ans=min(ans,1ll*(f[1][p]+f[p][n]+f[p][v[i]]+2)*w[i]);
                ans=min(ans,1ll*(f[1][p]+f[p][n]+f[p][u[i]]+2)*w[i]);
                // if(ans==132)
                //     cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<" "<<p<<endl;
            }
            ans=min(ans,1ll*(f[1][u[i]]+f[v[i]][n]+1)*w[i]);
            ans=min(ans,1ll*(f[n][u[i]]+f[v[i]][1]+1)*w[i]);
        }
        printf("%lld\n",ans);
    }
}