// ./c2-errich-tac-toe-hard-version.yml
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

const int MN = 301;
int N;
string grid[MN];

void solve() {
    cin >> (N);
    int kc = 0;
    for (auto i = 0; i < N; i++) {
        cin >> (grid[i]);
        for (auto c : grid[i]) kc += c != '.';
    }

    // no Xs on man=i, no Os on man=j
    int cnt[9]; fill(cnt, cnt + 9, 0);
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            if (i == j) continue;
            int idx = i*3+j;
            for (auto k = 0; k < N; k++) {
                for (auto l = 0; l < N; l++) {
                    if (grid[k][l] == '.') continue;
                    int man = (k + l) % 3;
                    if ((grid[k][l] == 'X' && man == i) || (grid[k][l] == 'O' && man == j)) {
                        cnt[idx]++;
                    }
                }
            }
        }
    }

    int minv = -1, best = INF;
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            if (i == j) continue;
            int idx = i*3+j;
            if (cnt[idx] < best) {
                best = cnt[idx];
                minv = idx;
            }
        }
    }
    // cout<<"minv="<<(minv)<<", "; cout<<"cnt[minv]="<<(cnt[minv])<<", "; cout << endl; // db minv,cnt[minv]
    assert(cnt[minv] <= kc / 3);
    
    int xset = minv/3, oset = minv%3;
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < N; j++) {
            int man = (i + j) % 3;
            if (grid[i][j] == 'X') {
                if (man == xset)
                    grid[i][j] = 'O';
            }
            else if (grid[i][j] == 'O') {
                if (man == oset)
                    grid[i][j] = 'X';
            }
        }
    }
    for (auto i = 0; i < N; i++)
        cout << (grid[i]) << '\n';
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