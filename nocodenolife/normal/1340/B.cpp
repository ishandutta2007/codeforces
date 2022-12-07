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

int n,k;
bool dp[2015][2015];
int dist[2005][12];

inline int findDist(bitset<7> v, bitset<7> b)
{
    if(((~v)&b).count()>0)
        return -1;
    return (v^b).count();
}

void solve()
{
    cin>>n>>k;
    memset(dp,false,sizeof(dp));

    string x;
    bitset<7> y;
    int u;
    bitset<7> arr[10];
    arr[0] = bitset<7> ("1110111");
    arr[1] = bitset<7> ("0010010");
    arr[2] = bitset<7> ("1011101");
    arr[3] = bitset<7> ("1011011");
    arr[4] = bitset<7> ("0111010");
    arr[5] = bitset<7> ("1101011");
    arr[6] = bitset<7> ("1101111");
    arr[7] = bitset<7> ("1010010");
    arr[8] = bitset<7> ("1111111");
    arr[9] = bitset<7> ("1111011");

    for(int i=1;i<=n;i++)
    {
        cin>>x;
        y = bitset<7>(x);
        for(int j=0;j<=9;j++)
        {
            dist[i][j] = findDist(arr[j],y);
        }
    }

    dp[n][k] = true;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=k;j++)
        {
            if(!dp[i][j])
                continue;
            for(int v=0;v<=9;v++) {
                if(dist[i][v]==-1)
                    continue;
                u = j - dist[i][v];
                if(u>=0)
                {
                    dp[i-1][u] = true;
                }
            }
        }
    }

    if(!dp[0][0])
    {
        cout<<-1<<endl;
        return;
    }

    int j = 0;
    for(int i=0;i<n;i++)
    {
        for(int v=9;v>=0;v--)
        {
            if(dist[i+1][v]==-1)
                continue;
            if(dp[i+1][j+dist[i+1][v]])
            {
                cout<<v;
                j += dist[i+1][v];
                break;
            }
        }
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