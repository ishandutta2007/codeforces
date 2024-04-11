#include <bits/stdc++.h>

#define int long long
#define ld long double
//#define double long double
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

int DP[200007];
int pot[200007];
int P[200007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pot[0]=1;
    for(int i=1;i<=200000;i++) pot[i]=pot[i-1]*2%mod;
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,k,ans=0;
        cin>>n>>k;
        P[0]=1;
        for(int i=1;i<=k;i++) P[i]=P[i-1]*pot[n]%mod;
        DP[0]=1;
        for(int i=1;i<=k;i++)
        {
            if(n%2==0) ans=(ans+DP[i-1]*P[k-i])%mod;
            if(n%2==0) DP[i]=(DP[i-1]*(pot[n-1]-1)%mod+mod)%mod;
            else DP[i]=(DP[i-1]*(pot[n-1]+1))%mod;
        }
        ans=(ans+DP[k])%mod;
        cout<<ans<<endl;
    }

    return 0;
}