// ./c-bear-and-drawing.yml
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

const int MN = 1e5 + 1;
int N,
    auxdeg[MN];
vector<int> g[MN], include;
bool mark[MN], onpath[MN];

int dfs(int c, int p) {
    int pre = -1;
    for (auto to : g[c]) {
        if (to != p) {
            int cv = dfs(to, c);
            if (cv != -1)
                pre = cv;
            if (SZ(g[c]) > 2 && cv != -1) {
                auxdeg[c]++;
                auxdeg[cv]++;
            }
        }
    }

    // if you have multiple "pre"s then SZ(g[c])>2 so no need to consider that case
    if (SZ(g[c]) > 2) {
        include.pb(c);
        return c;
    }
    return pre; 
}

int dfs2(int c, int p) {
    int pathcnt = 0, res = mark[c];

    for (auto to : g[c]) {
        if (to != p) {
            int cr = dfs2(to, c);
            res += cr;

            if (cr != 0 && (cr != 1 || !mark[to] || onpath[to]))
                pathcnt++;
        }
    }

    // cout<<"c="<<(c)<<", "; cout<<"p="<<(p)<<", "; cout<<"pathcnt="<<(pathcnt)<<", "; cout<<"res="<<(res)<<", "; cout << endl; // db c,p,pathcnt,res

    if (p == -1) {
        if (pathcnt > 2) {
            cout << ("No") << '\n';
            exit(0);
        }
    }
    else {
        if (pathcnt > 1) {
            cout << ("No") << '\n';
            exit(0);
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N);
    for (auto i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    int st = -1;
    for (auto i = 1; i <= N; i++) {
        if (SZ(g[i]) > 2) {
            st = i;
            break;
        }
    }
    if (st == -1) {
        cout << ("Yes") << '\n';
        return 0;
    }
    dfs(st, -1);
    for (auto x : include) {
        mark[x] = true;
        onpath[x] = SZ(g[x]) > 3 || auxdeg[x] > 1;

        // if (onpath[x]) { cout<<"[op]: "; cout<<"x="<<(x)<<", "; cout << endl; }
        // else { cout<<"x="<<(x)<<", "; cout << endl; }
    }
    st = -1;
    for (auto x : include) {
        if (onpath[x]) {
            st = x;
            break;
        }
    }
    if (st == -1) {
        cout << ("Yes") << '\n';
        return 0;
    }
    dfs2(st, -1);
    cout << ("Yes") << '\n';

    return 0;
}