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

int d[200007];
int DP[200007];
vector<int>G[200007];
deque<int>q;


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
        int n,m,a,b;
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            cin>>a>>b;
            G[a].pb(b);
        }
        for(int i=1; i<=n; i++) d[i]=-1;
        d[1]=0;
        q.pb(1);
        while(!q.empty())
        {
            int v=q[0];
            q.pop_front();
            for(auto u:G[v])
            {
                if(d[u]==-1)
                {
                    d[u]=d[v]+1;
                    q.pb(u);
                }
            }
        }
        vector<pair<int,int>> order;
        for(int i=1;i<=n;i++)
        {
            order.pb({d[i],i});
            DP[i]=d[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(auto u:G[i]) DP[i]=min(DP[i],d[u]);
        }
        sort(order.begin(),order.end(),greater<pair<int,int>>());
        for(auto v:order)
        {
            for(auto u:G[v.nd])
            {
                if(d[u]>d[v.nd]) DP[v.nd]=min(DP[v.nd],DP[u]);
            }
        }
        for(int i=1;i<=n;i++) cout<<DP[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            DP[i]=0;
            G[i].clear();
        }
    }

    return 0;
}