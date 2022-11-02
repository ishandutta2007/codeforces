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

vector<pair<int,int>>G[100007];
int ans[100007];

void dfs(int v,int o,bool c)
{
    for(auto u:G[v])
    {
        if(u.st==o) continue;
        if(c) ans[u.nd]=3;
        else ans[u.nd]=2;
        dfs(u.st,v,!c);
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
        int n,a,b;
        cin>>n;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb({b,i});
            G[b].pb({a,i});
        }
        bool nie=0;
        for(int i=1;i<=n;i++) if(sz(G[i])>2) nie=1;
        if(nie)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(sz(G[i])!=1) continue;
            dfs(i,0,0);
            break;
        }
        for(int i=1;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}