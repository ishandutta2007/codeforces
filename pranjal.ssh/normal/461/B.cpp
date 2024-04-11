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
int n;
vvi g;
vi col;
vi ways,waysl,sum;
int root;
int expo(int a, int p)
{
    if(p==0)return 1;
    int ans=expo(a,p>>1);
    ans=mul(ans,ans);
    if(p&1)return mul(ans,a);
    return ans;
}
void dfs(int u, int p=-1)
{
    sum[u]=col[u];
    tr(g[u],it)
    {
        if(*it==p)continue;
        dfs(*it,u);
        sum[u]+=sum[*it];
    }
    ways[u]=1;
    if(col[u])
    {
        
        tr(g[u],it)
        {
            if(*it==p or sum[*it]==0)continue;
            ways[u]=mul(ways[u],add(ways[*it],waysl[*it]));
        }
    }
    else
    {
        
        int x=0;
        waysl[u]=1;
        tr(g[u],it)
        {
            if(*it==p or sum[*it]==0)continue;
            ways[u]=mul(ways[u],add(waysl[*it],ways[*it]));
            waysl[u]=mul(waysl[u],add(ways[*it],waysl[*it]));
            x=add(x,mul(ways[*it],expo(add(ways[*it],waysl[*it]),INF-2)));
        }
        ways[u]=mul(ways[u],x);
    }
}
int main()
{
    boost;
    cin>>n;
    g.rz(n);col.rz(n);
    ways.rz(n);sum.rz(n);waysl.rz(n);
    FOR(i,0,n-2)
    {
        int x;cin>>x;
        g[x].pb(i+1);
        g[i+1].pb(x);
    }
    FOR(i,0,n-1)cin>>col[i];
    FOR(i,0,n-1)if(col[i])root=i;
    dfs(root);
    
    cout<<ways[root]<<"\n";
    return 0;
}