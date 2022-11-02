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
vector<int>G[200007];
int DP[200007];
int mx[200007];
int mn[200007];
int add[200007];
int sub[200007];
int a[200007];
int d[200007];

void dfs(int v)
{
    for(auto u:G[v])
    {
        d[u]=d[v]+1;
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
        int n,x;
        cin>>n;
        for(int i=2;i<=n;i++)
        {
            cin>>x;
            G[x].pb(i);
        }
        for(int i=2;i<=n;i++) cin>>a[i];
        dfs(1);
        vector<pair<int,int>>vec;
        for(int i=1;i<=n;i++) vec.pb({d[i],i});
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        for(int i=0;i<=n+3;i++)
        {
            mx[i]=0;
            mn[i]=inf;
            add[i]=-inf;
            sub[i]=-inf;
        }
        for(auto v:vec)
        {
            DP[v.nd]=0;
            int mxC=0,mnC=inf;
            for(auto u:G[v.nd])
            {
                DP[v.nd]=max(DP[v.nd],DP[u]+max(mx[v.st+1]-a[u],a[u]-mn[v.st+1]));
                mxC=max(mxC,a[u]);
                mnC=min(mnC,a[u]);
            }
            DP[v.nd]=max(DP[v.nd],add[v.st+1]-mnC);
            DP[v.nd]=max(DP[v.nd],sub[v.st+1]+mxC);
            //cout<<v.nd<<" "<<DP[v.nd]<<" "<<mxC<<" "<<mnC<<endl;
            add[v.st]=max(add[v.st],DP[v.nd]+a[v.nd]);
            sub[v.st]=max(sub[v.st],DP[v.nd]-a[v.nd]);
            mx[v.st]=max(mx[v.st],a[v.nd]);
            mn[v.st]=min(mn[v.st],a[v.nd]);
        }
        cout<<DP[1]<<endl;
        for(int i=1;i<=n;i++) G[i].clear();
    }

    return 0;
}