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

vector<int>V[2];
vector<int>G[200007];
bool color[200007];
bool C[20];
int ans[200007];

void dfs(int v,int o)
{
    V[color[v]].pb(v);
    for(auto u:G[v])
    {
        if(u==o) continue;
        color[u]=!color[v];
        dfs(u,v);
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
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1,-1);
        if(sz(V[0])>sz(V[1])) swap(V[0],V[1]);
        memset(C,0,sizeof C);
        for(int i=18;i>=0;i--) if((sz(V[0])&(1<<i))) C[i]=1;
        for(int i=18;i>=0;i--)
        {
            for(int j=(1<<i);j<min(n+1,(1LL<<(i+1)));j++)
            {
                ans[V[!C[i]].back()]=j;
                V[!C[i]].pop_back();
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
            color[i]=0;
            G[i].clear();
        }
        cout<<endl;
    }

    return 0;
}