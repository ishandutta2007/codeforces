// ./d-its-a-bird-no-its-a-plane-no-its-aaparsa.yml
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

const int MN = 601;
int N, M;
// vector<pii> g[MN];
ll adj[MN][MN];

// V^2 dijkstra
ll dis[MN];
bool inq[MN];

int mod(int k) { 
    k %= N;
    if (k < 0) k += N;
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    memset(adj, 0x3f, sizeof adj);
    for (auto i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        // g[a].eb(b, c);
        mina(adj[a][b], (ll)c);
    }

    for (auto i = 0; i < N; i++) {
        fill(dis, dis+N+1, LLINF);
        dis[i] = 0; inq[i] = true; 

        // cout<<"[FINDDIS]: "; cout<<"i="<<(i)<<", "; cout << endl; // db l:FINDDIS,i
        while (1) {
            int c = -1; ll bd = LLINF;
            for (auto j = 0; j < N; j++) {
                if (inq[j] && dis[j] < bd) {
                    bd = dis[j];
                    c = j;
                }
            }
            if (c == -1) break;
            inq[c] = false; // unqueue

            // cout<<"c="<<(c)<<", "; cout<<"dis[c]="<<(dis[c])<<", "; cout<<"dis[c]%N="<<(dis[c]%N)<<", "; cout << endl; // db c,dis[c],dis[c]%N

            int md = dis[c]%N;
            ll bestw = LLINF;
            for (auto j = 0; j < N; j++) {
                int tj = mod(j-md);
                if (adj[c][tj] != LLINF) {
                    // cout<<"j="<<(j)<<", "; cout<<"tj="<<(tj)<<", "; cout<<"adj[c][tj]="<<(adj[c][tj])<<", "; cout<<"adj[c][tj]+N-j="<<(adj[c][tj]+N-j)<<", "; cout << endl; // db j,tj,adj[c][tj],adj[c][tj]+N-j
                    mina(bestw, adj[c][tj]+N-j);
                }
            }
            for (auto j = 0; j < N; j++) {
                bestw = min(bestw+(j>0), adj[c][mod(j-md)]); // not first
                ll alt = dis[c]+bestw;
                // cout<<"j="<<(j)<<", "; cout<<"bestw="<<(bestw)<<", "; cout<<"alt="<<(alt)<<", "; cout<<"dis[j]="<<(dis[j])<<", "; cout << endl; // db j,bestw,alt,dis[j]
                if (alt < dis[j]) {
                    dis[j] = alt;
                    inq[j] = true;
                }
            }
        }

        for (auto j = 0; j < N; j++)
            cout << dis[j] << " \n"[j == N-1];
    }

    return 0;
}