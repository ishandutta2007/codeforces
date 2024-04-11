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

int x[200007];
int y[200007];
int pref[200007];
int xd[200007];
int DP[200007];
int S[200007];

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
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            bool s;
            cin>>x[i]>>y[i]>>s;
            int l=1,r=i,sr,L=i;
            while(l<=r)
            {
                sr=(l+r)/2;
                if(x[sr]>y[i])
                {
                    L=sr;
                    r=sr-1;
                }
                else l=sr+1;
            }
            if(L==i) S[i]=i;
            else S[i]=S[L];
            DP[i]=((pref[i-1]-pref[S[i]-1]+xd[L]+x[L]-y[i]+x[i]-x[S[i]])%mod+mod)%mod;
            pref[i]=(pref[i-1]+DP[i])%mod;
            xd[i]=((xd[L]-DP[i]+x[L]-y[i])%mod+mod)%mod;
            if(s) ans=(ans+DP[i])%mod;
        }
        ans=(ans+x[n]+1)%mod;
        cout<<ans;
    }

    return 0;
}