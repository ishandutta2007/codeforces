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
int a[100007];
int b[100007];
int DP[100007][3];

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
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++)
        {
            DP[i][0]=max(max(DP[i-1][0],DP[i-1][1]),DP[i-1][2]);
            DP[i][1]=a[i]+max(DP[i-1][0],DP[i-1][2]);
            DP[i][2]=b[i]+max(DP[i-1][0],DP[i-1][1]);
        }
        cout<<max(max(DP[n][0],DP[n][1]),DP[n][2]);
    }

    return 0;
}