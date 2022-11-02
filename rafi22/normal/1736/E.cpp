#include <bits/stdc++.h>
#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

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
int inf=1000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=507;

int DP[N][N][N];
int a[N];
int mx[N][N];

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) for(int l=0;l<=n+1;l++) DP[i][j][l]=-inf;
        int ans=0;
        DP[0][0][0]=0;
        a[0]=-inf;
        for(int i=0;i<=n;i++)
        {
            for(int k=0;k<=n;k++) for(int j=0;j<=n;j++) mx[k][j]=-inf;
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    DP[i+1][j][k]=max(DP[i+1][j][k],DP[i][j][k]+a[j]);
                    ans=max(ans,DP[i][j][k]);
                    mx[k+1][j+1]=max(mx[k+1][j+1],DP[i][j][k]);
                }
            }
            for(int k=0;k<=n;k++)
            {
                for(int j=1;j<=n;j++)
                {
                    mx[k][j]=max(mx[k][j],mx[k][j-1]);
                    if(j>i&&k-(j-i-1)>=0) DP[i+1][j][k-(j-i-1)]=max(DP[i+1][j][k-(j-i-1)],mx[k][j]+a[j]);
                }
            }
        }
        cout<<ans;
    }

    return 0;
}