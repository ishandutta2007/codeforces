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
int n,v;
vector<pii> boats;
vector<pii> caya;

void solve()
{
    cin>>n>>v;
    int ty,vol;
    for(int i=0;i<n;i++)
    {
        cin>>ty>>vol;
        if(ty==1)
            boats.pb({vol,i+1});
        else
            caya.pb({vol,i+1});
    }
    sort(all(boats),greater<>());
    sort(all(caya),greater<>());

    for(int i=1;i<boats.size();i++)
    {
        boats[i].fi += boats[i-1].fi;
    }
    for(int j=1;j<caya.size();j++)
    {
        caya[j].fi+=caya[j-1].fi;
    }

    int u = v;
    int ans =0 ;

    int bo = 0;
    int ca = 0;

    if(u>boats.size())
        u = boats.size();
    if(u>0) {
        ans = boats[u - 1].fi;
        bo = u;
        ca = 0;
    }

    for(int i=1;i<=caya.size();i++)
    {
        vol = v - (i*2);
        if(vol>boats.size())
            vol = boats.size();
        if(vol<0)
            break;
        if(vol==0)
        {
            u= caya[i-1].fi;
        }
        else
        {
            u = caya[i-1].fi + boats[vol-1].fi;
        }
        if(u>ans)
        {
            ans = u;
            bo = vol;
            ca = i;
        }
    }

    cout<<ans<<endl;

    for(int i=0;i<bo;i++)
    {
        cout<<boats[i].sc<<" ";
    }
    for(int i=0;i<ca;i++)
    {
        cout<<caya[i].sc<<" ";
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