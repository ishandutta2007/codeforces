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

const bool multi=1;

int inv[200007];
int silnia[200007];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int npok(int n,int k)
{
    if(k<0||k>n) return 0;
    return silnia[n]*inv[k]%mod*inv[n-k]%mod;
}

int L,R,n,l,r;

int check(int x)
{
    if(x==0||-x>=L&&x<=R) return 0;
    int P=min(n,r-x),S=max(1LL,l+x);
    if(n%2) return (npok(P-S+1,n/2-S+1)+npok(P-S+1,n/2-S+2))%mod;
    return npok(P-S+1,n/2-S+1);
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
        int ans;
        cin>>n>>l>>r;
        silnia[0]=1;
        for(int i=1;i<=n;i++) silnia[i]=silnia[i-1]*i%mod;
        inv[n]=pot(silnia[n],mod-2);
        for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        L=l-1;
        R=r-n;
        ans=min(-L,R)*npok(n,n/2)%mod*(1+n%2)%mod;
        set<int>S;
        for(int i=1;i<=n;i++)
        {
            S.insert(-(l-i));
            S.insert(r-i);
        }
        for(auto x:S) ans=(ans+check(x))%mod;
        cout<<ans<<endl;
    }

    return 0;
}