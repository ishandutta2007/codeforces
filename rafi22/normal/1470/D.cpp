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

bool odw[300007];
int color[300007];
vector<int> G[300007];
deque<int> q,ans;

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v]) if(!odw[u]) dfs(u);
}

void mark2(int v)
{
    color[v]=2;
    for(auto u:G[v])
    {
        if(color[u]==0) q.pb(u);
    }
}
void mark1(int v)
{
    color[v]=1;
    for(auto u:G[v])
    {
        if(color[u]==0) mark2(u);
        if(color[u]==1) exit(2137);
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
        int n,m,a,b;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1);
        bool ok=1;
        for(int i=1;i<=n;i++) ok&=odw[i];
        if(!ok) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            q.pb(1);
            while(!q.empty())
            {
                int u=q[0];
                q.pop_front();
                if(color[u]) continue;
                mark1(u);
            }
            for(int i=1;i<=n;i++) if(color[i]==1) ans.pb(i);
            cout<<sz(ans)<<endl;
            for(auto x:ans) cout<<x<<" ";
            cout<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            odw[i]=0;
            color[i]=0;
            G[i].clear();
        }
        q.clear();
        ans.clear();
    }

    return 0;
}