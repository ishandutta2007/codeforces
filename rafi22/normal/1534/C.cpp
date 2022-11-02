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

int a[400007];
int b[400007];
vector<int>G[400007];
bool odw[400007];

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(odw[u]) continue;
        dfs(u);
    }
}

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
        int n,ile=0;
        cin>>n;
        bool nie=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i]==b[i]) nie=1;
           G[a[i]].pb(b[i]);
           G[b[i]].pb(a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(!odw[i])
            {
                ile++;
                dfs(i);
            }
        }
        if(nie) cout<<0<<endl;
        else
        {
            int ans=1;
            for(int i=0;i<ile;i++) ans=ans*2%mod;
            cout<<ans<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            odw[i]=0;
            G[i].clear();
        }
    }

    return 0;
}