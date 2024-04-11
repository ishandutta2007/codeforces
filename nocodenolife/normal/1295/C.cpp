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

const int maxn = 1e5 + 7;

const ll inf = 1e9 + 7;

string s,t;
int nex[maxn][30];
int poss[30];
int n;

void solve()
{
    cin>>s>>t;
    int u,v;
    n = s.length();
    for(int i=0;i<29;i++)
    {
        poss[i] = 0;
        nex[n][i] = 0;
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<29;j++)
        {
            nex[i][j] = nex[i+1][j];
        }
        u = s[i] - 'a';
        poss[u] = 1;
        nex[i][u] = i+1;
        dbg(for(int j=0;j<29;j++)
        {
            cout<<nex[i][j]<<" ";
        }
        cout<<endl;);
    }

    int curlen = 0;
    int ans = 1;

    int m = t.length();

    for(int i=0;i<m;i++)
    {
        u = t[i] - 'a';
        if(poss[u]==0)
        {
            cout<<-1<<endl;
            return;
        }

        v = nex[curlen][u];
        if(v==0) {
            ans++;
            v = nex[0][u];
        }
        curlen = v;
    }
    cout<<ans<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}