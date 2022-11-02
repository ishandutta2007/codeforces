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

int qpow(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1) ret=1LL*x*ret%mod;
        x=1LL*x*x%mod,y>>=1;
    }
    return ret;
}

int pot[200007];
int cnta[200007];
int cntab[200007];
int cntabc[200007];

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
        int n, k=0;
        cin>>n;
        pot[0]=1;
        for(int i=1;i<=n;i++) pot[i]=pot[i-1]*3%mod;
        string s;
        cin>>s;
        s='#'+s;
        for(int i=1;i<=n;i++) if(s[i]=='?') k++;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='?') cnta[i]=(cnta[i-1]+pot[k-1])%mod;
            else if(s[i]=='a') cnta[i]=(cnta[i-1]+pot[k])%mod;
            else cnta[i]=cnta[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='?') cntab[i]=(cntab[i-1]+cnta[i-1]*qpow(3,mod-2)%mod)%mod;
            else if(s[i]=='b') cntab[i]=(cntab[i-1]+cnta[i-1])%mod;
            else cntab[i]=cntab[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='?') cntabc[i]=(cntabc[i-1]+cntab[i-1]*qpow(3,mod-2)%mod)%mod;
            else if(s[i]=='c') cntabc[i]=(cntabc[i-1]+cntab[i-1])%mod;
            else cntabc[i]=cntabc[i-1];
        }
        cout<<cntabc[n];
    }

    return 0;
}