///===========================///
///                           ///
///    ID     : FlaminRage    ///
///    School : JU            ///
///                           ///
///===========================///

#include<bits/stdc++.h>

#define sz(a) ((int)a.size())
#define repv(i,a) for(int i=0;i<sz(a);i++)
#define revv(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define countbit(x) __builtin_popcount(x)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi (2.0*acos(0.0))
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define setinf(ar) memset(ar,126,sizeof ar)
#define in(a,x,y) (a>=x && a<=y)
#define out(a,x,y) (!in(a,x,y))
#define eq(a,b) (fabs(a-b)<eps)
#define less(a,b) (a+eps<b)
#define great(a,b) (a>b+eps)
#define xx first
#define yy second
#define root 1

#define MAX(a) (*max_element(all(a)))
#define MIN(a) (*min_element(all(a)))

#define LB(a,x) (lower_bound(all(a),x)-a.begin())
#define UB(a,x) (upper_bound(all(a),x)-a.begin())

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;

template< class T > inline T _sq(T a) { return a * a; }
template< class T > inline T _sqrt(T a) { return (T) sqrt( (double) a); }
template< class T, class X > inline T _pow(T a,X y) {T z=1; rep(i,1,y){z*=a;} return z; }
template< class T > inline T _gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return _gcd(b,a%b);}
template< class T > inline T _lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}

template< class T > inline T _extended(T a,T b,T &x,T &y) {a=abs(a);b=abs(b); T g,x1,y1; if(!b) {x=1;y=0;g=a; return g;} g=_extended(b,a%b,x1,y1); x=y1; y=x1-(a/b)*y1; return g;}

template< class T, class X > inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0); }
template< class T, class X > inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template< class T, class X > inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i))); }
template< class T, class X > inline T togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

template< class T > void pv(T v) { repv(i,v) cout<<v[i]<<" "; cout<<endl; }

///========CONSTANT=========///
///  power    0123456789    ///
#define MX  ( 400000  +3 )
#define inf   2000000000
#define MOD   1000000007

#define eps 1e-9
///=========================///

template< class T,class X > inline T _bigmod(T n,X m){ull ret=1, a = n%MOD ; while(m){ if(m&1)ret=(ret*a)%MOD; m>>=1; a=(a*a)%MOD; }ret%=MOD;return (T)ret;}
template< class T > inline T _modinv(T n) {return _bigmod(n,MOD-2);}

///===============///
///End of template///
///===============///

int n,m,a[MX];

vi adj[MX];

int bit[2][MX],st[MX],ed[MX],cnt=1;

bool dep[MX];

void dfs(int u,int p,int d) {

    dep[u]=d;

    st[u]=cnt++;

    repv(i,adj[u]) {
        int v=adj[u][i];
        if(v==p) continue;
        dfs(v,u,d^1);
    }

    ed[u]=cnt++;

    return;
}

void update(int t,int x,int v) {
    while(x < MX) {
        bit[t][x]+=v;
        x+=x&(-x);
    }
    return;
}

int query(int t,int x) {
    int ret = 0;
    while(x) {
        ret+=bit[t][x];
        x-=x&(-x);
    }
    return ret;
}

int main() {

    cin>>n>>m;

    rep(i,1,n) cin>>a[i];

    rep(i,1,n-1) {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1,-1,0);

    while(m--) {
        int t,x,y;
        cin>>t>>x;
        if(t==1) {
            cin>>y;
            update(dep[x],st[x],+y);
            update(dep[x],ed[x]+1,-y);

            update((1^dep[x]),st[x],-y);
            update((1^dep[x]),ed[x]+1,+y);
        }
        else {
                int ans=a[x];

                ans+=query(dep[x],st[x]);

                cout<<ans<<endl;


        }

    }

    return 0;
}