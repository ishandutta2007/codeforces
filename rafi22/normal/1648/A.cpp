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

vector<int>a[100007];
int ile[100007];
int sum[100007];
int ile1[100007];
int sum1[100007];

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
        for(int i=1;i<=n;i++)
        {
            a[i].resize(m+3);
            for(int j=1;j<=m;j++) cin>>a[i][j];
        }
        int ans=0;
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
            {
                ans+=ile[a[i][j]]*j-sum[a[i][j]];
                ile[a[i][j]]++;
                sum[a[i][j]]+=j;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                ans+=ile1[a[i][j]]*i-sum1[a[i][j]];
                ile1[a[i][j]]++;
                sum1[a[i][j]]+=i;
            }
        }
        cout<<ans;
    }

    return 0;
}