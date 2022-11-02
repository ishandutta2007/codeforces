#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

vector<pair<int,int>>G[200007];
vector<int>G1[200007];
bool color[200007];
bool odw[200007];
int ord[200007];

void gg()
{
    cout<<"NO";
    exit(0);
}

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u.st])
        {
            color[u.st]=!color[v];
            dfs(u.st);
        }
        else if(color[u.st]==color[v]) gg();
    }
}
vector<int>topsort;
bool odw1[200007];

void dfs1(int v)
{
    odw1[v]=1;
    for(auto u:G1[v])
    {
        if(!odw1[u]) dfs1(u);
    }
    topsort.pb(v);
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
        int n,m,a,b,c;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>c>>a>>b;
            G[a].pb({b,c});
            G[b].pb({a,c});
        }
        for(int i=1;i<=n;i++) if(!odw[i]) dfs(i);
        for(int i=1;i<=n;i++)
        {
            for(auto u:G[i])
            {
                if(u.nd==1&&color[i]==1) G1[i].pb(u.st);
                if(u.nd==2&&color[i]==0) G1[i].pb(u.st);
            }
        }
        for(int i=1;i<=n;i++) if(!odw1[i]) dfs1(i);
        reverse(all(topsort));
        int it=0;
        for(auto x:topsort) ord[x]=++it;
        for(int i=1;i<=n;i++) for(auto u:G1[i]) if(ord[i]>ord[u]) gg();
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==1) cout<<"L ";
            else cout<<"R ";
            cout<<ord[i]<<endl;
        }
    }

    return 0;
}