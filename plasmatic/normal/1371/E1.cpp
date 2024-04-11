// e2-asterism-hard-version.yml
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
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

/*
 * Sort the values, consider the possible starting positions of A_i given x
 * -> (0-indexed) minpos_i = max(0, A_i - x)
 *      > This gives us an N^2 solution
 * -> Once minpos_p = 0, then no more good numbers exist.
 * -> Simple optimization to O(NsqrtN)
 */

const int MN = 1e5 + 1, B = 316;
ll N, P,
   val[MN];
bool canUse[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (P);
    for (auto i = 0; i < N; i++)
        cin >> (val[i]);
    sort(val, val + N);
    ll mn = -LLINF;
    for (auto i = 0; i < N; i++)
        maxa(mn, val[i] - i);

    vector<ll> ans;
    ll mx = LLINF;
    for (auto i = P - 1; i < N; i += P)
        mina(mx, val[i]);
    if (P > B) {
        set<ll> bad;
        for (auto i = 0; i < N; i++) {
            ll st = P - i - 1 + val[i];
            // cout<<"[st]: "; cout<<"i="<<(i)<<", "; cout<<"st="<<(st)<<", "; cout << endl; // db l:st,i,st
            while (val[i] - st >= 0) {
                // cout<<"[bad]: "; cout<<"st="<<(st)<<", "; cout << endl; // db l:bad,st
                bad.insert(st);
                st += P;
            }
        }
        for (auto i = mn; i <= mx; i++)
            if (!bad.count(i))
                ans.pb(i);
    }
    else {
        for (auto i = mn; i <= mx; i++) {
            bool good = true;
            for (auto j = 0; j < N; j++) {
                int len = j - max(0LL, val[j] - i) + 1;
                // cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"len="<<(len)<<", "; cout << endl; // db i,j,len
                good &= len % P != 0;
            }
            if (good)
                ans.pb(i);
        }
    }

    cout << (SZ(ans)) << '\n';
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';

    return 0;
}