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

int DP[3007][3007];

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
        swap(mod,mod1);
        string s,t;
        cin>>s>>t;
        int n=sz(s),m=sz(t);
        s='#'+s;
        t='#'+t;
        for(int i=1;i<=n+1;i++) DP[i][i-1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i+1;j++)
            {
                if(j>m||s[i]==t[j]) DP[j][j+i-1]=DP[j+1][j+i-1];
                if(j+i-1>m||s[i]==t[j+i-1]) DP[j][j+i-1]=(DP[j][j+i-1]+DP[j][j+i-2])%mod;
            }
        }
        int ans=0;
        for(int i=m;i<=n;i++) ans=(ans+DP[1][i])%mod;
        cout<<ans;
    }

    return 0;
}