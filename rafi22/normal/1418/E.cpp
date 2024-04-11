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

int pref[200007];

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
        mod=mod1;
        int n,m,a,b;
        cin>>n>>m;
        vector<int>d;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            d.pb(a);
        }
        d.pb(inf);
        d.pb(-inf);
        sort(d.begin(),d.end());
        for(int i=1;i<sz(d);i++) pref[i]=(pref[i-1]+d[i])%mod;
        while(m--)
        {
            cin>>a>>b;
            int l=lower_bound(d.begin(),d.end(),b)-d.begin(),ans=0;
            int k=n-l+1;
            if(k>a) ans=(pref[n]-pref[l-1]+mod)%mod*(k-a)%mod*pot(k,mod-2)%mod;
            if(k>=a&&l>1) ans=(ans+pref[l-1]*(k-a+1)%mod*pot(k+1,mod-2)%mod)%mod;
            cout<<ans<<endl;
        }
    }

    return 0;
}