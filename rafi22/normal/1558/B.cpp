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

int DP[5000007];
int P[5000007];

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
        DP[n]=1;
        P[n]=1;
        for(int i=n-1;i>0;i--)
        {
            DP[i]=P[i+1];
            for(int j=2;j<=n;j++)
            {
                if(i*j>n) break;
                DP[i]=(DP[i]+P[i*j])%mod;
                if(i*j+j<=n) DP[i]=(DP[i]-P[i*j+j]+mod)%mod;
            }
            P[i]=(DP[i]+P[i+1])%mod;
        }
        cout<<DP[1];
    }


    return 0;
}