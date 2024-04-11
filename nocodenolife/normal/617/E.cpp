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
const int bsiz = 316;
int n,m,k;
vector<int> arr;

struct query{
    int l;
    int r;
    int idx;
};

vector<struct query> qu;

bool comp(struct query q1, struct query q2)
{
    if(q1.l/bsiz != q2.l/bsiz)
    {
        return q1.l<q2.l;
    }
    return q1.l/bsiz%2==0?q1.r<q2.r:q1.r>q2.r;
}

int mp[1<<20];
int prexor=0;
int totxor =0;
int ql = 0;
int qr = -1;
int curAns = 0;
int ans[maxn];

void addLeft(int idx)
{
    prexor = prexor^arr[idx];
    int u = k^prexor;
    curAns+= mp[u];
    mp[prexor]++;
    totxor = totxor^arr[idx];
}

void addRight(int idx)
{
    int u = totxor^arr[idx]^prexor;
    int v = k^u;
    curAns+= mp[v];
    mp[u]++;
    totxor = totxor^arr[idx];
}

void removeLeft(int idx)
{
    int v = k^prexor;
    mp[prexor]--;
    curAns-= mp[v];
    prexor = prexor^arr[idx];
    totxor = totxor^arr[idx];
}

void removeRight(int idx)
{
    int u = totxor^prexor;
    int v = k^u;
    mp[u]--;
    curAns-= mp[v];
    totxor = totxor^arr[idx];
}

void findAns(struct query y)
{
    //cout<<y.l<<" "<<y.r<<endl;
    while (ql > y.l) {
        ql--;
        addLeft(ql);
    }
    while (qr < y.r) {
        qr++;
        addRight(qr);
    }
    //cout<<curAns<<" --- ";
    while (ql < y.l) {
        removeLeft(ql);
        ql++;
    }
    while (qr > y.r) {
        removeRight(qr);
        qr--;
    }
    ans[y.idx] = curAns;
    //cout<<curAns<<endl;
}

void solve()
{
    cin>>n>>m>>k;
    int x;
    mp[0] = 1;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr.pb(x);
    }

    for(int i=0;i<m;i++)
    {
        struct query y;
        cin>>y.l>>y.r;
        y.l--;
        y.r--;
        y.idx = i+1;
        qu.pb(y);
    }
    sort(all(qu),comp);

    for(auto y: qu)
    {
        findAns(y);
    }

    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<endl;
    }
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    memset(mp,0, sizeof(mp));
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}