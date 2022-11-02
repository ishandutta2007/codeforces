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

int DP[407][407];
int DP1[407][407];
int len[407];

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
        cin>>n>>mod;
        DP1[0][0]=1;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i>0) DP1[i][j]=(DP1[i][j]+DP1[i-1][j])%mod;
                if(j>0) DP1[i][j]=(DP1[i][j]+DP1[i][j-1])%mod;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++) len[i]=(len[i]+DP1[j-1][i-j])%mod;
        }
        int ans=len[n];
        DP[0][0]=1;
        for(int i=2;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=i-2;k>=0;k--)
                {
                    if(k-j+1<0||i-k+1<0) continue;
                    DP[i][j]=(DP[i][j]+DP[k][j-1]*DP1[k-j+1][i-k-1]%mod*len[i-k-1]%mod)%mod;
                }
                if(i-j<0||n-i<0) continue;
                ans=(ans+DP[i][j]*DP1[i-j][n-i]%mod*len[n-i]%mod)%mod;
            }
        }
        cout<<ans;
    }

    return 0;
}