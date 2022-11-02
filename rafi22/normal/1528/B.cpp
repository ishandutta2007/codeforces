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

int d[1000007];
int DP[1000007];

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
        for(int i=1;i<=1000000;i++)
        {
            for(int j=i;j<=1000000;j+=i)
            {
                d[j]++;
            }
        }
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            DP[i]=(sum+d[i])%mod;
            sum=(sum+DP[i])%mod;
        }
        cout<<DP[n];
    }

    return 0;
}