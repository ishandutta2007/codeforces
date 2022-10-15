// ./d-unshuffling-a-deck.yml
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

const int MN = 55;
int N,
    val[MN], tmp[MN];

vector<vector<int>> ops;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 1; i <= N; i++)
        cin >> (val[i]);

    int end = N & 1;
    for (auto i = 1; i <= N; i++) {
        // get tmp
        int target = (i & 1) == end ? i : (N - i + 1);
        copy(val + 1, val + N + 1, tmp + 1);
        reverse(tmp + 1, tmp + N + 1);

        // get ind
        int idx = -1;
        for (auto j = 1; j <= N; j++) {
            if (tmp[j] == i) {
                idx = j;
                break;
            }
        }

        // compute ks
        int l = target, r = idx; if (l > r) swap(l, r);
        vector<int> ks;
        for (auto j = 0; j < l-1; j++) ks.pb(1);
        ks.pb(r - l + 1);
        for (auto j = 0; j < N-r; j++) ks.pb(1);
        reverse(all(ks));

        // simulate
        vector<vector<int>> comps;
        int pre = 0;
        for (auto &x : ks) {
            vector<int> cc;
            for (auto j = pre+1; j <= pre+x; j++)
                cc.pb(val[j]);
            comps.pb(cc);
            pre += x;
        }
        reverse(all(comps));
        vector<int> newv;
        for (auto &c : comps) newv.insert(newv.end(), all(c));
        copy(all(newv), val + 1);

        if (SZ(ks) > 1)
            ops.pb(ks);

        // cout<<"i="<<(i)<<", "; cout<<"(val+1)=["; for(int __i=0; __i<(N); __i++)cout<<(val+1)[__i]<<", "; cout<<"], ";cout << endl; // db i,A:N:(val+1)
    }

    for (auto i = 2; i <= N; i++)
        assert(val[i] > val[i - 1]);

    // output
    cout << (SZ(ops)) << '\n';
    for (auto &ks : ops) {
        cout << SZ(ks) << ' ';
        for (auto x : ks) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}