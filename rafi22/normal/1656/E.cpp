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
int d[100007];
int sum=0;

void dfs(int v,int o,bool x)
{
    int c=0;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v,!x);
        c++;
    }
    if(x) d[v]=-1-c;
    else d[v]=1+c;
    if(v!=1) sum+=d[v];
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
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
        }
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        sum=0;
        dfs(1,0,0);
        d[1]=-sum;
        for(int i=1;i<=n;i++) cout<<d[i]<<" ";
        cout<<endl;
    }

    return 0;
}