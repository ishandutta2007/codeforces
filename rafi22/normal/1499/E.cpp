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

int DP[1007][1007][2][4];
int odejm[1007][1007];


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
        string a,b;
        cin>>a>>b;
        a='#'+a;
        b='#'+b;
        int ans=0;
        for(int i=0;i<sz(a);i++)
        {
            for(int j=0;j<sz(b);j++)
            {
                if(i>0)
                {
                    if(a[i]!=a[i-1])
                    {
                        DP[i][j][0][1]=(DP[i][j][0][1]+DP[i-1][j][0][1])%mod1;
                        DP[i][j][0][3]=(DP[i][j][0][3]+DP[i-1][j][0][3])%mod1;
                        DP[i][j][0][3]=(DP[i][j][0][3]+DP[i-1][j][0][2])%mod1;
                    }
                    if(a[i]!=b[j])
                    {
                        DP[i][j][0][3]=(DP[i][j][0][3]+DP[i-1][j][1][3])%mod1;
                        DP[i][j][0][3]=(DP[i][j][0][3]+DP[i-1][j][1][2])%mod1;
                    }
                }
                if(j>0)
                {
                    if(b[j]!=b[j-1])
                    {
                        DP[i][j][1][2]=(DP[i][j][1][2]+DP[i][j-1][1][2])%mod1;
                        DP[i][j][1][3]=(DP[i][j][1][3]+DP[i][j-1][1][3])%mod1;
                        DP[i][j][1][3]=(DP[i][j][1][3]+DP[i][j-1][1][1])%mod1;
                    }
                    if(b[j]!=a[i])
                    {
                        DP[i][j][1][3]=(DP[i][j][1][3]+DP[i][j-1][0][3])%mod1;
                        DP[i][j][1][3]=(DP[i][j][1][3]+DP[i][j-1][0][1])%mod1;
                    }
                }
                if(i>0) DP[i][j][0][1]=(DP[i][j][0][1]+1)%mod1;
                if(j>0) DP[i][j][1][2]=(DP[i][j][1][2]+1)%mod1;
                if(i>0&&j>0) ans=(ans+DP[i][j][0][3]+DP[i][j][1][3])%mod1;
            }
        }
        cout<<ans;
    }

    return 0;
}