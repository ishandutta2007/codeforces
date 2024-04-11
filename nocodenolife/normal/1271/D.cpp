//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)));
#define BREM(a, p) (BCHK(a, p)?(BXOR(a, p)):(a))
#define BSHO(a, N) (bitset<N>(a))

#define fi first
#define sc second 
#define pb push_back


#ifdef DEBUG
    #define dbg(s) {s;}
    #define PRELUDE
#endif

#ifndef DEBUG 
    #define PRELUDE { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    #define dbg(s)
    #define endl "\n"
#endif

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 
// Ordered set docs:
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

// To remove randomization use 0 below:
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int x) { // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

inline ld rf() { // from [0, 1]
    return uniform_real_distribution<ld>(0, 1)(rng);
}

ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 5000 + 7;

const ll inf = 1e9 + 7;

int n,m,k;
int req[maxn];
int added[maxn];
int val[maxn];
//int excess[maxn];

int where[maxn];

int dp[maxn][maxn];

vector<int> should[maxn];

void printDP(int i)
{
    cout<<"After "<<i<<endl;
    for(int j=0;j<maxn;j++)
        if(dp[i][j]>=0)
            cout<<j<<" -> "<<dp[i][j]<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    cin>>n>>m>>k;

    int a,b,c;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        req[i] = a;
        added[i] = b;
        val[i] = c;
        where[i] = i;
    }
    req[n+1] = 0;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        where[b] = max(where[b],a);
    }

    for(int i=1;i<=n;i++)
    {
        should[where[i]].pb(val[i]);
    }

    int r = 0;
    for(int i=n;i>=1;i--)
    {
        r-=added[i];
        r = max(r,req[i]);
        req[i] = r;
        dbg(cout<<i<<" "<<req[i]<<endl;);
    }
    if(req[1]>k)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            dp[i][j] = -inf;
    
    int gv = k - req[1];
    for(int j=0;j<=gv;j++)
        dp[0][j] = 0;
    
    int extra;
    int used,ad,newex;
    for(int i=1;i<=n;i++)
    {
        extra = req[i]-req[i+1]+added[i];
        dbg(cout<<i<<" extra "<<extra<<endl;);
        sort(all(should[i]));
        used = 0;
        ad = 0;
        int gs = should[i].size();
        gs--;
        for(int c = gs;c>=0;c--)
        {
            used++;
            ad+=should[i][c];
            dbg(cout<<"?"<<should[i][c]<<" ";);
            for(int j=0;j<maxn;j++)
            {
                newex = j + extra - used;
                if(newex<0)
                    continue;
                if(newex>=maxn)
                    newex = maxn-1;
                dp[i][newex] = max(dp[i-1][j]+ad, dp[i][newex]);
            }
        }
        dbg(cout<<endl;);
        for(int j=0;j<maxn;j++)
        {
            newex = j+extra;
            if(newex<0)
                continue;
            if(newex>=maxn)
                newex = maxn-1;
            dp[i][newex] = max(dp[i-1][j], dp[i][newex]);
        }
        dbg(printDP(i););
    }

    int ans = 0;
    for(int i=0;i<maxn;i++)
    {
        ans = max(ans,dp[n][i]);
    }

    cout<<ans<<endl;
}