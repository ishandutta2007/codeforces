// f-robots-on-a-grid.yml
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

ostream& operator<<(ostream& out, const pii o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

const int MN = 1e6 + 1, DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
map<char, int> DMAP;
int N, M;
vector<vector<int>> val, dir;
vector<int> g[MN], rg[MN];

int mk(int x, int y) { return x * M + y; }
int X(int x) { return x / M; }
int Y(int x) { return x % M; }

bool done = false,
    vis[MN], instk[MN];
vector<int> cycle, stk;
void findCycle(int c) {
    if (done) return;
    vis[c] = instk[c] = true; stk.pb(c);
    // cout<<"c="<<(c)<<", "; cout << "stk=["; for (auto x:stk)cout<<x<<", "; cout<<"], "; cout << endl; // db c,I:stk
    for (int to : g[c]) {
        if (done) return;
        // cout<<"to="<<(to)<<", "; cout << endl; // db to
        if (!vis[to])
            findCycle(to);
        else if (instk[to]) {
            while (stk.back() != to) {
                int cc = stk.back();
                instk[cc] = false;
                cycle.pb(cc);
                stk.pop_back();
            }
            instk[to] = false;
            cycle.pb(to);
            stk.pop_back();
            return;
        }
    }
}
void dfs(int c, int cdep, vector<pii> &cnt) {
    if (vis[c]) return;
    vis[c] = true;
    cnt[cdep].fs++; cnt[cdep].sn += val[X(c)][Y(c)];
    for (auto to : rg[c])
        dfs(to, (cdep + 1) % SZ(cnt), cnt);
}

void solve() {
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < M; j++) {
            auto d = DIR[dir[i][j]];
            int f = mk(i, j), t = mk(i + d[0], j + d[1]);
            // cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"f="<<(f)<<", "; cout<<"t="<<(t)<<", "; cout << endl; // db i,j,f,t
            // int x=i+d[0],y=j+d[1];
            // cout<<"x="<<(x)<<", "; cout<<"y="<<(y)<<", "; cout<<"dir[i][j]="<<(dir[i][j])<<", "; cout << endl; // db x,y,dir[i][j]
            g[f].pb(t);
            rg[t].pb(f);
        }
    }
    vector<vector<int>> cycles;
    for (auto i = 0; i < N*M; i++) {
        if (!vis[i]) {
            cycle.clear();
            done = false;
            findCycle(i);
            if (!cycle.empty())
                cycles.pb(cycle);
            while (!stk.empty()) {
                instk[stk.back()] = false;
                stk.pop_back();
            }
        }
    }
    fill(vis, vis + N*M, false);
    pii ans;
    for (auto &cyc : cycles) {
        int sz = SZ(cyc);
        vector<pii> cnt(sz);
        dfs(cyc[0], 0, cnt);
        // cout << "cyc=["; for (auto x:cyc)cout<<x<<", "; cout<<"], "; cout << endl; // db I:cyc
        // cout << "cnt=["; for (auto x:cnt)cout<<x<<", "; cout<<"], "; cout << endl; // db I:cnt
        for (auto p : cnt) {
            ans.fs += p.fs > 0;
            ans.sn += p.sn > 0;
        }
    }
    cout << (ans.fs) << ' ' << (ans.sn) << '\n';
}

int main() {
    for (auto i = 0; i < 4; i++)
        DMAP["DURL"[i]] = i;

    int T;
    cin >> T;
    while (T--) {
        // Input
        cin >> (N) >> (M);
        val = vector<vector<int>>(N, vector<int>(M));
        dir = vector<vector<int>>(N, vector<int>(M));
        for (auto i = 0; i < N; i++) {
            string tmp; cin >> tmp;
            for (auto j = 0; j < M; j++)
                val[i][j] = tmp[j] == '0';
        }
        for (auto i = 0; i < N; i++) {
            string tmp; cin >> tmp;
            for (auto j = 0; j < M; j++)
                dir[i][j] = DMAP[tmp[j]];
        }
        
        solve();

        // Reset
        for (auto i = 0; i < N*M; i++) {
            g[i].clear();
            rg[i].clear();
        }
        fill(vis, vis + N*M, false);
    }
}