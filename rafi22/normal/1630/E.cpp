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

int fac[1000007];
int inv[1000007];
int ile[1000007];
int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int D[1000007];
int C[1000007];
int C1[1000007];
int B[1000007];

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
        int n,x;
        cin>>n;
        int invn=pot(n,mod-2);
        for(int i=1;i<=n;i++)
        {
            D[i]=1;
            B[i]=0;
            C[i]=0;
            C1[i]=0;
            ile[i]=0;
        }
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
        inv[n]=pot(fac[n],mod-2);
        for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            ile[x]++;
        }
        int ans=0,c=1,res;
        for(int i=1;i<=n;i++) c=c*inv[ile[i]]%mod;
        res=fac[n]*c%mod;
        for(int i=1;i<=n;i++)
        {
            if(ile[i]>=2)
            {
                ans=(ans+n*fac[n-2]%mod*c%mod*ile[i]%mod*(ile[i]-1))%mod;
            }
        }
        int b=0;
        for(int i=1;i<=n;i++)
        {
            if(ile[i]) b++;
            for(int j=1;j*j<=ile[i];j++)
            {
                if(ile[i]%j!=0) continue;
                D[j]=D[j]*inv[ile[i]/j]%mod;
                B[j]++;
                if(j!=ile[i]/j)
                {
                    D[ile[i]/j]=D[ile[i]/j]*inv[j]%mod;
                    B[ile[i]/j]++;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=ile[i];j++)
            {
                if(ile[i]%j!=0) continue;
                //cout<<j<<endl;
                if(j!=n) C[j]=(C[j]+n*fac[n/j-2]%mod*D[j]%mod*(ile[i]/j)%mod*(ile[i]/j-1))%mod;
                if(j!=ile[i]/j)
                {
                    int J=ile[i]/j;
                    if(J!=n) C[J]=(C[J]+n*fac[n/J-2]%mod*D[J]%mod*(ile[i]/J)%mod*(ile[i]/J-1))%mod;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            C1[i]=fac[n/i]*D[i]%mod;
        }
        C[n]=n;
        for(int i=1;i<n;i++)
        {
            int k=__gcd(i,n);
            if(B[n/k]==b)
            {
                ans=(ans+C[n/k])%mod;
               // cout<<i<<" "<<k<<" "<<C[n/k]<<endl;
                res=(res+C1[n/k])%mod;
            }
        }
        res=res*invn%mod;
        ans=ans*invn%mod;
        ans=ans*pot(res,mod-2)%mod;
        if(B[n]==b) cout<<1<<endl;
        else cout<<(n-ans+mod)%mod<<endl;
    }

    return 0;
}