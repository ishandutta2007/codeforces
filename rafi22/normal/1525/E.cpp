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

int d[27][50007];
int ile[27];

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
        int n,m,ns=1,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) ns=ns*i%mod;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>d[i][j];
            }
        }
        for(int j=1;j<=m;j++)
        {
            memset(ile,0,sizeof ile);
            for(int i=1;i<=n;i++) ile[d[i][j]-1]++;
            int p=1,act=0;
            for(int i=n;i>0;i--)
            {
                act+=ile[i];
                p=p*act%mod;
                act--;
            }
            ans=(ans+(ns-p+mod)%mod*pot(ns,mod-2)%mod)%mod;
        }
        cout<<ans;
    }

    return 0;
}