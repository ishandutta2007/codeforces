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

int inv[200007];
int fac[200007];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int npok(int n,int k)
{
    if(min(k,n)<0||k>n) return 0;
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}

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
        int n;
        cin>>n;
        fac[0]=1;
        for(int i=1;i<=2*n;i++) fac[i]=fac[i-1]*i%mod;
        inv[2*n]=pot(fac[2*n],mod-2);
        for(int i=2*n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        int c01=1,c10=1;
        int ile=1;
        int b=0,w=0;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            if(s[0]=='B') b++;
            if(s[1]=='B') b++;
            if(s[0]=='W') w++;
            if(s[1]=='W') w++;
            if(s=="??") ile=2*ile%mod;
            if(s=="BB"||s=="WW") ile=0;
            if(s[0]=='W') c01=0;
            if(s[0]=='B') c10=0;
            if(s[1]=='W') c10=0;
            if(s[1]=='B') c01=0;
        }
        if(max(b,w)>n) cout<<0;
        else cout<<(npok(2*n-b-w,n-b)-ile+mod+c01+c10)%mod;
    }

    return 0;
}