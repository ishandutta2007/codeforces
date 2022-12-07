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

const ll inf = 1e5;

int n,r;
int len[maxn];
int tim[maxn];

int findNumReq(bool toPrint)
{
    int coun = 0;

    int over = 0;
    int curTime = 0;
    int req;
    int l,t,d;

    for(int i=1;i<=n;i++)
    {
        if(len[i]<=over)
        {
            over-=len[i];
            curTime += len[i];
            continue;
        }
        l = len[i] - over;
        curTime+=over;
        t = tim[i] - over;
        over = 0;

        req = l+l-t;
        if(req<0)
        {
            req = 0;
        }
        d = (req+r-1)/r;
        coun+= d;
        over = d*r - req;

        curTime+=req;
        l-=req;
        curTime+=l+l;

        if(toPrint)
        {
            t = curTime - req;
            for(int j=0;j<d;j++)
            {
                cout<<t<<" ";
                t+=r;
            }
        }

    }

    return coun;
}

void solve()
{
    cin>>n>>r;

    for(int i=1;i<=n;i++)
    {
        cin>>len[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>tim[i];
        if(tim[i]<len[i])
        {
            cout<<-1<<endl;
            return;
        }
    }

    int ans = findNumReq(false);
    cout<<ans<<endl;
    if(ans>inf)
    {
        return;
    }
    findNumReq(true);
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