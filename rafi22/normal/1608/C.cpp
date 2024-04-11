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

vector<int>G[100007];
vector<int>RG[100007];
int scc[100007];
bool odw[100007];
bool bad[100007];
vector<int>stos;

void edge(int u,int v)
{
    G[u].pb(v);
    RG[v].pb(u);
}
void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(odw[u]) continue;
        dfs(u);
    }
    stos.pb(v);
}
int c=0;
void dfs1(int v)
{
    scc[v]=c;
    for(auto u:RG[v])
    {
        if(scc[u]!=c&&scc[u]) bad[c]=1;
        if(scc[u]) continue;
        dfs1(u);
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
        int n;
        cin>>n;
        vector<pair<int,int>>a(n);
        vector<pair<int,int>>b(n);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i-1].st;
            a[i-1].nd=i;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>b[i-1].st;
            b[i-1].nd=i;
        }
        sort(all(a));
        sort(all(b));
        for(int i=0;i<n-1;i++)
        {
            edge(a[i+1].nd,a[i].nd);
            edge(b[i+1].nd,b[i].nd);
        }
        for(int i=1;i<=n;i++) if(!odw[i]) dfs(i);
        reverse(stos.begin(),stos.end());
        for(auto i:stos)
        {
            if(!scc[i])
            {
                c++;
                dfs1(i);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!bad[scc[i]]) cout<<1;
            else cout<<0;
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            RG[i].clear();
            odw[i]=0;
            scc[i]=0;
            bad[i]=0;
        }
        stos.clear();
        c=0;
    }

    return 0;
}