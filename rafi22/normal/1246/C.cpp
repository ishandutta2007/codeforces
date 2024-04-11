#include <bits/stdc++.h>

#define int long long
#define double long double
// #define endl '\n'
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

char g[2007][2007];
vector<int>D[2007];
vector<int>R[2007];
int DP[2007][2007][2];
int prefD[2007][2007];
int prefR[2007][2007];
int ileD[2007][2007];
int ileR[2007][2007];

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
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
            }
        }
        for(int i=n;i>0;i--)
        {
            for(int j=m;j>0;j--)
            {
                ileD[i][j]=ileD[i+1][j];
                ileR[i][j]=ileR[i][j+1];
                if(g[i][j]!='R')
                {
                    ileD[i][j]++;
                    ileR[i][j]++;
                }
            }
        }
        DP[1][1][0]=1;
        DP[1][1][1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(g[i][j]=='R')
                {
                    D[j].pb(i);
                    R[i].pb(j);
                }
                if(i>1)
                {
                    if(sz(D[j])-(ileD[i+1][j]+1)>=0) DP[i][j][0]=(prefD[i-1][j]-prefD[D[j][sz(D[j])-(ileD[i+1][j]+1)]-1][j]+mod)%mod;
                    else DP[i][j][0]=prefD[i-1][j];
                }
                if(j>1)
                {
                    if(sz(R[i])-(ileR[i][j+1]+1)>=0) DP[i][j][1]=(prefR[i][j-1]-prefR[i][R[i][sz(R[i])-(ileR[i][j+1]+1)]-1]+mod)%mod;
                    else DP[i][j][1]=prefR[i][j-1];
                }
                prefD[i][j]=(prefD[i-1][j]+DP[i][j][1])%mod;
                prefR[i][j]=(prefR[i][j-1]+DP[i][j][0])%mod;
            }
        }
        if(n==1&&m==1) cout<<1;
        else cout<<(DP[n][m][0]+DP[n][m][1])%mod;
    }

    return 0;
}