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

const bool multi=1;

int DP[2007][2007];
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
        int n,m,k;
        cin>>n>>m>>k;
        int inv2=pot(2,mod-2);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                int x;
                if(i==j) x=k;
                else x=(DP[i-1][j]-DP[i-1][j-1]+mod)%mod*inv2%mod;
                DP[i][j]=(DP[i-1][j-1]+x)%mod;
            }
        }
        cout<<DP[n][m]<<endl;
    }

    return 0;
}