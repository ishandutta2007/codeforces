#include <bits/stdc++.h>

//#define int long long
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

int R[507][507];
int D[507][507];
int DP[507][507][23];

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
            for(int j=1;j<m;j++)
            {
                cin>>R[i][j];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>D[i][j];
            }
        }
        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=m+1;j++)
            {
                for(int l=0;l<=k;l++)
                {
                    DP[i][j][l]=mod;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                DP[i][j][0]=0;
            }
        }
        for(int l=2;l<=k;l++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    DP[i][j][l]=min(mod,min(min(DP[i-1][j][l-2]+2*D[i-1][j],DP[i][j-1][l-2]+2*R[i][j-1]),min(DP[i+1][j][l-2]+2*D[i][j],DP[i][j+1][l-2]+2*R[i][j])));
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(DP[i][j][k]==mod) cout<<-1<<" ";
                else cout<<DP[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}