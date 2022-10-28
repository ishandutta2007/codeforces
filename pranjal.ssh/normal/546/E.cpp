#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)

const int maxn=202;
vector<int> G[maxn];
int cap[maxn][maxn];
int from[maxn];
bool vis[maxn];
int Source,Sink;
int bfs()
{
    fill(from,from+Sink+1,-1);
    fill(vis,vis+Sink+1,0);
    queue<int> q;
    q.push(Source);
    vis[Source]=1;
    int u;
    while(!q.empty())
    {
        u=q.front();q.pop();
        //if(u==g+h+1)break;
        tr(G[u],it)
        {
            if((!vis[*it])&&(cap[u][*it]>0))
            {from[*it]=u;q.push(*it);vis[*it]=1;}
        }
    }
    int mn=INF;u=Sink;
    while(from[u]!=-1)
    {
        mn=min(mn,cap[from[u]][u]);
        u=from[u];
    }
    if(mn==INF)return 0;
    u=Sink;
    while(from[u]!=-1)
    {
        cap[from[u]][u]-=mn;
        cap[u][from[u]]+=mn;
        u=from[u];
    }
    return mn;
}

int max_flow(){int ans=0;int temp;while(1){temp=bfs();if(temp==0)break;ans+=temp;}return ans;}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    Source=0;
    Sink=2*n+1;
    int sum=0;
    FOR(i,0,n-1)
    {
        int x;
        cin>>x;
        G[i+1].pb(0);
        G[0].pb(i+1);
        cap[0][i+1]=x;
        sum+=x;
    }
    int SUM=0;
    FOR(i,0,n-1)
    {
        int x;
        cin>>x;
        SUM+=x;
        G[i+1+n].pb(Sink);
        G[Sink].pb(i+1+n);
        cap[i+n+1][Sink]=x;
        G[i+1].pb(i+n+1);
        G[i+n+1].pb(i+1);
        cap[i+1][i+n+1]=INF;
    }
    FOR(i,0,m-1)
    {
        int u,v;
        cin>>u>>v;
        G[u].pb(n+v);
        G[n+v].pb(u);
        G[v].pb(n+u);
        G[n+u].pb(v);
        cap[u][n+v]=INF;
        cap[v][n+u]=INF;
    }
   
    if(max_flow()==sum&&sum==SUM)cout<<"YES\n";
    else {cout<<"NO\n";return 0;}
    FOR(i,1,n)
    {
        FOR(j,n+1,2*n)
        {
            if(cap[i][j]!=0)cap[i][j]=INF-cap[i][j];
            cout<<cap[i][j]<<" ";
        }cout<<"\n";
    }
    return 0;
}