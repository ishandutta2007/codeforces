// ./d-strange-housing.yml
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

const int MN = 3e5 + 1;
int N, M;

vector<int> g[MN];
int vis[MN];

void solve() {
    cin >> N >> M;
    for (auto i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    queue<int> q;
    vector<int> sel;
    q.push(1); vis[1] = 2;
    while (!q.empty()) {
        auto c = q.front(); q.pop();
        if (vis[c] == 2) sel.pb(c);
        for (auto to : g[c]) {
            if (!vis[to]) {
                vis[to] = vis[c] == 1 ? 2 : 1;
                q.push(to);
            }
            else if (vis[c] == 2 && vis[to] == 2)
                vis[to] = 1;
        }
    }
    for (auto i = 1; i <= N; i++) {
        if (vis[i] == 0) {
            return void(cout << "NO\n");
        }
    }
    cout << "YES\n" << sel.size() << '\n';
    for (auto x : sel) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();
        for (auto i = 1; i <= N; i++) {
            g[i].clear();
            vis[i] = 0;
        }

        // Reset
    }
}