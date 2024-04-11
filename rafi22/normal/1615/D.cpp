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

vector<pair<int,bool>>G[200007];
vector<pair<int,int>>G1[200007];
bool odw[200007];
bool color[200007];
bool nie;

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G1[v])
    {
        if(!odw[u.st])
        {
            color[u.st]=color[v]^u.nd;
            dfs(u.st);
        }
        else if(color[u.st]!=(color[v]^u.nd)) nie=1;
    }
}
vector<pair<pair<int,int>,int>>ans;

void dfs1(int v,int o)
{
    for(auto u:G[v])
    {
        if(u.st==o) continue;
        if(!u.nd) ans.pb({{v,u.st},color[v]^color[u.st]});
        dfs1(u.st,v);
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
        int n,m,a,b,x;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            G1[i].clear();
            color[i]=0;
            odw[i]=0;
        }
        ans.clear();
        for(int i=1;i<n;i++)
        {
            cin>>a>>b>>x;
            G[a].pb({b,x!=-1});
            G[b].pb({a,x!=-1});
            if(x!=-1)
            {
                ans.pb({{a,b},x});
                bool c=__builtin_popcount(x)%2;
                G1[a].pb({b,c});
                G1[b].pb({a,c});
            }
        }
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>x;
            G1[a].pb({b,x});
            G1[b].pb({a,x});
        }
        nie=0;
        for(int i=1;i<=n;i++)
        {
            if(odw[i]) continue;
            dfs(i);
        }
        if(nie)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        dfs1(1,0);
        for(auto x:ans) cout<<x.st.st<<" "<<x.st.nd<<" "<<x.nd<<endl;
    }

    return 0;
}