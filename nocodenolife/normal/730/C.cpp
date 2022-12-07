// #define DEBUG
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
    // if(x == 0) return 0; // Remember 0 ^ 0 case.
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 5000 + 7;
const int N = maxn;
const ll inf = 1e9 + 7;

int store[N], num[N], prc[N];
vector < int > g[N];
vector < int > str_id[N];
vector < pair < pii,int > > time_cost_qty;
queue < pii > q;
int vis[N];
int st, qty, cost;
pii x;


int poss(int mid){
    int cur_qty = 0, cur_cost = 0;
    for(auto c:time_cost_qty)
    {
        if(c.sc > mid)
            continue;
        x = c.fi;
        if(cur_qty+x.sc < qty)
        {
            cur_qty += x.sc;
            cur_cost += x.sc*x.fi;
            if(cur_cost>cost)
                return 0;
        } else{
            cur_cost += (qty-cur_qty)*(x.fi);
            return cur_cost<=cost;
        }
    }
    return 0;
}

void sol(){
    cin >> st >> qty >> cost;

    while(!q.empty()) q.pop();
    q.push({st, 0});

    fill(vis, vis + N, 0);
    time_cost_qty.clear();

    while(!q.empty()){
        pii p = q.front();
        q.pop();
        if(vis[p.fi])
            continue;
        vis[p.fi] = 1;
        for(auto i : str_id[p.fi]){
            time_cost_qty.pb({{prc[i], num[i]},p.sc});
        }

        for(auto i : g[p.fi]){
            if(vis[i]) continue;
            q.push({i, p.sc + 1});
        }
    }

    int low = 0, mid, high = N - 1;

    sort(all(time_cost_qty));

    while(low != high){
        mid = (low + high) / 2;
        if(poss(mid)){
            high = mid;
        }else{
            low = mid + 1;
        }
    }

    if(low == N - 1){
        cout << -1 << endl;
    }else{
        cout << low << endl;
    }

}

void __solve(){

    int n, m;
    cin >> n >> m;

    int x, y;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    int w; cin >> w;

    int c, k, p;
    for(int i = 1; i <= w; i++){
        cin >> c >> k >> p;
        store[i] = c;
        num[i] = k;
        prc[i] = p;
        str_id[c].pb(i);
    }

    int q; cin >> q;
    while(q--) sol();

}


i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);

    PRELUDE;

    int t = 1;
    // cin >> t;

    for(int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        __solve();
    }


}