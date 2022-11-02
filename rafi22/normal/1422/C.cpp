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

int DP[100007][2];
int ile[100007];


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
        string s;
        cin>>s;
        s='#'+s;
        int ans;
        if(sz(s)>2) ans=s[1]-'0';
        else ans=0;
        DP[1][0]=s[1]-'0';
        int sum=0;
        for(int i=2;i<sz(s);i++)
        {
            DP[i][0]=(DP[i-1][0]*10+s[i]-'0')%mod;
            ile[i]=(i-1+ile[i-1])%mod;
            DP[i][1]=((sum+DP[i-1][1])*10+ile[i]*(s[i]-'0'))%mod;
            if(i<sz(s)-1) ans=(ans+DP[i][0])%mod;
            sum=(sum+DP[i-1][0])%mod;
        }
        ans=(ans+DP[sz(s)-1][1])%mod;
        cout<<ans;
    }

    return 0;
}