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
int DP[100007];
int t[100007];
int x[100007];
int y[100007];
bool ok[100007];


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
       int r,n,ans=0;;
       cin>>r>>n;
       ok[0]=1;
       x[0]=1;
       y[0]=1;
        for(int i=1;i<=n;i++)
        {
            cin>>t[i]>>x[i]>>y[i];
            int mx=0;
            bool is=0;
            for(int j=i-1;j>=max((int)0,i-2007);j--)
            {
                if(ok[j]&&t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j]))
                {
                    is=1;
                    mx=max(mx,DP[j]+1);
                }
            }
            if(is) ok[i]=1;
            DP[i]=mx;
            ans=max(mx,ans);
        }
        cout<<ans;
    }

    return 0;
}