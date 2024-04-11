// Flow credits : https://web.stanford.edu/~liszt90/acm/notebook.html

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
inline int mul(int a,int b, int m=INF){return (a*b)%m;}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}



struct BIT1
{
    vector<int> t;
    int n;
    BIT1( int sz)
    {
        n=sz;
        t.resize(sz+1);
    }
    inline void update( int i, int  val)
    {
        while(i<=n)
        {
            t[i]+=val;
            i+=i&-i;
        }
    }
    inline int query(int  i)
    {
        int ans=0;
        while(i>0)
        {
            ans+=t[i];
            i-=i&-i;
        }
        return ans;
    }
};

string a[3000];
int l[3000][3000];
int r[3000][3000];
int N;
int f(vi &L,vi &R)
{

    int n = sz(L);
    if(n<=1)return n;

    
    N=n+2;
    int ans=0;
    // int off=n+1;
    FOR(i,0,n-1)R[i]=i-R[i],N=max(N,abs(R[i])+2);

    vii q[n+N+10];
    vi pos[n+N+10];
    BIT1 bt(n+10);
    
    FOR(i,0,n-1)pos[R[i]+N].pb(i);
    FOR(i,0,n-1)q[i-1+N].pb({i,min(n-1,i+L[i]-1)});

    FOR(i,0,n+N+5)
    {
        tr(pos[i],it)
        bt.update(*it+2,1);

        tr(q[i],it)
        {
            ans+=bt.query(it->S+2)-bt.query(it->F-1+2);
        }
    }

    return ans;
}
int main()
{
    boost;
    int n,m;
    cin>>n>>m;
    N=max(n,m);
    FOR(i,0,n-1)cin>>a[i];

    FOR(i,0,n-1)
    FOR(j,0,m-1)
    l[i][j] = (j==0) ?a[i][j]=='z': (l[i][j-1]+1)*(a[i][j]=='z');

    FOR(i,0,n-1)
    NFOR(j,m-1,0)
    r[i][j] = (j==m-1)? a[i][j]=='z': (r[i][j+1]+1)*(a[i][j]=='z');


    ll ans=0;
    vi v,vv;
    FOR(i,0,m-1)
    {
        v.clear();
        vv.clear();
        int x=0,y=i;
        while(x<=n-1 and y>=0)
        {
            if(r[x][y]==0)
            {
                ans+=f(v,vv);
                v.clear();
                vv.clear();
            }
            else
            {
                v.pb(l[x][y]);
                vv.pb(r[x][y]);
            }
            x++,y--;
        }
        ans+=f(v,vv);
    }

    FOR(i,1,n-1)
    {
        v.clear();
        vv.clear();
        int x=i,y=m-1;
        while(x<=n-1 and y>=0)
        {
            if(r[x][y]==0)
            {
                ans+=f(v,vv);
                v.clear();
                vv.clear();
            }
            else
            {
                v.pb(l[x][y]);
                vv.pb(r[x][y]);
            }
            x++,y--;
        }
        ans+=f(v,vv);
    }
    cout<<ans;
    return 0;
}