// ./f-lost-root.yml
#include "bits/stdc++.h"
#include <random>
using namespace std;

// Defines good rng good rng
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

const int MN = 1501;
const ull SEED = time(NULL);
// const ull SEED = 1607013174;
int N, K;
mt19937 mt(SEED);

int randint(int a, int b) { return uniform_int_distribution<int>(a, b)(mt); }
template <typename T> T choice(vector<T> &v) { return v[randint(0, SZ(v)-1)]; }

ostream& operator<<(ostream& out, const pii o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

#ifdef LOCAL
const int NN = 1023;
int dis[MN];
void dfs(int c, int cdis) {
    if (c <= 0 || c > N) return;
    if (dis[c] != -1) return;
    dis[c] = cdis;
    dfs(c / 2, cdis+1); dfs(c * 2, cdis+1); dfs(c * 2 + 1, cdis+1);
}
bool ask(int a, int b, int c) {
    a = N-a+1;
    b = N-b+1;
    c = N-c+1;
    memset(dis, -1, sizeof dis);
    dfs(b, 0); int use = dis[a] + dis[c];
    memset(dis, -1, sizeof dis);
    dfs(a, 0);
    return dis[c] == use;
}
void answer(int n) {
    cout<<"[got]: "; cout<<"n="<<(n)<<", "; cout << endl; // db l:got,n
    cout<<"[expect 1]: "; cout << endl; // db l:expect 1
}
#else
bool ask(int a, int b, int c) {
    cout << "? " << a << ' ' << b << ' ' << c << '\n'; cout.flush();
    string res;
    cin >> res;
    return res == "Yes";
}
void answer(int n) {
    cout << "! " << n << '\n';
    cout.flush();
}
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef LOCAL
    N = NN;
    K = 2;
    cout<<"SEED="<<(SEED)<<", "; cout << endl; // db SEED
#else
    cin >> (N) >> (K);
#endif
    // cout<<"N="<<(N)<<", "; cout<<"K="<<(K)<<", "; cout << endl; // db N,K
    vector<pii> dif;
    for (auto i = 1; i <= N; i++) dif.eb(0, i);
    for (auto i = 0; i <= N; i++)
        swap(dif[randint(0, N-1)], dif[randint(0, N-1)]);
    while (SZ(dif) > 1) {
        for (auto &x : dif) {
            x.fs = 0;
            for (auto i = 0; i < 40; i++) {
                int a = x.sn, b = x.sn;
                while (a == b || a == x.sn || b == x.sn) {
                    a = choice(dif).sn;
                    b = choice(dif).sn;
                }
                x.fs += ask(a, x.sn, b);
            }
        }
        vector<pii> dif2;
        for (auto &p : dif) if (p.fs) dif2.eb(0, p.sn);
        dif2.swap(dif);
    }
    answer(dif[0].sn);

    return 0;
}