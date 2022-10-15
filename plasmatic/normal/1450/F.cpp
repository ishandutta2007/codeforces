// ./f-the-struggling-contestant.yml
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

const int MN = 1e5 + 1;
int N,
    A[MN];

struct Seg {
    int l, r;
    int a() const { return A[l]; }
    int b() const { return A[r]; }
    bool same() const { return a() == b(); }

    bool operator<(const Seg &o) const {
        if (same() == o.same()) {
            if (a() == o.a()) {
                if (b() == o.b())
                    return l < o.l;
                return b() < o.b();
            }
            return a() < o.a();
        }
        return same() < o.same();
    }
};
ostream& operator<<(ostream& out, const Seg o) {
    out << "(l=" << o.l << ", r=" << o.r << ")";
    return out;
}

pii getMax(map<int, int> &mp) {
    int mxfre = 0, mxfreno = -1;
    for (auto p : mp) {
        if (p.sn > mxfre) {
            mxfre = p.sn;
            mxfreno = p.fs;
        }
    }
    return mpr(mxfre, mxfreno);
}

void solve() {
    cin >> (N);
    map<int, int> fre;
    for (auto i = 1; i <= N; i++) {
        cin >> (A[i]);
        fre[A[i]]++;
    }
    int mxfre = getMax(fre).fs;
    if (N - mxfre + 1 < mxfre) {
        cout << (-1) << '\n';
        return;
    }
    fre.clear();

    // if there exists a solution, we end up with some invariants
    int segc = 0;
    for (auto i = 1; i <= N; ) {
        int j = i;
        while (j < N && A[j] != A[j+1]) j++;

        fre[A[i]]++; fre[A[j]]++;
        segc++;

        i = j + 1;
    }

    auto mx = getMax(fre);
    int ans = (segc - 1) + max(0, mx.fs - (segc + 1));
    cout << (ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}