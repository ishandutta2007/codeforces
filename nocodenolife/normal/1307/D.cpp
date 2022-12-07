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

const int maxn = 2e5 + 7;

const ll inf = 1e9 + 7;
int n,m,k;
int isSpecial[maxn];
vector<int> graph[maxn];
int dist[maxn][2];

void bfs(int st, int idx)
{
    dist[st][idx] = 0;
    queue<pair<int,int>> q;
    q.push({st,0});
    pii x;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(auto r: graph[x.first])
        {
            if(dist[r][idx] >= inf)
            {
                dist[r][idx] = x.sc+1;
                q.push({r,dist[r][idx]});
            }
        }
    }
}

bool compareVal(pii i1, pii i2)
{
    return ((i1.fi - i1.sc) < (i2.fi - i2.sc));
}

void solve()
{
    cin>>n>>m>>k;

    int u,v;
    memset(isSpecial,0, sizeof(isSpecial));
    for(int i=0;i<k;i++)
    {
        cin>>u;
        isSpecial[u] = 1;
    }
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for(int i=0;i<=n;i++)
    {
        dist[i][0] = inf;
        dist[i][1] = inf;
    }

    bfs(1,0);
    bfs(n,1);

    int ans = dist[n][0];
    vector<pii> p;
    for(int i=0;i<=n;i++)
    {
        if(isSpecial[i])
        {
            p.pb({dist[i][0],dist[i][1]});
        }
    }
    sort(all(p),compareVal);

    int curmax = p[0].fi;
    int maxi = 0;
    k = p.size();
    for(int i=1;i<k;i++)
    {
        maxi = max(curmax + p[i].sc + 1, maxi);
        curmax = max(curmax,p[i].fi);
    }

    if(maxi>ans)
        maxi = ans;
    cout<<maxi<<endl;
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