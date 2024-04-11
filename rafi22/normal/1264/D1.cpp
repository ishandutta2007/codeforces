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

int DP[2007][2007];
int pref[2007];
int pot[2007];

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
        string s;
        cin>>s;
        int n=sz(s);
        s='#'+s;
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]+(s[i]=='?');
        pot[0]=1;
        for(int i=1;i<=n;i++) pot[i]=pot[i-1]*2%mod;
        for(int k=2;k<=n;k++)
        {
            for(int l=1;l<=n-k+1;l++)
            {
                int r=l+k-1;
                if(s[l]==')'&&s[r]=='(') DP[l][r]=DP[l+1][r-1];
                else if(s[l]==')') DP[l][r]=DP[l+1][r];
                else if(s[r]=='(') DP[l][r]=DP[l][r-1];
                else if(s[l]=='('&&s[r]==')') DP[l][r]=(DP[l+1][r-1]+pot[pref[r-1]-pref[l]])%mod;
                else if(s[l]=='?'&&s[r]=='?') DP[l][r]=(pot[pref[r-1]-pref[l]]+DP[l+1][r]+DP[l][r-1])%mod;
                else if(s[l]=='?') DP[l][r]=(DP[l+1][r-1]+pot[pref[r-1]-pref[l]]+DP[l+1][r])%mod;
                else if(s[r]=='?') DP[l][r]=(DP[l+1][r-1]+pot[pref[r-1]-pref[l]]+DP[l][r-1])%mod;
               // cout<<l<<" "<<r<<" "<<DP[l][r]<<endl;
            }
        }
        cout<<DP[1][n];
    }

    return 0;
}