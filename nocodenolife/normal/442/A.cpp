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

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;
int n;
int num[105];
char fac[105];

//hints -> 1 2 3 4 5 R G B Y W
set<int> intDiff;
set<char> charsDiff;
bool canDiff(int i, int j)
{
//    cout<<i<<" "<<j<<endl;
    if(num[i]==num[j] && fac[i]==fac[j])
        return true;
    if(num[i]!=num[j])
    {
        if(intDiff.find(num[i])!=intDiff.end())
            return true;
        if(intDiff.find(num[j])!=intDiff.end())
            return true;
    }
    if(fac[i]!=fac[j])
    {
        if(charsDiff.find(fac[i])!=charsDiff.end())
            return true;
        if(charsDiff.find(fac[j])!=charsDiff.end())
            return true;
    }
    return false;
}

bool check()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(!canDiff(i,j))
                return false;
        }
    }
    return true;
}

void setupSets(int val)
{
    intDiff.clear();
    charsDiff.clear();

    for(int i=1;i<=5;i++) {
        if (BCHK(val, i-1))
            intDiff.insert(i);
    }

    if(BCHK(val,5))
    {
        charsDiff.insert('R');
    }
    if(BCHK(val,6))
    {
        charsDiff.insert('G');
    }
    if(BCHK(val,7))
    {
        charsDiff.insert('B');
    }
    if(BCHK(val,8))
    {
        charsDiff.insert('Y');
    }
    if(BCHK(val,9))
    {
        charsDiff.insert('W');
    }
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>fac[i];
        cin>>num[i];
        //cout<<num[i]<<fac[i]<<endl;
    }

    int ans = 1000;
    int maxi = 1ll<<10ll;
    maxi--;
    int u;
    for(int i=0;i<maxi;i++)
    {
        setupSets(i);
        if(check())
        {
            u = __builtin_popcountll(i);
            ans = min(ans,u);
        }
    }
    cout<<ans<<endl;

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