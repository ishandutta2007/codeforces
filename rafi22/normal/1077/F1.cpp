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
int a[207];
int DP[207][207];

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
        int n,k,x;
        cin>>n>>k>>x;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=x;j++)
            {
                DP[i][j]=-inf;
            }
        }
        DP[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=x;j++)
            {
                for(int l=i-1;l>=max((int)0,i-k);l--) DP[i][j]=max(DP[i][j],DP[l][j-1]+a[i]);
            }
        }
        int ans=-1;
        for(int i=n;i>n-k;i--) ans=max(ans,DP[i][x]);
        cout<<ans;


    }

    return 0;
}