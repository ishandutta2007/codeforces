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

bool is[507][507];
bool g[507][507];

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
        char c;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='B') g[i][j]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                is[i][j]=(g[i][j]+g[i+1][j]+g[i][j+1]+g[i+1][j+1])%2;
                ans+=is[i][j];
            }
        }
        bool b=0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                b|=(is[i][j]&&is[i][m]&&is[n][j]&&is[n][m]);
            }
        }
        cout<<ans-b;
    }

    return 0;
}