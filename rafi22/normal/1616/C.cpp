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

int a[107];
int DP[107][107];

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
        for(int i=1;i<=n;i++) for(int j=1;j<i;j++) DP[i][j]=2;
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                ans=max(ans,DP[i][j]);
                for(int l=i+1;l<=n;l++)
                {
                    if((a[i]-a[j])*(l-i)==(a[l]-a[i])*(i-j)) DP[l][i]=max(DP[l][i],DP[i][j]+1);
                }
            }
        }
        cout<<n-ans<<endl;
    }

    return 0;
}