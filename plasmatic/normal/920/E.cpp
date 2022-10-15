// ./e-connected-components.yml
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

const int MN = 2e5 + 10;
int N, M;
vector<int> g[MN];
bool explore[MN];

queue<int> q;
set<int> need;
void process(int c) {
    for (auto x : g[c])
        if (need.count(x))
            need.erase(x);

    // cout<<"c="<<(c)<<", "; cout << "need=["; for (auto __x:need)cout<<__x<<", "; cout<<"], "; cout << endl; // db c,I:need
    for (auto x : vector<int>(all(need))) {
        // cout<<"[adj]: "; cout<<"x="<<(x)<<", "; cout << endl; // db l:adj,x
        if (!explore[x]) {
            explore[x] = true;
            need.erase(x);
            q.push(x);
        }
    }

    for (auto x : g[c])
        if (!explore[x])
            need.insert(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M);
    for (auto i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for (auto i = 1; i <= N; i++) need.insert(i);
    vector<int> ans;
    for (auto i = 1; i <= N; i++) {
        if (!explore[i]) {
            // cout<<"[start]: "; cout<<"i="<<(i)<<", "; cout << endl; // db l:start,i
            int cur = 0;
            q.push(i);
            need.erase(i);
            explore[i] = true;
            while (!q.empty()) {
                int f = q.front(); q.pop();
                cur++;
                process(f);
            }
            ans.pb(cur);
        }
    }
    sort(all(ans));
    cout << (SZ(ans)) << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';

    return 0;
}