// ./c-representative-edges.yml
#include <bits/stdc++.h>
#define DEBUG 0
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
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

const int MN = 71;
int N,
    A[MN];

void solve() {
    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (N == 1) {
        cout << (0) << '\n';
        return;
    }

    int ans = INF;
    for (auto i = 0; i < N; i++) {
        for (auto j = i+1; j < N; j++) {
            int cans = 0, dY = A[j] - A[i], dX = j - i, want = A[j];

            int g = abs(gcd(dY, dX));
            dY /= g;
            dX /= g;

            int init = j;
            while (init >= dX) {
                init -= dX;
                want -= dY;
            }

            if (DEBUG) { cout<<"init="<<(init)<<", "; cout<<"want="<<(want)<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db init,want

            int hit = 0;
            for (auto k = init; k < N; k += dX) {
                hit++;
                cans += A[k] != want;
                want += dY;
            }

            cans += N - hit;
            if (DEBUG) { cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"dX="<<(dX)<<", "; cout<<"dY="<<(dY)<<", "; cout<<"cans="<<(cans)<<", "; cout<<"hit="<<(hit)<<", "; cout << endl; } //__RAW_DEBUG_LINE__:db i,j,dX,dY,cans,hit

            mina(ans, cans);
        }
    }

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