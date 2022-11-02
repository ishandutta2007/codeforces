#include <bits/stdc++.h>

//#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=100001,D=51;

vector<int>G[N],RG[N];
bool odw[N*D];
bool odw1[N*D];
int scc[N*D];
int ile[N*D];
char is[N][D];
vector<int>post;

int cnt[N*D];
int DP[N*D];

int d;

void dfs(int v)
{
    odw[v]=1;
    for(auto x:G[v/d+1])
    {
        int u=(x-1)*d+(v%d+1)%d;
        if(odw[u]) continue;
        dfs(u);
    }
    post.pb(v);
}
int it,r;
set<int>S;
void dfs1(int v)
{
    scc[v]=it;
    if(is[v/d+1][v%d]=='1') S.insert(v/d+1);
    if(v==0) r=it;
    for(auto x:RG[v/d+1])
    {
        int u=(x-1)*d+(v%d-1+d)%d;
        if(scc[u]==0) dfs1(u);
        else if(scc[u]!=it)
        {
           // SG[it].pb(scc[u]);
            ile[scc[u]]++;
        }
    }
}
void dfs2(int v)
{
    odw1[v]=1;
    for(auto x:RG[v/d+1])
    {
        int u=(x-1)*d+(v%d-1+d)%d;
        if(scc[u]==scc[v])
        {
            if(!odw1[u]) dfs2(u);
        }
        else DP[scc[v]]=max(DP[scc[v]],cnt[scc[v]]+DP[scc[u]]);
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
        cin>>n>>m>>d;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            RG[b].pb(a);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<d;j++) cin>>is[i][j];
        }
        for(int i=0;i<n*d;i++) if(!odw[i]) dfs(i);
        reverse(post.begin(),post.end());
        for(auto v:post)
        {
            if(scc[v]) continue;
            it++;
            S.clear();
            dfs1(v);
            cnt[it]=sz(S);
            //cout<<it<<" "<<cnt[it]<<endl;
            if(r==it) DP[it]=sz(S);
            else DP[it]=-inf;
        }
        for(auto v:post)
        {
            if(odw1[v]) continue;
            dfs2(v);
        }
        int ans=0;
        for(int i=1;i<=it;i++) ans=max(ans,DP[i]);
        cout<<ans;
    }

    return 0;
}