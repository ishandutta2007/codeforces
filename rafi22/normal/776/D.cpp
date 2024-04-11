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

const bool multi=0;

int a[100007];
vector<int>v[100007];
vector<int>G[200007];
vector<int>post;
bool odw[200007];
bool ans[200007];
void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v]) if(!odw[u]) dfs(u);
    post.pb(v);
}
void ustaw(int v)
{
    ans[v]=1;
    for(auto u:G[v]) if(!ans[u]) ustaw(u);
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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++)
        {
            int k,b;
            cin>>k;
            while(k--)
            {
                cin>>b;
                v[b].pb(i);
            }
        }
        for(int i=1;i<=n;i++)
        {
            G[2*v[i][0]].pb(2*v[i][1]+1^a[i]);
            G[2*v[i][0]+1].pb(2*v[i][1]^a[i]);
            G[2*v[i][1]].pb(2*v[i][0]+1^a[i]);
            G[2*v[i][1]+1].pb(2*v[i][0]^a[i]);
        }
        for(int i=2;i<=2*m+1;i++) if(!odw[i]) dfs(i);
        for(auto v:post) if(!ans[v]&&!ans[v^1]) ustaw(v);
        for(int i=1;i<=m;i++)
        {
            if(ans[2*i]==ans[2*i+1])
            {
                cout<<"NO";
                return 0;
            }
        }
        cout<<"YES";
    }

    return 0;
}