// c-beautiful-rectangle.yml
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

const int MN = 4e5 + 1;
int N;
vector<pii> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    map<int, int> ccnt;
    for (auto i = 0; i < N; i++) {
        int x;
        cin >> x;
        ccnt[x]++;
    }
    cnt = vector<pii>(all(ccnt));
    sort(all(cnt), [&] (const pii &a, const pii &b) { return a.sn > b.sn; });

    int bestr = 0, bestc = 0;
    for (int i = 1; i * i <= N; i++) {
        int cres = 0;
        for (auto p : cnt) cres += min(p.sn, i);
        cres = cres / i * i;
        // cout<<"i="<<(i)<<", "; cout<<"cres="<<(cres)<<", "; cout<<"cres/i="<<(cres/i)<<", "; cout << endl; // db i,cres,cres/i
        if (cres / i >= i && cres > bestr * bestc) {
            bestr = i;
            bestc = cres / i;
        }
    }

    cout << (bestr*bestc) << '\n';
    cout << (bestr) << ' ' << (bestc) << '\n';
    vector<vector<int>> ans(bestr, vector<int>(bestc));
    vector<int> tape;
    for (auto p : cnt) {
        mina(p.sn, bestr);
        while (p.sn--) tape.pb(p.first);
    }
    // cout << "tape=["; for (auto __x:tape)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:tape
    int idx = 0;
    for (auto i = 0; i < bestc; i++) {
        for (int c = i, r = 0; r < bestr; c = (c + 1) % bestc, r++) {
            assert(!ans[r][c]);
            ans[r][c] = tape[idx++];
        }
    }
    for (auto &r : ans) {
        for (auto c : r) cout << c << ' '; 
        cout << '\n';
    }

    return 0;
}