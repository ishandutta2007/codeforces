#include <bits/stdc++.h>

//#define int long long
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

const int N=83;

int DP[N][N][N*N/2];

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
        int n,x;
        cin>>n;
        vector<int>a;
        a.pb(0);
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x==1) a.pb(i);
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int l=0;l<=n*(n-1)/2;l++)
                {
                    DP[i][j][l]=mod;
                }
            }
        }
        for(int c=0;c<=n*(n-1)/2;c++) DP[0][0][c]=0;

        for(int c=0;c<=n*(n-1)/2;c++)
        {
            int ans=mod;
            for(int i=1;i<sz(a);i++)
            {
                for(int j=i;j<=n-(sz(a)-i-1);j++)
                {
                    for(int k=i-1;k<j;k++)
                    {
                        if(c-abs(a[i]-j)>=0) DP[i][j][c]=min(DP[i][j][c],DP[i-1][k][c-abs(a[i]-j)]+(j-k-1)*(j-k-2)/2);
                    }
                    if(i==sz(a)-1) ans=min(ans,DP[i][j][c]+(n-j)*(n-j-1)/2);
                }
            }
            if(sz(a)==1) cout<<0<<" ";
            else cout<<(n-sz(a)+1)*(n-sz(a))/2-ans<<" ";
        }
    }

    return 0;
}