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

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int silnia[200007];
int dwumian[2007][2007];
int pk[200007];
//int dwumian(int n, int k){ return (silnia[n]*pot(silnia[k]*silnia[n-k]%mod,mod-2))%mod;}

int h[200007];

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
        silnia[0]=1;
        for(int i=1;i<=200000;i++) silnia[i]=silnia[i-1]*i%mod;
        dwumian[0][0]=1;
        for(int i=1;i<=2000;i++)
        {
            dwumian[i][0]=1;
            for(int j=1;j<=i;j++) dwumian[i][j]=(dwumian[i-1][j-1]+dwumian[i-1][j])%mod;
        }
        int n,k;
        cin>>n>>k;
        pk[0]=1;
        for(int i=1;i<=n;i++) pk[i]=pk[i-1]*(k-2)%mod;
        for(int i=1;i<=n;i++) cin>>h[i];
        int s=0;
        for(int i=1;i<=n;i++) if(h[i]==h[i%n+1]) s++;
        int ans=0;
        n-=s;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(i+j>n) continue;
                ans=(ans+dwumian[n][i]*dwumian[n-i][j]%mod*pk[n-i-j]%mod)%mod;
            }
        }
        ans=ans*pot(k,s)%mod;
        cout<<ans;
    }

    return 0;
}