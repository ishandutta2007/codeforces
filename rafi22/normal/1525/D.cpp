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

int DP[5007][5007];

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
        vector<int>v1,v2;
        v1.pb(0);
        v2.pb(0);
        int n,a;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(a==1) v1.pb(i);
            else v2.pb(i);
        }
        for(int i=1;i<sz(v1);i++)
        {
            int mn=DP[i-1][i-1];
            for(int j=i;j<sz(v2);j++)
            {
                DP[i][j]=mn+abs(v1[i]-v2[j]);
                mn=min(mn,DP[i-1][j]);
            }
        }
        int ans=inf;
        for(int i=sz(v1)-1;i<sz(v2);i++) ans=min(ans,DP[sz(v1)-1][i]);
        cout<<ans;
    }

    return 0;
}