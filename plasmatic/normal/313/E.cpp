// e-ilya-and-two-numbers.yml
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


const int MN = 1e5 + 1;
int N, M,
    A[MN], B[MN], cnt[MN];

multiset<int> av[MN];
int dsu[MN];

void init(int N) { iota(dsu, dsu + N + 1, 0); }
int rt(int x) { return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }
void unite(int x, int y) {
    x = rt(x); y = rt(y);
    if (SZ(av[x]) < SZ(av[y])) swap(av[x], av[y]);
    av[x].insert(all(av[y]));
    av[y].clear();
    dsu[y] = x;
} // x into y
bool same(int x, int y) { return rt(x) == rt(y); }

multiset<int>::iterator bestPtr(int i) {
    auto ptr = av[i].lower_bound(M - i);
    if (ptr == av[i].begin()) {
        ptr = --av[i].end(); }
    else {
        ptr--; }
    return ptr;
}
int getBest(int i) { return (*bestPtr(i) + i) % M; }

set<pii, greater<pii>> best;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M);
    for (auto i = 0; i < N; i++)
        cin >> (A[i]);
    for (auto i = 0; i < N; i++) {
        cin >> (B[i]);
        cnt[B[i]]++;
    }

    init(M);
    for (auto i = 0; i < N; i++) {
        int tg = M - A[i] - 1;
        av[tg].insert(A[i]);
    }
    for (auto i = 0; i < M; i++)
        if (!cnt[i])
            unite((i - 1 + M) % M, i);

    set<int> rts;
    for (auto i = 0; i < M; i++) rts.insert(rt(i));
    for (auto x : rts) {
        if (!av[x].empty())
            best.emplace(getBest(x), x);
    }

    for (auto i = 0; i < N; i++) {
        auto p = *best.begin(); best.erase(best.begin());
        cnt[p.sn]--;
        av[p.sn].erase(bestPtr(p.sn));
        if (!cnt[p.sn]) {
            int pre = rt((p.sn - 1 + M) % M);
            if (!av[pre].empty())
                best.erase(mpr(getBest(pre), pre));
            unite(pre, p.sn);
            if (!av[pre].empty())
                best.emplace(getBest(pre), pre);
        }
        else if (!av[p.sn].empty()) {
            best.emplace(getBest(p.sn), p.sn); }
        cout << p.fs << ' ';
    }
    cout << '\n';

    return 0;
}