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

int DP[5007][5007];
int a[5007];

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
        mod=mod1;
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        DP[n][n]=1;
        for(int i=n-1;i>0;i--)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]>=2*a[i]) DP[i][i]=(DP[i][i]+DP[i+1][j])%mod;
                DP[i][j]=DP[i+1][j]*(n-i-(2*a[i]>a[j]))%mod;
            }
        }
        for(int i=1;i<=n;i++) ans=(ans+DP[1][i])%mod;
        cout<<ans;
    }

    return 0;
}