// f-super-jaber.yml
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

// naNAnaNAnaNAnaNA
using state = pair<short, short>;
const int MN = 1001, MK = 41, DIR[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int N, M, K, Q,
    val[MN][MN];
short tele[MK][MN][MN], notele[MK][MN][MN];
bool done[MK];
vector<state> cells[MK];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M) >> (K);
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < M; j++) {
            cin >> (val[i][j]);
            val[i][j]--;
            cells[val[i][j]].eb(i, j);
        }
    }

    memset(notele, -1, sizeof notele);
    memset(tele, -1, sizeof tele);
    for (auto i = 0; i < K; i++) {
        // from (any cell in clr) -> any cell (w/ teleportations)
        queue<state> q;
        auto dis = tele[i];
        for (auto p : cells[i]) {
            q.push(p);
            dis[p.fs][p.sn] = 0;
        }
        done[i] = true;
        while (!q.empty()) {
            auto c = q.front(); q.pop();
            int d = dis[c.fs][c.sn], clr = val[c.fs][c.sn];
            if (!done[clr]) {
                done[clr] = true;
                for (auto to : cells[clr]) {
                    if (dis[to.fs][to.sn] == -1) {
                        dis[to.fs][to.sn] = d + 1;
                        q.push(to);
                    }
                }
            }
            for (auto D : DIR) {
                int x = c.fs + D[0], y = c.sn + D[1];
                if (x >= 0 && x < N && y >= 0 && y < M && dis[x][y] == -1) {
                    dis[x][y] = d + 1;
                    q.emplace(x, y);
                }
            }
        }
        fill(done, done + K, false);
        
        // from (any cell in clr) -> any cell (only ULDR)
        dis = notele[i];
        for (auto p : cells[i]) {
            q.push(p);
            dis[p.fs][p.sn] = 0;
        }
        while (!q.empty()) {
            auto c = q.front(); q.pop();
            int d = dis[c.fs][c.sn];
            for (auto D : DIR) {
                int x = c.fs + D[0], y = c.sn + D[1];
                if (x >= 0 && x < N && y >= 0 && y < M && dis[x][y] == -1) {
                    dis[x][y] = d + 1;
                    q.emplace(x, y);
                }
            }
        }
    }

    cin >> (Q);
    while (Q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2; r1--; c1--; r2--; c2--;
        int ans = abs(r1 - r2) + abs(c1 - c2);
        for (auto i = 0; i < K; i++) {
            mina(ans, notele[i][r1][c1] + tele[i][r2][c2] + 1); }
        cout << (ans) << '\n';
    }

    return 0;
}