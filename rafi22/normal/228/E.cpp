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
vector<int>G[407];
bool odw[407];
bool ans[407];
vector<int>post;

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u]) dfs(u);
    }
    post.pb(v);
}
void ustaw(int v)
{
    ans[v]=1;
    for(auto u:G[v]) if(!ans[u]) ustaw(u);
}
void gg()
{
    cout<<"Impossible";
    exit(0);
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
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if(c)
            {
                G[2*a].pb(2*b);
                G[2*b].pb(2*a);
                G[2*a+1].pb(2*b+1);
                G[2*b+1].pb(2*a+1);
            }
            else
            {
                G[2*a].pb(2*b+1);
                G[2*b+1].pb(2*a);
                G[2*a+1].pb(2*b);
                G[2*b].pb(2*a+1);
            }
        }
        for(int i=2;i<=2*n+1;i++) if(!odw[i]) dfs(i);
        for(auto v:post) if(!ans[v]&&!ans[v^1]) ustaw(v);
        vector<int>vec;
        for(int i=1;i<=n;i++)
        {
            if(ans[2*i]==ans[2*i+1]) gg();
            if(ans[2*i]) vec.pb(i);
        }
        cout<<sz(vec)<<endl;
        for(auto x:vec) cout<<x<<" ";
    }

    return 0;
}