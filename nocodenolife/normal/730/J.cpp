//#define DEBUG
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
/* const long long mod = 998244353ll; */
//                     123456789*/
const long long mod = 1000000007ll;
/* #define int ll */
 
#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) (((a) & (1ll << (p)))>0)
#define BXOR(a, p) ((a) ^ (1ll << (p)));
#define BREM(a, p) (BCHK(a, p)?(BXOR(a, p)):(a))
#define BSHO(a, N) (bitset<N>(a))
 
#define fi first
#define sc second 
#define pb push_back
 
 
#ifdef DEBUG
    #define dbg(s) {s;}
    #define PRELUDE {common();}
#endif
 
#ifndef DEBUG 
    #define PRELUDE { common(); ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    #define dbg(s)
    #define endl "\n"
#endif
 
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
typedef pair< ld, ld > point;
 
istringstream _inp;
string _inps;
 
void common() {
    _inp.clear();
    _inps = "";
    _inp.str(_inps);
}
 
int gi() {
    int x;
    while (true) {
        try {
            while (_inp.peek() == ',' || _inp.peek() == ' ') 
                _inp.ignore();
            if (_inp >> x) 
                return x;
            else throw 6;
        } catch (...) {
            getline(cin, _inps);
            _inp.clear();
            _inp.str(_inps);
        }
    }
}
 
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
  
ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}
 
 
#define X first
#define Y second 
const int maxn = 103;
const ll inf = 1e9 + 7;
 
const ld eps = 1e-7;
const ld pi = acosl(-1.0);

pii d[maxn];

int dp[2][maxn][maxn * maxn];

void __solve() {
    int n; cin >> n;
    int A = 0;
    for (int j = 1; j <= n; j++) {
        cin >> d[j].fi;
        A += d[j].fi;
    }

    for (int j = 1; j <= n; j++) cin >> d[j].sc;

    sort(d + 1, d + n + 1, [&](pii x, pii y) {
            return x.sc > y.sc;
            });

    int k = 0, total = 0;
    while (total < A) {
        k++; total += d[k].sc;
    }

    for (int i = 0; i <= n; i++) {
        int c = i&1;
        int o = 1 - c;
        for (int b = 0; b <= k; b++) {
            for (int lf = 0; lf <= A; lf++) {
                if (i == 0) {
                    if (lf == 0) dp[c][b][lf] = 0;
                    else dp[c][b][lf] = -inf;
                } else {
                    dp[c][b][lf] = dp[o][b][lf];
                    if (b >= 1) {
                        int nx = lf - d[i].sc; if (nx <= 0) nx = 0;
                        dp[c][b][lf] = max(dp[c][b][lf], dp[o][b - 1][nx] + d[i].fi);
                    }
                }
            } 
        }
    }

    cout << k << " " << A - dp[n&1][k][A] << endl;
}

i32 main() {

    PRELUDE;        
    int t; 
    t = 1;
    /* cin >> t; */
    for (int i = 1; i <= t; i++) {

        __solve();
    }

}