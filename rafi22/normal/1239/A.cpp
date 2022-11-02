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
        int n,m;
        cin>>n>>m;
        DP[1][0]=2;
        for(int i=2;i<=max(m,n);i++)
        {
            DP[i][0]=(DP[i-1][0]+DP[i-1][1])%mod;
            DP[i][1]=DP[i-1][0];
        }
        cout<<(DP[n][0]+DP[n][1]+DP[m][0]+DP[m][1]-2+mod)%mod;
    }

    return 0;
}