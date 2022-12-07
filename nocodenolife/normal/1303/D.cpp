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

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;
int n,m;
int coun[32];
int pow2[32];
int req[32];

int log2m(int x)
{
    int ans = 0;
    while(x>1)
    {
        x/=2;
        ans++;
    }
    return ans;
}

int ans;
void breakOne(int b)
{
    int x = b;
    while(x<31)
    {
        x++;
        if(coun[x]>0)
            break;
    }
    while(x>b)
    {
        coun[x]--;
        coun[x-1]+=2;
        ans++;
        x--;
    }
}

void solve()
{
    cin>>n>>m;
    memset(coun,0,sizeof(coun));
    memset(req,0,sizeof(req));
    int su = 0;
    int x;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        su+=x;
        x = log2m(x);
        coun[x]++;
    }
    if(su<n)
    {
        cout<<"-1"<<endl;
        return;
    }

    for(int i =0;i<31;i++)
    {
        x = pow2[i];
        if(n&x) {
            req[i]++;
            n-=x;
        }
    }
    assert(n%(pow2[31])==0);
    req[31] += n/pow2[31];

    ans = 0;
    for(int i=0;i<31;i++)
    {
        while(req[i]>coun[i])
        {
            //cout<<req[i]<<" "<<i<<endl;
            breakOne(i);
        }
        coun[i]-= req[i];
        x = coun[i]/=2;
        coun[i] = 0;
        coun[i+1]+=x;
    }

    cout<<ans<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    PRELUDE;
    pow2[0] = 1;
    for(int i=1;i<32;i++)
    {
        pow2[i] = pow2[i-1] * 2;
    }
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}