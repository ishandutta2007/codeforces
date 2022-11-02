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

const bool multi=0;

int DP[507][507];
int fac[507];
int inv[507];
int P[507][507];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int npok(int n,int k) {return fac[n]*inv[k]%mod*inv[n-k]%mod;}

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
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=500;i++)
        {
            P[i][0]=1;
            for(int j=1;j<=500;j++) P[i][j]=P[i][j-1]*i%mod;
        }
        fac[0]=1;
        for(int i=1;i<=500;i++) fac[i]=fac[i-1]*i%mod;
        inv[500]=pot(fac[500],mod-2);
        for(int i=500-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<min(k+1,i);j++) DP[i][j]=npok(n,i)*P[j][i]%mod;
            for(int j=min(k+1,i)-1;j>0;j--) DP[i][j]=(DP[i][j]-DP[i][j-1]+mod)%mod;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                for(int l=1;;l++)
                {
                    if(i+l>n||j+i+l-1>k) break;
                    DP[i+l][j+i+l-1]=(DP[i+l][j+i+l-1]+DP[i][j]*npok(n-i,l)%mod*P[i+l-1][l])%mod;
                }
                if(j+i-1<=k) DP[i][j+i-1]=(DP[i][j+i-1]+DP[i][j])%mod;
            }
        }
        int ans=0;
        for(int j=1;j<=k;j++) ans=(ans+DP[n][j])%mod;
        cout<<ans;
    }

    return 0;
}