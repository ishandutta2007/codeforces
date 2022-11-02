#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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

unordered_map<int,vector<int>>ile;

int g[307][307];
int t[307][307];

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
        ile.clear();
        set<int>S;
        int n,m,a;
        cin>>n>>m;
        for(int i=1;i<=n*m;i++)
        {
            cin>>a;
            ile[a].pb(i);
            S.insert(a);
        }
        int it=0;
        for(auto x:S)
        {
            for(auto y:ile[x])
            {
                g[it/m][it%m]=y;
                t[it/m][it%m]=x;
                it++;
            }
        }
        for(int i=0;i<n;i++)
        {
            int poc=0;
            t[i][m]=inf;
            for(int j=1;j<=m;j++)
            {
                if(t[i][j]!=t[i][j-1])
                {
                    reverse(g[i]+poc,g[i]+j);
                    poc=j;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<j;k++) if(g[i][k]<g[i][j]) ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}