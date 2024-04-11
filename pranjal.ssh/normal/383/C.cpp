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
#define mid ((l+r)>>1)

const int N=2e5+10;
struct BIT1
{
    vector<long long> t;
    long long n;
    BIT1()
    {
            n=0;
            t.clear();
    }
    BIT1(long long sz)
    {
        n=sz;
        t.clear();
        t.resize(sz+1);
    }
    void clear(long long sz)
    {
        n=sz;
        t.clear();
        t.resize(sz+1);
    }
    void update(long long i, long long val)
    {
        while(i<=n)
        {
            t[i]+=val;
            i+=i&-i;
        }
    }
    long long query(long long i)
    {
        long long ans=0;
        while(i>0)
        {
            ans+=t[i];
            i-=i&-i;
        }
        return ans;
    }
};
int val[N];
int sum[N];
vvi g;
int ctr;
int sub[N];
int pos[N];
int l[N];
void dfs(int i,int p)
{
    pos[i]=++ctr;
    sub[i]=1;
    tr(g[i],it)
    if(*it!=p)l[*it]=l[i]^1,dfs(*it,i),sub[i]+=sub[*it];
}

int main()
{
    boost;
    int n,m;
    cin>>n>>m;
    g.rz(n+1);
    FOR(i,1,n)cin>>val[i];
    
    BIT1 bt[2];
    rep(i,2)bt[i].clear(n+10);
    FOR(i,1,n-1)
    {
        int x,y;cin>>x>>y;g[x].pb(y);g[y].pb(x);
    }
    l[1]=0;
    dfs(1,-1);

    FOR(i,1,n)bt[l[i]].update(pos[i],val[i]),bt[l[i]].update(pos[i]+1,-val[i]);

    while(m--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            bt[l[x]].update(pos[x],y);bt[l[x]].update(pos[x]+sub[x],-y);
            bt[!l[x]].update(pos[x],-y);bt[!l[x]].update(pos[x]+sub[x],y);

        }
        else
        {
            int x;
            cin>>x;
            cout<<bt[l[x]].query(pos[x])<<"\n";
        }
    }
    return 0;
}