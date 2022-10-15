// ./e-colors-and-intervals.yml
#include <bits/stdc++.h>
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

const int MN = 101, MCNT = MN*MN;
int N, K,
    col[MCNT], cnt[MCNT];
vector<int> idx[MN];

int ceilDiv(int a, int b) { return (a+b-1) / b; }

bool done[MN];
pii ans[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (auto i = 1; i <= N*K; i++) {
        cin >> col[i];
        idx[col[i]].pb(i);
    }

    int most = ceilDiv(N, K-1);

    vector<pii> ps;
    for (auto i = 1; i <= N; i++) {
        for (auto j = 0; j < SZ(idx[i])-1; j++)
            ps.eb(idx[i][j+1], idx[i][j]);
    }
    sort(all(ps));

    for (auto [r, l] : ps) {
        int c = col[l];
        if (!done[c]) {
            bool ok = true;
            for (auto j = l; j <= r; j++) ok &= cnt[j] < most;

            if (ok) {
                for (auto j = l; j <= r; j++) cnt[j]++;
                done[c] = true;
                ans[c] = {l, r};
            }
        }
    }
    for (auto i = 1; i <= N; i++)
        assert(done[i]);

    for (auto i = 1; i <= N; i++) {
        cout << (ans[i].fs) << ' ' << (ans[i].sn) << '\n';
    }

    return 0;
}