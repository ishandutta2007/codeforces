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

int c[300007];
int pref[300007];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}

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
        for(int i=1;i<=n;i++) cin>>c[i];
        sort(c+1,c+n+1,greater<int>());
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]+c[i];
        int inv=pot(n,mod-2);
        for(int k=1;k<=n;k++)
        {
            int sum=0;
            for(int i=k+1,s=1;i<=n;i+=k,s++) sum=(sum+(pref[min(n,i+k-1)]-pref[i-1])%mod*s)%mod;
            cout<<sum*inv%mod<<" ";
        }
    }

    return 0;
}