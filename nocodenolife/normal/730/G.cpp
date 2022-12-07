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

const int maxn = 200 + 7;
const int N = maxn;
const ll inf = 1e9 + 7;

int st[N];
int len[N];
vector < pii > interval;
pii ans[N];

int clash(int x){
    int str = st[x];
    int en = str + len[x] - 1;
    for(auto i : interval){
        if((i.fi <= str && str <= i.sc) || (i.fi <= en && en <= i.sc)) return 1;
        if((str <= i.fi && i.fi <= en) || (str <= i.sc && i.sc <= en)) return 1;
    }
    return 0;
}

void __solve(){

    int n; cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> st[i] >> len[i];
    }
    interval.pb({0, 0});

    int str, en;
    for(int i = 1; i <= n; i++){

        if(!clash(i)){
            ans[i] = {st[i], st[i] + len[i] - 1};
            interval.pb({st[i], st[i] + len[i] - 1});
        }else{
            sort(all(interval));
            ans[i] = {-1, -1};
            for(int j = 0; j + 1 < interval.size(); j++){
                str = interval[j].sc + 1;
                en = str + len[i] - 1;
                if(en < interval[j + 1].fi){
                    ans[i] = {str, en};
                    break;
                }
            }
            if(ans[i].fi == -1){
                str = interval.back().sc + 1;
                en = str + len[i] - 1;
                ans[i] = {str, en};
            }
            interval.pb({str, en});
        }

    }

    for(int i = 1; i <= n; i++){
        cout << ans[i].fi << " " << ans[i].sc << endl;
    }

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