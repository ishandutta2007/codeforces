// ./b-jzzhu-and-cities.yml
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

struct ed {
    int v; bool tk; ll w;
    bool operator<(const ed &o) const {
        return w > o.w;
    }
};

const int MN = 1e5 + 1;
int N, M, K;
vector<ed> g[MN];
ll dis[MN][2], mind[MN]; // dis[i][0/1] -> node, just came from train
bool tk[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M) >> (K);
    for (auto i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, 0, c});
        g[b].pb({a, 0, c});
    }

    memset(mind, 0x3f, sizeof mind);
    int ans = 0;
    for (auto i = 0; i < K; i++) {
        int n, w;
        cin >> n >> w;
        mind[n] = min(mind[n], (ll)w);
        if (tk[n]) ans++;
        tk[n] = true;
    }
    for (auto i = 1; i <= N; i++)
        if (mind[i] != LLINF)
            g[1].push_back({i, 1, mind[i]});

    memset(dis, 0x3f, sizeof dis);
    priority_queue<ed> pq; pq.push({1, 0, 0}); dis[1][0] = 0;
    while (!pq.empty()) {
        auto c = pq.top(); pq.pop();
        if (c.w > dis[c.v][c.tk]) continue;
        for (auto to : g[c.v]) {
            ll alt = c.w + to.w;
            if (alt < dis[to.v][to.tk]) {
                dis[to.v][to.tk] = alt;
                pq.push({to.v, to.tk, alt});
            }
        }
    }
    for (auto i = 1; i <= N; i++)
        if (dis[i][1] != LLINF)
            ans += dis[i][0] <= dis[i][1];
    cout << (ans) << '\n';

    return 0;
}