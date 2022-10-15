// ./c-penalty.yml
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

string s;

int player(int turn) {
    return turn & 1;
}

void solve() {
    cin >> s;

    vector<int> ch;
    for (auto i = 0; i < 10; i++)
        if (s[i] == '?')
            ch.pb(i);

    int sz = SZ(ch), msub = 1<<sz, ans = 10;
    for (auto i = 0; i < msub; i++) {
        string cs = s;
        for (auto j = 0; j < sz; j++) {
            if ((i >> j) & 1)
                cs[ch[j]] = '1';
            else
                cs[ch[j]] = '0';
        }

        // cout<<"cs="<<(cs)<<", "; cout << endl; // db cs
        int p1 = 0, p2 = 0;
        for (auto j = 0; j < 10; j++) {
            if (cs[j] == '1') {
                if (!player(j)) p1++;
                else p2++;
            }

            int rem1 = 0, rem2 = 0;
            for (auto k = j+1; k < 10; k++) {
                if (player(k)) rem2++;
                else rem1++;
            }

            // cout<<"j="<<(j)<<", "; cout<<"p1="<<(p1)<<", "; cout<<"p2="<<(p2)<<", "; cout<<"rem1="<<(rem1)<<", "; cout<<"rem2="<<(rem2)<<", "; cout << endl; // db j,p1,p2,rem1,rem2

            if (p1 > p2+rem2 || p2 > p1+rem1) {
                mina(ans, j+1);
                break;
            }
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