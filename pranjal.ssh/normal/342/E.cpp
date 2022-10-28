#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define ntr(x,it) for(auto it = x.rbegin();it!=x.rend();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define MP make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)

int n,m;
vector<set<int> > g;
vi p;
vi l;
vi sub;
vvi dp;
void dfs(int u)
{
    
    tr(g[u],it)
    {
        if(*it==p[u])continue;
        p[*it]=u;
        l[*it]=l[u]+1;
        dfs(*it);
        
    }
}

void preprocess()
{
    p[0]=-1;
    l[0]=0;
    dfs(0);
    dp.resize(20);
    FOR(i,0,19)dp[i].resize(n);
    
    FOR(i,0,n-1)
    {
        for(int j=0;(1<<j)<n;++j)
        dp[j][i]=-1;
    }
    FOR(i,0,n-1)
    dp[0][i]=p[i];
    
    for(int j=1;(1<<j)<n;++j)
    FOR(i,0,n-1)
    if(dp[j-1][i]!=-1)
    dp[j][i]=dp[j-1][dp[j-1][i]];
    
}
inline int lca(int u, int v)
{   
    if(l[u]<l[v])u^=v^=u^=v;
    
    int LOG;
    for(LOG=1;(1<<LOG)<=l[u];++LOG);--LOG;
    
    NFOR(i,LOG,0)
    if(l[u]-(1<<i)>=l[v])
    u=dp[i][u];
    
    if(u==v)return u;
    
    NFOR(i,LOG,0)
    if(dp[i][u]!=-1&&dp[i][u]!=dp[i][v])
    u=dp[i][u],v=dp[i][v];
    
    return p[u];
}

inline int dist(int u, int v)
{
    return l[u]+l[v]-2*l[lca(u,v)];
}

vi papa;
int dn;
void DFS(int u, int p)
{
    ++dn;
    sub[u]=1;
    tr(g[u],it)
    {
        if(*it==p)continue;
        DFS(*it,u);
        sub[u]+=sub[*it];
    }
}
int centroid(int u,int baap)
{
    tr(g[u],it)
    if(*it!=baap&&sub[*it]>dn/2)
    return centroid(*it,u);
    
    return u;
}

void decompose(int u,int baap)
{
    dn=0;
    DFS(u,-1);
    int root=centroid(u,-1);
    papa[root]=baap;
    
    tr(g[root],it)
    {
        g[*it].erase(root);
        decompose(*it,root);
    }
    g[root].clear();
}
vi ans;

void update(int u)
{
    int x=u;
    while(1)
    {
        if(u==-1)break;
        ans[u]=min(ans[u],dist(x,u));
        u=papa[u];
    }
}
int query(int u)
{
    int x=u;
    int ret=INF;
    while(1)
    {
        if(u==-1)break;
        ret=min(ret,dist(u,x)+ans[u]);
        u=papa[u];
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    
    g.resize(n);
    p.resize(n);
    l.resize(n);
    ans.resize(n);
    papa.resize(n);
    sub.resize(n);
    
    int u,v;
    
    FOR(i,0,n-2)
    {
        cin>>u>>v;--u;--v;
        g[u].insert(v);g[v].insert(u);
    }
    
    preprocess();
    decompose(0,-1);
    fill(all(ans),INF);
    update(0);
    while(m--)
    {
        cin>>u>>v;--v;
        if(u==1)update(v);
        else cout<<query(v)<<"\n";
    }
    return 0;
}