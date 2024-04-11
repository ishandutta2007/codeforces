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
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
#define N 200000
vii g[N];
int d[N];
int u[N];
void dfs(int v, int p=-1)
{
    tr(g[v],it)
    {
        if(it->F==p)continue;
        dfs(it->F,v);
        d[v]+=d[it->F]+it->S;
    }
}

void DFS(int v, int p=-1)
{
    if(p>=0)
    {
        int x=0;
        tr(g[v],it)if(it->F==p)x=it->S;
        u[v]=u[p]+d[p]+x-(1-x+d[v]);
    }
    tr(g[v],it)
    {
        if(it->F==p)continue;
        DFS(it->F,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    FOR(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        --u,--v;
        g[u].pb({v,0});
        g[v].pb({u,1});
    }
    dfs(0);
    DFS(0);
    
    int anss=INF;
    FOR(i,0,n-1)
    anss=min(anss,d[i]+u[i]);
    cout<<anss<<"\n";
    FOR(i,0,n-1)if(anss==d[i]+u[i])cout<<i+1<<" ";
    return 0;
}