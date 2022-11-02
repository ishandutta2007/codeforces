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

const int N=1000007;

int p[N];
int DP[N];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}

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
        cin>>n;
        p[0]=1;
        for(int i=1;i<=n;i++) p[i]=p[i-1]*2%mod;
        DP[n+1]=1;
        DP[n+2]=0;
        for(int i=n;i>0;i--)
        {
            DP[i]=(2*DP[i+1]-DP[min(n+2,2*i)]+mod)%mod;
            if(2*i==n+1) DP[i]=(DP[i]+1)%mod;
        }
        int inv=pot(p[n],mod-2);
        for(int i=1;i<=n;i++)
        {
            int ans=0;
            ans=p[i/2]*(DP[i+1]-DP[min(n+2,2*i)]+mod)%mod;
            if(2*i==n+1) ans=(ans+p[i/2])%mod;
            if(i==n) ans=(ans+p[i/2]+mod)%mod;
            cout<<ans*inv%mod<<endl;
        }
    }

    return 0;
}