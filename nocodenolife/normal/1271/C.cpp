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

int dista(pii a, pii b)
{
    int ans = a.fi - b.fi;
    if(ans<0)
        ans *= -1;
    int u = a.sc - b.sc;
    if(u<0)
        u*=-1;
    ans+=u;
    return ans;
}
pii school;
vector<pii> home;
 
int loca(pii sta)
{
    int ans = 0;
    dbg(cout<<"?"<<sta.fi<<" "<<sta.sc<<endl;);
    for(auto v: home)
    {
        dbg(cout<<"."<<v.fi<<" "<<v.sc<<endl;);
        dbg(cout<<dista(v,school)<<" "<<dista(v,sta)<<endl;);
        if(dista(v,school) == dista(v,sta)+1)
            ans++;
    }
    //cout<<ans<<endl;
    return ans;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    int n,sx,sy;
    cin>>n>>sx>>sy;
    
    school = {sx,sy};
    
    pii ans = {-1,-1};
    int val = -1;
    
    int u,v;
    for(int i=0;i<n;i++)
    {
        cin>>u>>v;
        home.pb({u,v});
    }

    pii stall = {sx,sy+1};
    int value = loca(stall);
    if(value>val)
    {
        val = value;
        ans = stall;
    }
    stall = {sx+1,sy};
    value = loca(stall);
    if(value>val)
    {
        val = value;
        ans = stall;
    }
    stall = {sx,sy-1};
    value = loca(stall);
    if(value>val)
    {
        val = value;
        ans = stall;
    }
    stall = {sx-1,sy};
    value = loca(stall);
    if(value>val)
    {
        val = value;
        ans = stall;
    }

    cout<<val<<endl;
    cout<<ans.fi<<" "<<ans.sc<<endl;
}