//#define DEBUG
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
 
/* const long long mod = 998244353ll; */
//                     123456789*/
const long long mod = 1000000007ll;
#define int ll
 
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
 
const int maxn = 1e6 + 7;
const ll inf = 1e9 + 7;
 
const ld eps = 1e-7;
const ld pi = acosl(-1.0);

int r[maxn];
int a[maxn];

string gs(int n, vector<int> v) {
    string s = "";
    for (int i = 0; i < n; i++) s.push_back('0');
    for (int e : v) s[e - 1] = '1';
    return s;
}

vector<string> sol;
vector<string> sol2;

bool solve(int n) {
    set<pii> S;  
    for (int i = 1; i <= n; i++) if (a[i] != 0) S.insert({a[i], i});


    while (true) {
        if (S.size() == 0) return true;

        if (S.size() == 1) return false;

        if (S.size() == 2) {
            int v = S.begin()->fi;
            if (v != S.rbegin()->fi) return false;
            int a = S.begin()->sc, b = S.rbegin()->sc;
            for (int j = 0; j < v; j++) {
                sol.push_back(gs(n, {a, b}));
            }
            return true;
        }

        if (S.size() == 3 && S.begin()->fi == S.rbegin()->fi && S.begin()->fi == 1) {
            int a = S.begin()->sc; S.erase(S.begin());
            int b = S.begin()->sc; S.erase(S.begin());
            int c = S.begin()->sc; S.erase(S.begin());
            sol.push_back(gs(n, {a, b, c}));
        } else {
            int v, i; tie(v, i) = *S.rbegin(); S.erase(*S.rbegin());
            int h, j; tie(h, j) = *S.rbegin(); S.erase(*S.rbegin());
            sol.push_back(gs(n, {i, j}));
            v--; h--;
            if (v != 0) S.insert({v, i}); 
            if (h != 0) S.insert({h, j});
        }
    }
}

void display(int c, int n) {
    cout << c << endl;
    if (c == 0) {
        sol2.clear();
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= 100; j++) {
                sol2.pb(gs(n, {i, 1}));
            }
        }
    }
    cout << sol2.size() << endl;
    for (string s : sol2) cout << s << endl;
}

void __solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }

    sol.clear();

    for (int c = 1; c <= 101; c++) {
        for (int i = 1; i <= n; i++) {
            a[i] = r[i] - c;
            if (a[i] < 0) {
                display(c - 1, n); return;
            }
        }
        if (!solve(n)) {
            display(c - 1, n); return;
        }
        sol2 = sol; sol.clear();
    }

    assert(false);
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