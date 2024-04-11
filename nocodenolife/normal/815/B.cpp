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
    x = x%mod;
    ex = ex % (mod-1);
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 2e5 + 7;

const ll inf = 1e9 + 7;
int n;
vector<int> vals;
int fact[maxn];
int facti[maxn];

void doStep()
{
    int siz = vals.size();

    for(int i=0;i+1<siz;i++)
    {
        if(i%2==0)
            vals[i] += vals[i+1];
        else
            vals[i] -= vals[i+1];
    }
    vals.pop_back();
}

int C(int n, int k)
{
    int ans = (fact[n] * facti[n-k] )%mod;
    ans = ans * facti[k];
    ans = ans % mod;
    return ans;
}

void solve()
{
    cin>>n;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        vals.pb(x);
    }
    if(n==1)
    {
        cout<<vals[0]<<endl;
        return;
    }

    if(n%2==1)
    {
        doStep();
        n--;
    }

    int val1=0;
    int val2=0;
    int idx = 0;
    for(int i=0;i<n;i+=2)
    {
        val1 += (C((n/2)-1,idx++) * vals[i]) % mod;
    }
    val1%=mod;
//    cout<<val1<<endl;
    idx = 0;
    for(int i=1;i<n;i+=2)
    {

        val2 += (C((n/2)-1,idx++) * vals[i]) % mod;
    }
    val2%=mod;
//    cout<<val2<<endl;
    int ans = val1+val2;
    if(n%4==0)
    {
        ans = val1 - val2 + mod;
    }
    ans = (ans  + mod)% mod;

    cout<<ans<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    PRELUDE;

    fact[0] = facti[0] = 1;
    fact[1] = facti[1] = 1;

    for(int i=2;i<maxn;i++)
    {
        fact[i] = i*fact[i-1] % mod;
        facti[i] = modexp(fact[i],mod-2);
    }

    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}