// ./e-minimax.yml
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
int N;

void solve() {
    cin >> s;
    N = SZ(s);

    vector<int> fre(26);

    sort(all(s));
    for (auto x : s) fre[x-'a']++;

    int f1 = -1, distc = 0;
    for (auto i = 25; i >= 0; i--) {
        if (fre[i] == 1)
            f1 = i;
        distc += fre[i] > 0;
    }

    if (f1 != -1) {
        cout << char(f1+'a');
        for (auto x : s)
            if (x-'a' != f1)
                cout << x;
        cout << '\n';
        return;
    }

    string ans;
    vector<char> o;
    for (auto i = 0; i < N; i++)
        if (s[i] != s[0])
            o.pb(s[i]);
    int cntl = N-SZ(o);
    char cl = s[0];

    if (cntl-2 <= SZ(o)) {
        ans += cl;
        ans += cl;
        cntl -= 2;

        int optr = 0;
        while (cntl > 0) {
            ans += o[optr++];
            ans += cl;
            cntl--;
        }
        for (auto i = optr; i < SZ(o); i++)
            ans += o[i];
    }
    else {
        if (distc > 2) {
            char d1 = o[0];
            o.erase(o.begin());

            auto ptr = upper_bound(all(o), d1);
            char d2 = *ptr;
            o.erase(ptr);

            ans += cl;
            ans += d1;
            for (auto i = 0; i < cntl-1; i++) ans += cl;
            ans += d2;
            for (auto x : o) ans += x;
        }
        else {
            ans += cl;
            for (auto c : o) ans += c;
            for (auto i = 0; i < cntl-1; i++) ans += cl;
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