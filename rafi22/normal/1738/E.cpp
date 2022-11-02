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

int a[100007];
int r[100007];
int L[100007];
int R[100007];

int fac[100007];
int inv[100007];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int npok(int n,int k)
{
    if(min(k,n)<0||k>n) return 0;
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}

signed main()
{
    mod=mod1;
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
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
        inv[n]=pot(fac[n],mod-2);
        for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        int S=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            S+=a[i];
        }
        int s1=0,s2=0;
        int j=n+1,k=n+1;
        for(int i=1;i<=n;i++)
        {
            s1+=a[i];
            while(s2<s1&&j-1>i)
            {
                j--;
                if(a[j]!=0) k=j;
                s2+=a[j];
            }
            if(s1==s2&&a[i]!=0&&s1<=S/2) r[i]=k;
            else r[i]=-1;
        }
        for(int i=1;i<=n;i++) if(a[i]==0) L[i]=L[i-1]+1;
        for(int i=n;i>0;i--) if(a[i]==0) R[i]=R[i+1]+1;
        if(R[1]==n)
        {
            int p=1;
            for(int i=1;i<n;i++) p=p*2%mod;
            cout<<p<<endl;
            for(int i=1; i<=n; i++)
            {
                L[i]=0;
                R[i]=0;
                r[i]=0;
            }
            continue;
        }
        int ans=1,act=1;
        for(int i=1;i<=n;i++)
        {
            if(r[i]!=-1)
            {
                if(i+R[i+1]==r[i]-1)
                {
                    int w=1;
                    for(int j=1;j<=R[i+1]+1;j++) w=w*2%mod;
                    w=(w-1+mod)%mod;
                    ans=(ans+act*w)%mod;
                }
                else
                {
                    int w=0;
                    int p=R[i+1],q=L[r[i]-1];
                    for(int j=0;j<=min(p,q);j++) w=(w+npok(p,j)*npok(q,j))%mod;
                    int w1=0;
                    for(int j=1;j<=min(p,q)+1;j++) w1=(w1+npok(p+1,j)*npok(q+1,j))%mod;
                    ans=(ans+act*w1)%mod;
                    act=act*(w1+1)%mod;
                }
            }
        }
        int p=R[1],q=L[n];
        int w=0;
        for(int j=0;j<=min(p,q);j++) w=(w+npok(p,j)*npok(q,j))%mod;
        cout<<ans*w%mod<<endl;
        for(int i=1;i<=n;i++)
        {
            L[i]=0;
            R[i]=0;
            r[i]=0;
        }
    }

    return 0;
}