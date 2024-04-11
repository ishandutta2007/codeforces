// ./e-xum.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

struct op {
    ll a, b; char o;
};

ll N;

vector<op> ops;
unordered_set<ll> has;
ll oadd(ll a, ll b) {
    // if (!has.count(a)) {
    //     cout<<"a="<<(a)<<", "; cout << endl; // db a
    //     assert(0);
    // }
    // if (!has.count(b)) {
    //     cout<<"b="<<(b)<<", "; cout << endl; // db b
    //      assert(0);   
    // }
    ops.pb({a, b, '+'});
    return a + b;
}
ll oxor(ll a, ll b) {
    ops.pb({a, b, '^'});
    return a ^ b;
}

ll multiply(ll a, ll b) {
    swap(a, b);
    ll res = 0, cp = a;
    for (auto i = 0; i <= __lg(b); i++) {
        if ((b >> i) & 1)
            res = oadd(res, cp);
        cp = oadd(cp, cp);
    }
    return res;
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    oxor(N, N); // so we always have 0 available

    // get a and b
    ll mul = 1, b, a = N;
    do {
        mul++;
        b = ((mul - 1) * a) ^ (mul * a);
    } while (gcd(a, b) != 1);
    multiply(mul - 1, a);
    multiply(mul, a);
    oxor((mul - 1) * a, mul * a);

    // get EEA
    ll x = 0, y = 1;
    assert(extgcd(a, b, x, y) == 1);

    // compute answer
    ll small, large;
    if (x < 0) { // then a > 0
        small = multiply(-x, a);
        large = multiply(y, b);
    }
    else {
        assert(y < 0);
        small = multiply(-y, b);
        large = multiply(x, a);
    }

    // WLOG a < 0
    assert(small + 1 == large);

    if (small % 2 == 1) {
        ll _small = oadd(small, small), _large = oadd(small, large);
        small = _small;
        large = _large;
    }

    assert(oxor(small, large) == 1);

    // output
    cout << (SZ(ops)) << '\n';
    for (auto &o : ops)
        cout << o.a << ' ' << o.o << ' ' << o.b << '\n';

    return 0;
}