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

vector<int>G[200007];
int h[200007];
int id[200007];
int cnt[200007];

void dfs(int v,int o)
{
    id[v]=v;
    h[v]=1;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        if(h[u]+1>h[v])
        {
            id[v]=id[u];
            h[v]=h[u]+1;
        }
    }
    cnt[id[v]]++;
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
        int n,k,u,v;
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        dfs(1,0);
        vector<int>V;
        for(int i=2;i<=n;i++) if(sz(G[i])==1) V.pb(cnt[i]);
        sort(all(V));
        int w=0,r=0,b=n;
        while(sz(V)>0&&k>0)
        {
            b-=V.back();
            r++;
            w+=V.back()-1;
            V.pop_back();
            k--;
        }
        int ans=-inf;
        for(int i=0;i<=k;i++)
        {
            int W=w-i,R=r+i;
            int ile=0;
            if(W+R-b+1<0)
            {
                int x=-(W+R-b+1);
                ile=x/2+x%2;
            }
            ans=max(ans,(W+ile)*(R-(b-ile)));
        }
        cout<<ans<<endl;
    }

    return 0;
}