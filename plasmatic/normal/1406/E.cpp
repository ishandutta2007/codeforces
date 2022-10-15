// ./e-deleting-numbers.yml
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

#ifdef LOCAL
int nn, xv;
set<int> _CUR;
int qc = 0;
int askA(int x) {
    qc++;
    int res = 0;
    for (int i = x; i <= nn; i += x)
        res += _CUR.count(i);
    return res;
}
int askB(int x) {
    qc++;
    int res = 0;
    for (int i = x; i <= nn; i += x) {
        if (_CUR.count(i)) {
            res++;
            if (i != xv) _CUR.erase(i);
        }
    }
    return res;
}
#else
int askA(int x) {
    cout << "A " << x << '\n'; cout.flush();
    int res; cin >> res; return res;
}
int askB(int x) {
    cout << "B " << x << '\n'; cout.flush();
    int res; cin >> res; return res;
}
#endif

// begin prorgam
const int MN = 1e5 + 1, BS = 100; // 100 = block size
int N;

// sieve and related
bool isp[MN];
vector<int> pr, small, large;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef LOCAL
    cin >> nn >> xv;
    N = nn;
    for (auto i = 1; i <= N; i++)
        _CUR.insert(i);
#else
    cin >> (N);
#endif

    // sieve
    memset(isp, true, sizeof isp);
    for (auto i = 2; i <= N; i++) {
        if (isp[i]) {
            pr.pb(i);
            for (int j = i * 2; j <= N; j += i)
                isp[j] = false;
        }
    }

    // get all distinct primes
    int ans = 1, sqn = 0;
    while (sqn * sqn <= N) sqn++;
    sqn--;
    for (auto p : pr) {
        if (p <= sqn) small.pb(p);
        else large.pb(p);
    }

    vector<int> pfs;
    // prime factors <= sqrt(N)
    for (auto p : small) {
        askB(p);
        if (askA(p) > 0) pfs.pb(p);
    }
    // prime factors > sqrt(N)
    int rem = SZ(large);
    for (auto i = 0; i < SZ(large); i++) {
        if (pfs.empty()) { // number is prime
            askB(large[i]);
            if (i % BS == (SZ(large) - 1) % BS) {
                if (askA(1) > rem) {
                    for (int j = max(0, i - BS + 1); j <= i; j++) {
                        if (askA(large[j]) > 0) {
                            pfs.pb(large[j]);
                            break;
                        }
                    }
                    break;
                }
            }

            rem--;
        }
        else if (askA(large[i]) > 1) { // number is composite
            pfs.pb(large[i]);
            break;
        }
    }

    // compute powers for each prime
    for (auto x : pfs) {
        ll cp = x;
        while (cp <= N && askA(cp) > 0) {
            ans *= x;
            cp *= x;
        }
    }

#ifdef LOCAL
    qc++;
    if (ans == xv && qc <= 10000) {
        cout << ("foo") << '\n';
        return 0;
    }
    cout<<"ans="<<(ans)<<", "; cout<<"xv="<<(xv)<<", "; cout << endl; // db ans, xv
    cout<<"qc="<<(qc)<<", "; cout << endl; // db qc
#else
    cout << "C " << ans << '\n';
    cout.flush();
#endif

    return 0;
}