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

const bool multi=0;

int DP[2][107][107*107];
int a[107];
int b[107];

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
        int n,s=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i];
            s+=b[i];
        }
        for(int j=0;j<=n;j++) for(int l=0;l<=10000;l++) DP[0][j][l]=-inf;
        DP[0][0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++) for(int l=0;l<=10000;l++) DP[i%2][j][l]=-inf;
            DP[i%2][0][0]=0;
            for(int j=1;j<=n;j++)
            {
                for(int l=0;l<=10000;l++)
                {
                    DP[i%2][j][l]=DP[(i-1)%2][j][l];
                    if(l-a[i]>=0) DP[i%2][j][l]=max(DP[i%2][j][l],DP[(i-1)%2][j-1][l-a[i]]+b[i]);
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            int ans=0;
            for(int l=0;l<=10000;l++) ans=max(ans,min(s+DP[n%2][j][l],2*l));
            if(ans%2) cout<<ans/2<<".5"<<" ";
            else cout<<ans/2<<" ";
        }
    }

    return 0;
}