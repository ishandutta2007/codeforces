//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)))
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

//#define int ll
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

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;
int n;
int gr[20][20];
vector < ll > dp[1 << 14][14];
ll ans[1<<13];

void solve()
{
    cin>>n;
    char t;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>t;
            gr[i][j] = t-'0';
        }
    }
    int x = 1<<n,y;
    //cout<<x<<endl;

    int u,v;
    int visn,staten;
    for(int vis=1;vis<x;vis++)
    {
        int c = __builtin_popcount(vis);
        y = 1<<(c-1);
        for(int state=0;state<y;state++)
        {
            staten = BREM(state,c-2);
            v = 0;
            if(BCHK(state,c-2))
                v = 1;
            for(int ver=0;ver<n;ver++) {
                if(!BCHK(vis,ver))
                    continue;
                while (dp[vis][ver].size() <= state) {
                    dp[vis][ver].pb(0);
                }

                if(c==1) {
                    dp[vis][ver][state] = 1;
                    continue;
                }
                visn = BREM(vis,ver);
                for(int i=0;i<n;i++)
                {
                    u = gr[ver][i];
                    if(BCHK(visn,i) && u==v)
                    {
                        dp[vis][ver][state]+=dp[visn][i][staten];
                    }
                }
            }
        }
    }

    x = 1<<n;
    y = x/2;
    for(int i=0;i<y;i++)
    {
        ll ans =0 ;
        for(int j=0;j<n;j++)
        {
            ans+=dp[x-1][j][i];
        }
        cout<<ans<<" ";
    }
    cout<<endl;


}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    PRELUDE;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}