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

int DP[1007][1007][2];

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
        int n,k;
        cin>>n>>k;
        memset(DP,0,sizeof DP);
        DP[0][k][1]=1;
        for(int j=k;j>0;j--)
        {
            for(int i=1;i<=n;i++) DP[i][j][1]=(DP[i-1][j][1]+DP[i+1][j+1][0])%mod;
            for(int i=n;i>0;i--) DP[i][j][0]=(DP[i+1][j][0]+DP[i-1][j+1][1])%mod;
        }
        int ans=0;
        for(int i=1;i<=k;i++)
        {
            ans=(ans+DP[1][i][0]+DP[n][i][1])%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}