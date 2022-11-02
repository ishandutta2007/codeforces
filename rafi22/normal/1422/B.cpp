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

const bool multi=1;

int a[107][107];
map<int,int>ile;

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
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        int ans=0;
        for(int i=1;i<=n/2;i++)
        {
            for(int j=1;j<=m/2;j++)
            {
                vector<int>v;
                v.pb(a[i][j]);
                v.pb(a[i][m-j+1]);
                v.pb(a[n-i+1][j]);
                v.pb(a[n-i+1][m-j+1]);
               // cout<<i<<" "<<j<<" "<<n-i+1<<" "<<m-j+1<<endl;
                sort(v.begin(),v.end());
                int med=v[1];
                ans+=abs(a[i][j]-med)+abs(a[i][m-j+1]-med)+abs(a[n-i+1][j]-med)+abs(a[n-i+1][m-j+1]-med);
            }
        }
        if(n%2)
        {
            for(int i=1;i<=m/2;i++) ans+=abs(a[n/2+1][i]-a[n/2+1][m-i+1]);
        }
        if(m%2)
        {
            for(int i=1;i<=n/2;i++) ans+=abs(a[i][m/2+1]-a[n-i+1][m/2+1]);
        }
        cout<<ans<<endl;
    }

    return 0;
}