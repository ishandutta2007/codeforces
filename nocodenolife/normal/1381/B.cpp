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

const int maxn = 4007;

const ll inf = 1e9 + 7;
int n;
int arr[maxn];
int maxi[maxn];

vector<int> vals;
int poss[maxn];
vector<int> toAdd;

void solve()
{
    cin>>n;
    n = n+n;
    maxi[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        maxi[i] = max(maxi[i-1],arr[i]);
    }

    int count = 1;
    vals.clear();
    for(int i=2;i<=n;i++){
        if(maxi[i]==maxi[i-1])
        {
            count++;
            continue;
        }
        else
        {
            vals.pb(count);
            count = 1;
        }
    }
    vals.pb(count);

    for(int i=1;i<=n;i++)
        poss[i] = 0;
    poss[0] = 1;

    for(auto c:vals)
    {
        toAdd.clear();
        for(int i=0;i<=n;i++)
        {
            if(poss[i]==0)
                continue;
            toAdd.pb(i+c);
        }
        for(auto x:toAdd)
        {
            poss[x] = 1;
        }
    }

    int m = n/2;
    if(poss[m]==1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

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