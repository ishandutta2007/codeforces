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

const ll inf = 1e14 + 7;
const int bsiz = 350;

int n,m;
int arr[maxn];
int dp[bsiz][maxn];
vector<pair<int,pii>> qu[bsiz];
int sto[maxn];
int ans[3*maxn];
int sorted[maxn];
int suc[maxn];
int pre[maxn];

bool comp(pair<int,pii> p1, pair<int,pii>p2)
{
    return p1.sc.sc > p2.sc.sc;
}

void del(int x)
{
    pre[suc[x]] = pre[x];
    suc[pre[x]] = suc[x];
}

int add(int x)
{
    int ret = inf;
    int u = suc[x];
    if(u<n+1) ret = min(sorted[u] - sorted[x], ret);
    u = pre[x];
    if(u>0) ret = min(sorted[x] - sorted[u],ret);
    suc[pre[x]] = pre[suc[x]] = x;
    return  ret;
}

void setUp()
{
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = i - 1;
        suc[i] = i + 1;
    }
    pre[n + 1] = n;
    suc[0] = 1;
}

void start()
{
    for(int i=1;i<=n;i++)dp[1][i] = inf;
    for(int i=2;i<bsiz;i++)
    {
        for(int j=1;j+i-1<=n;j++)
        {
            dp[i][j] = min(min(dp[i-1][j],dp[i-1][j+1]),abs(arr[j+i-1] - arr[j]));
        }
    }
    pii info[maxn];
    for (int i = 1; i <= n; ++i) info[i] = {arr[i], i};
    sort(info + 1, info + n + 1);
    for (int i = 1; i <= n; ++i) arr[i] = lower_bound(info + 1, info + n + 1, std::make_pair(arr[i], i)) - info;
    for (int i = 1; i <= n; ++i) sorted[i] = info[i].first;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cin>>m;
    start();

    int l,r;
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        if(r-l+1<bsiz)
        {
            ans[i] = dp[r-l+1][l];
        } else{
            qu[l/bsiz].pb({i,{l,r}});
        }
    }

    int p,q;
    int val;
    for(int i=0;i<bsiz;i++)
    {
        if(qu[i].empty())
            continue;
        setUp();
        p = min(i * bsiz + bsiz - 1,n), q = i * bsiz;
        if(q>n)
            break;
        for (int j = 1; j < p; ++j) del(arr[j]);
        for (int j = n; j > p; --j) del(arr[j]);
        sto[p] = inf;
        for(int j=p+1;j<=n;j++) sto[j] = min(sto[j-1],add(arr[j]));
        for(int j=p-1;j>=q;j--) add(arr[j]);
        sort(all(qu[i]),comp);
        l = q;
        r = n;
        for(auto x:qu[i])
        {
            assert(l==q);
            assert(r>=x.sc.sc);
            while(r>x.sc.sc)
            {
                del(arr[r]);
                r--;
            }
            val = sto[r];
            while(l<p)
            {
                del(arr[l]);
                l++;
            }

            while(l>x.sc.fi)
            {
                l--;
                val = min(val,add(arr[l]));
            }
            while(l>q)
            {
                l--;
                add(arr[l]);
            }
            ans[x.fi] = val;
        }
    }

    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;

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