#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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

// 0 based indexing
vi p,l,sub,inv,pos;
int s[20][100010];
vvi g;
int lg2[100010];
int n;
vll sod,tsod;
void dfs(int i)
{
    static int ctr=0;
    pos[i]=++ctr;
    inv[pos[i]]=i;
    sub[i]=1;
    sod[i]=0;
    tr(g[i],it)
    {
        if(p[i]==*it)continue;
        p[*it]=i;
        l[*it]=l[i]+1;
        dfs(*it);
        sub[i]+=sub[*it];
        sod[i]+=sod[*it]+sub[*it];
    }

}
void rectify(int i)
{
    tsod[i]=sod[i];
    if(i)tsod[i]+=tsod[p[i]]-sod[i]-sub[i]+n-sub[i];
    tr(g[i],it)
    {
        if(*it==p[i])continue;
        rectify(*it);
    }
}
void pre()
{
    l.rz(n);p.rz(n);sub.rz(n);pos.rz(n);inv.rz(n+1);tsod.rz(n+1);sod.rz(n);
    pos[0]=0;
    l[0]=0; p[0]=-1;
    dfs(0);
    rectify(0);
    FOR(i,1,n)lg2[i]=lg2[i-1]+((i&(i-1))==0);
    FOR(i,0,n-1)
    for(int j=0;(1<<j)<n;++j)   s[j][i]=-1; 
    FOR(i,0,n-1)s[0][i]=p[i];   
    for(int j=1;(1<<j)<n;++j)
        FOR(i,0,n-1)if(s[j-1][i]!=-1)s[j][i]=s[j-1][s[j-1][i]];

    
    
    
}
inline int lca(int u, int v)
{   
    if(l[u]<l[v])swap(u,v); 
    int LOG=lg2[l[u]];
    NFOR(i,LOG,0)
    if(l[u]-(1<<i)>=l[v])
    u=s[i][u];
    
    if(u==v)return u;
    
    NFOR(i,LOG,0)
    if(s[i][u]!=-1&&s[i][u]!=s[i][v])
    u=s[i][u],v=s[i][v];
    return p[u];
}

double qry(int x,int y)
{
    if(l[x]<l[y])swap(x,y);
    int LCA = lca(x,y);
    int dist = l[x]+l[y]-2*l[LCA];
    ll yo=0;
    ll tot=0;
    if(LCA==y)
    {
        int xx=x;
        NFOR(i,lg2[l[x]],0)if(l[xx]-(1<<i)>=(l[y]+1))xx=s[i][xx];
        
        int SUB=n-sub[xx];
        ll DF=tsod[y]-sod[xx]-sub[xx];
        
        tot=sub[x]*1LL*SUB;
        yo+=sub[x]*1LL*(DF);
        yo+=(SUB)*1LL*sod[x];
        yo+=tot*(dist+1);   
    }
    else
    {
        tot=sub[x]*1LL*sub[y];
        yo+=sub[x]*1LL*sod[y];
        yo+=sub[y]*1LL*sod[x];
        yo+=tot*(dist+1);
    }
    // cout<<yo<<" "<<tot<<" ";
    return static_cast<double>(yo)/tot;
}
int main()
{
    boost;
    int m;
    cin>>n>>m;
    g.rz(n);
    FOR(i,1,n-1)
    {
        int x,y;cin>>x>>y;
        x--,y--;
        g[x].pb(y);g[y].pb(x);
    }
    pre();

    cout<<fixed<<setprecision(9);
    // FOR(i,0,n-1)cout<<sod[i]<<" "<<tsod[i]<<"\n";
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        cout<<qry(x-1,y-1)<<"\n";
    }
    return 0;
}