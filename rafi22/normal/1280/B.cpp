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

char g[107][107];

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
        int ans=inf;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
                if(g[i][j]=='A')
                {
                    ans=min(ans,4LL);
                    if(i==1||i==n||j==1||j==m)
                    {
                        ans=min(ans,3LL);
                        if((i==1||i==n)&&(j==1||j==m))
                        {
                            ans=min(ans,2LL);
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            bool is=1;
            for(int j=1;j<=m;j++) if(g[i][j]=='P') is=0;
            if(is)
            {
                if(i==1||i==n) ans=min(ans,1LL);
                ans=min(ans,2LL);
            }
        }
        for(int j=1;j<=m;j++)
        {
            bool is=1;
            for(int i=1;i<=n;i++) if(g[i][j]=='P') is=0;
            if(is)
            {
                if(j==1||j==m) ans=min(ans,1LL);
                ans=min(ans,2LL);
            }
        }
        bool is=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(g[i][j]=='P') is=0;
        if(is) ans=0;
        if(ans==inf) cout<<"MORTAL"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}