// ./b-boboniu-walks-on-graph.yml
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

const ll MOD = 1e9 + 7;
ll madd(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll msub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mmul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }
ll fpow(ll x, ll y, ll mod = MOD) {
    if (!y) return 1LL;
    return mmul(fpow(mmul(x, x, mod), y >> 1, mod), (y & 1) ? x : 1LL, mod);
}
ll mdiv(ll x, ll y, ll mod = MOD) { return mmul(x, fpow(y, mod - 2, mod), mod); }

const int MN = 2e5 + 1, MK = 10;
int N, M, K;
vector<pii> g[MN];
ll gain[MK][MK], WN[MN], wsum = 0;

ll ans = 0, cval = 0;
int cur[MK];
void solve(int c) {
    if (c == K) {
        // cout<<"cur=["; for(int i=0; i<(K); i++)cout<<cur[i]<<", "; cout<<"], ";cout<<"cval="<<(cval)<<", "; cout << endl; // db A:K:cur,cval
        ans += cval == wsum;
        return;
    }

    for (auto i = 0; i <= c; i++) {
        cur[c] = i;
        cval += gain[c][i];
        solve(c + 1);
        cval -= gain[c][i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M) >> (K);

    mt19937_64 mt(RANDOM);
    // mt19937_64 mt(69);
    uniform_int_distribution<ll> dis(1, 1e12);
    // uniform_int_distribution<ll> dis(1, 100);
    for (auto i = 1; i <= N; i++) {
        WN[i] = dis(mt);
        wsum += WN[i];
    }

    for (auto i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].eb(c, b);
    }
    for (auto i = 1; i <= N; i++) {
        sort(all(g[i]));
        for (auto j = 0; j < SZ(g[i]); j++) {
            gain[SZ(g[i]) - 1][j] += WN[g[i][j].sn];
            // cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"SZ(g[i])="<<(SZ(g[i]))<<", "; cout<<"g[i][j].sn="<<(g[i][j].sn)<<", "; cout << endl; // db i,j,SZ(g[i]),g[i][j].sn
        }
    }
    // cout<<"(WN+1)=["; for(int i=0; i<(N); i++)cout<<(WN+1)[i]<<", "; cout<<"], ";cout << endl; // db A:N:(WN+1)
    // for (auto i = 0; i < K; i++) {
    //     for (auto j = 0; j <= i; j++) {
    //         cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"gain[i][j]="<<(gain[i][j])<<", "; cout << endl; // db i,j,gain[i][j]
    //     }
    // }

    solve(0);
    cout << (ans) << '\n';

    return 0;
}