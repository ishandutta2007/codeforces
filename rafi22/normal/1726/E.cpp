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

const int N=300007;

int fac[N];
int inv[N];
int p[N];
int DP[N];

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
     /*   vector<int>q(n),w(n);
        for(int i=1;i<=n;i++) q[i-1]=i;
        int res=0;
        while(true)
        {
            bool ok=1;
            for(int i=0;i<n;i++) w[q[i]-1]=i+1;
            for(int i=0;i<n;i++) if(abs(q[i]-w[i])>1) ok=0;
            res+=ok;
            if(ok)
            {
                for(int i=0;i<n;i++) cout<<q[i]<<" ";
                cout<<endl;
                for(int i=0;i<n;i++) cout<<w[i]<<" ";
                cout<<endl;
                cout<<endl;
            }
            if(!next_permutation(all(q))) break;
        }
*/
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
        inv[n]=pot(fac[n],mod-2);
        for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        DP[0]=1;
        DP[1]=1;
        for(int i=2;i<=n;i++) DP[i]=(DP[i-1]+(i-1)*DP[i-2])%mod;
        p[0]=1;
        for(int i=1;i<=n;i++) p[i]=p[i-1]*2%mod;
        int ans=0;
        for(int k=0;2*k<=n;k+=2)
        {
            int P=fac[k]*inv[k/2]%mod*pot(p[k/2],mod-2)%mod;
            ans=(ans+P*npok(n-k,k)%mod*DP[n-2*k]%mod*p[k/2])%mod;
           // cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }

    return 0;
}