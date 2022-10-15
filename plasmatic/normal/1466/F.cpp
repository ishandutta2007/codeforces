// ./f-euclids-nightmare.yml
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

const ll MOD = 1e9 + 7;
ll fix(ll &&x) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fix(ll &x) { x %= MOD; if (x < 0) x += MOD; return x; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return fpow(x * x % mod, y >> 1, mod) * ((y & 1) ? x : 1LL) % mod;
}
ll inv(ll x, ll mod = MOD) { return fpow(x, mod - 2, mod); }

const int MN = 5e5 + 1, LG = 20;
int N, M;
vector<int> v[MN];
bool basis[MN];

// int snd(int x) { return SZ(v[x]) < 2 ? -INF : v[x][1]; }
// bool cmpn(const int a, const int b) {
//     return v[a][0] == v[b][0] ? snd(a) < snd(b) : v[a][0] < v[b][0];
// }

// ...
// int tb[20][MN], dep[MN];
//
// int atleast(int c, int minv) {
//     for (auto k = LG-1; k >= 0; k--)
//         if (tb[k][c] >= minv)
//             c = tb[k][c];
//     return c;
// }
//
// int lca(int a, int b) {
//     if (a == b) return a;
//     if (dep[a] > dep[b]) swap(a, b);
//     int delta = dep[b] - dep[a];
//     for (auto i = 0; i < LG; i++) {
//         if ((delta >> i) & 1) {
//             if (tb[i][b] == -1)
//                 return -1;
//             b = tb[i][b];
//         }
//     }
//     if (a == b) return a;
//     for (auto i = LG-1; i >= 0; i--) {
//         if (tb[i][a] != tb[i][b]) {
//             a = tb[i][a];
//             b = tb[i][b];
//         }
//     }
//     if (tb[0][a] == tb[0][b]) return tb[0][a];
//     return -1;
// }

int dsu[MN];
void init() { iota(dsu, dsu + MN, 0); }
int get(int x) { return dsu[x] == x ? x : dsu[x] = get(dsu[x]); }
void mergeinto(int x, int y) { dsu[get(x)] = get(y); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M);
    for (auto i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (auto j = 0; j < k; j++) {
            int x;
            cin >> x;
            v[i].pb(x);
        }
        sort(all(v[i]), greater<int>());

        // cout<<"i="<<(i)<<", "; cout<<"snd(i)="<<(snd(i))<<", "; cout << endl; // db i,snd(i)
    }
    // cout<<"v[1][0]="<<(v[1][0])<<", "; cout<<"v[2][0]="<<(v[2][0])<<", "; cout << endl; // db v[1][0],v[2][0]

    // memset(tb, -1, sizeof tb);
    init();

    // sort(all(ord), cmpn);
    // cout << "ord=["; for (auto __x:ord)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:ord
    vector<int> inds;
    for (auto i = 0; i < N; i++) {
        // if (SZ(v[i]) == 2 && lca(v[i][0], v[i][1]) != -1) {
        //     cout<<"i="<<(i)<<", "; cout<<"lca(v[i][0], v[i][1])="<<(lca(v[i][0], v[i][1]))<<", "; cout << endl; // db i,lca(v[i][0], v[i][1])
        //     continue;
        // }
        //
        // int maxk = -INF;
        // for (auto j : v[i])
        //     maxa(maxk, atleast(j, 0));
        //
        // cout<<"i="<<(i)<<", "; cout<<"maxk="<<(maxk)<<", "; cout << endl; // db i,maxk

        vector<int> rt;
        for (auto j : v[i]) {
            // int c = atleast(j, maxk);
            // if (c > maxk) c = tb[0][c];
            // cout<<"j="<<(j)<<", "; cout<<"c="<<(c)<<", "; cout << endl; // db j,c
            rt.pb(get(j));
        }

        // sort rt
        if (SZ(rt) == 2) {
           if (rt[0] < rt[1]) swap(rt[0], rt[1]);
           if (rt[0] == rt[1]) rt.clear(); // cancel out
        }

        while (!rt.empty() && basis[rt[0]]) {
            rt.erase(rt.begin());
        }
        // if (!rt.empty() && basis[rt[0]]) {
        //     rt.erase(rt.begin());
        // }

        // cout<<"i="<<(i)<<", "; cout << endl; // db i
        // cout << "rt=["; for (auto __x:rt)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:rt

        // sort(all(rt), greater<int>());

        if (SZ(rt) > 0) {
            basis[rt[0]] = true;
            inds.pb(i);

            if (SZ(rt) == 2) {
                // tb[0][rt[0]] = rt[1];
                // dep[rt[0]] = dep[rt[1]] + 1;
                // for (auto j = 1; j < LG; j++) {
                //     int pp = tb[j-1][rt[0]];
                //     tb[j][rt[0]] = pp == -1 ? -1 : tb[j-1][pp];
                // }
                mergeinto(rt[0], rt[1]);
            }
        }
    }

    sort(all(inds));
    cout << (fpow(2, SZ(inds))) << ' ' << (SZ(inds)) << '\n';
    for (auto x : inds)
        cout << (x+1) << ' ';
    cout << '\n';

    return 0;
}