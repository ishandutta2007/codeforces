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
int ile[5007];
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
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) DP[i][0]=1;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                DP[j][i]=(DP[j-1][i-1]+DP[j+1][i-1])%mod;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                ile[i]=(ile[i]+DP[i][j]*DP[i][k-j])%mod;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=(ans+a[i]*ile[i])%mod;
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            ans+=((y-a[x])+mod)%mod*ile[x]%mod;
            a[x]=y;
            ans%=mod;
            cout<<ans<<endl;
        }
    }

    return 0;
}