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

int tab[77][77];
int DP[77][77][77];
int ans[77][77];

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
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>tab[i][j];
            }
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                ans[i][j]=-inf;
            }
        }
        ans[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int l=0;l<=m/2;l++)
                {
                    for(int z=0;z<k;z++)
                    {
                        DP[j][l][z]=-inf;
                    }
                }
            }
            DP[0][0][0]=0;
            for(int j=1;j<=m;j++)
            {
                DP[j][0][0]=0;
                for(int l=1;l<=m/2;l++)
                {
                    for(int z=0;z<k;z++)
                    {
                        int x=z-tab[i][j]%k;
                        if(x<0) x+=k;
                        DP[j][l][z]=max(DP[j-1][l][z],DP[j-1][l-1][x]+tab[i][j]);
                    }
                }
            }
            for(int l=1; l<=m/2; l++)
            {
                for(int z=0; z<k; z++)
                {
                    DP[m][l][z]=max(DP[m][l][z],DP[m][l-1][z]);
                }
            }
            //for(int j=0;j<k;j++) cout<<DP[m][m/2][j]<<" ";
            //cout<<endl;
            for(int j=0;j<k;j++)
            {
                for(int l=0;l<k;l++)
                {
                    int x=j-l;
                    if(x<0) x+=k;
                    ans[i][j]=max(ans[i][j],DP[m][m/2][l]+ans[i-1][x]);
                }
            }
        }
        cout<<ans[n][0];
    }

    return 0;
}