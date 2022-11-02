#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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

int ile[100007];
int fac[100007];
int inv[100007];

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
        int n,k,ans=0,cnt=0;
        cin>>n>>k;
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
        inv[n]=pot(fac[n],mod-2);
        for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        for(int i=1;i<=n;i++)
        {
            if(n-i-(i-1)*(k-1)>=0) ile[i]=npok(n-(i-1)*(k-1),i);
            else ile[i]=0;
        }
        ile[n+1]=0;
        for(int i=1;i<n;i++)
        {
            ans=(ans+ile[i]*fac[i]%mod*inv[n]%mod*fac[n-i]%mod);
        }
        cout<<(ans+1)%mod<<endl;
    }

    return 0;
}