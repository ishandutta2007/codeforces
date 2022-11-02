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

int a[200007];
int b[200007];
int pw(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int fac[200007];
int inv[200007];
int ile[200007];

const int pot=1<<18;
int seg[2*pot+7];

void upd(int v,int x)
{
    v+=pot-1;
    seg[v]=x;
    while(v>1)
    {
        v/=2;
        seg[v]=(seg[2*v]+seg[2*v+1])%mod;
    }
}
int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(r<a||l>b) return 0;
    return (que(2*v,a,b,l,(l+r)/2)+que(2*v+1,a,b,(l+r)/2+1,r))%mod;
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
        fac[0]=1;
        for(int i=1;i<=200000;i++) fac[i]=fac[i-1]*i%mod;
        inv[200000]=pw(fac[200000],mod-2);
        for(int i=200000-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            ile[a[i]]++;
        }
        for(int i=1;i<=m;i++) cin>>b[i];
        int act=1;
        for(int i=1;i<=200000;i++)
        {
            act=act*inv[ile[i]]%mod;
            if(ile[i]>0) upd(i,fac[ile[i]]*inv[ile[i]-1]%mod);
        }
        int ans=0;
        bool tak=1;
        for(int i=1;i<=min(n,m);i++)
        {
            ans=(ans+fac[n-i]*act%mod*que(1,1,b[i]-1,1,pot)%mod)%mod;
            if(ile[b[i]]>0)
            {
                act=act*fac[ile[b[i]]]%mod*inv[ile[b[i]]-1]%mod;
                ile[b[i]]--;
                if(ile[b[i]]>0) upd(b[i],fac[ile[b[i]]]*inv[ile[b[i]]-1]%mod);
                else upd(b[i],0);
            }
            else
            {
                tak=0;
                break;
            }
        }
        if(tak&&n<m) ans=(ans+1)%mod;
        cout<<ans;
    }

    return 0;
}