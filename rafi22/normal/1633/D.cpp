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

int b[1007];
int c[1007];
int DP[2007];
int DP1[1007][15*1007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=2;i<=1000;i++) DP[i]=inf;
    for(int i=1;i<=1000;i++)
    {
        for(int x=1;x<=i;x++) DP[i+i/x]=min(DP[i+i/x],DP[i]+1);
    }
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) cin>>c[i];
        k=min(k,15*n);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                DP1[i][j]=DP1[i-1][j];
                if(j>=DP[b[i]]) DP1[i][j]=max(DP1[i][j],DP1[i-1][j-DP[b[i]]]+c[i]);
            }
        }
        cout<<DP1[n][k]<<endl;
    }

    return 0;
}