#include <bits/stdc++.h>

//#define int long long
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
ll mod=1000000007;
int mod1=998244353;

const bool multi=0;

int DP[1000007][20][2];
int ile[27];
int ile1[27];
int ileP[27];
int ile1P[27];

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
        int n,mx=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x=i,c=0;
            while(x%2==0)
            {
                c++;
                x/=2;
            }
            mx=max(mx,c);
            ile[c]++;
            if(i%3==0) ile1[c]++;
        }
        for(int i=19;i>=0;i--) ileP[i]=ile[i]+ileP[i+1];
        for(int i=19;i>=0;i--) ile1P[i]=ile1[i]+ile1P[i+1];
        DP[1][mx][0]=1;
        DP[1][mx-1][1]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=mx;j>=0;j--)
            {
                if((1<<(mx-1))*3<=n)
                {
                    DP[i+1][j][0]=((ll)DP[i+1][j][0]+(ll)DP[i][j][1]*((ll)ileP[j]-(ll)ile1P[j]))%mod;
                    DP[i+1][j][1]=((ll)DP[i+1][j][1]+(ll)DP[i][j][1]*((ll)ile1P[j]-(ll)i))%mod;
                    if(j>0) DP[i+1][j-1][1]=((ll)DP[i+1][j-1][1]+(ll)DP[i][j][1]*(ll)ile1[j-1])%mod;
                }
                DP[i+1][j][0]=((ll)DP[i+1][j][0]+(ll)DP[i][j][0]*((ll)ileP[j]-(ll)i))%mod;
                if(j>0) DP[i+1][j-1][0]=((ll)DP[i+1][j-1][0]+(ll)DP[i][j][0]*(ll)ile[j-1])%mod;
            }
        }
        cout<<DP[n][0][0];
    }

    return 0;
}