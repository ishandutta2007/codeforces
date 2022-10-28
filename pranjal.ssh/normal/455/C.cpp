#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define ufy(v) sort(all(v));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}



vi p,r,d;

int find(int i)
{
    return i==p[i]?i:p[i]=find(p[i]);
}

void connect(int i,int j)
{
    int x=find(i);
    int y=find(j);
    if(x==y)return;
    if(r[x]<r[y])swap(x,y);
    p[y]=x,r[y]+=(r[x]==r[y]),d[x]=max({d[x],d[y],1+(d[x]+1)/2+(d[y]+1)/2});
}


vvi g;
vi dp,vis;
int dfs(int u,int p)
{
    dp[u]=0;
    vis[u]=1;
    vi bc(2,-1);
    int x=0;
    tr(g[u],it)
    {
        if(*it==p)continue;
        connect(u,*it);
        x=max(x,dfs(*it,u));
        bc.pb(dp[*it]);

        sort(nall(bc));
        if(sz(bc)>2)bc.pop_back();
    }
    dp[u]=1+bc[0];
    return max(x,2+bc[0]+bc[1]);
}
int main()
{
    boost;
    int n,m,q;
    cin>>n>>m>>q;
    vis.rz(n);p.rz(n);r.rz(n);d.rz(n);
    g.rz(n);
    FOR(i,0,m-1){int x,y;cin>>x>>y;x--,y--;g[x].pb(y);g[y].pb(x);}

    dp.rz(n);
    FOR(i,0,n-1)p[i]=i;
    FOR(i,0,n-1)
    {
        if(vis[i])continue;
        int x=dfs(i,-1);
        d[find(i)]=x;
    }
    
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x;cin>>x;cout<<d[find(x-1)]<<"\n";
        }
        else
        {
            int x,y;
            cin>>x>>y;
            connect(x-1,y-1);
        }
    }
    return 0;
}