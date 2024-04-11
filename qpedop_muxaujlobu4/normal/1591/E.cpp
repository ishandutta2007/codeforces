#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned short us;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1000000000;
const int mod = 998244353;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 1 << 21, maxT = 119, A = 179, K = 450;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
    b %= mod - 1;
    et %= mod;
    ll res = 1;
    for (int i = 30; i >= 0; --i) {
        res = (res * res) % mod;
        if ((b & (1 << i)) != 0)res = (res * et) % mod;
    }
    return res;
}
void panic() {
    cout << "impossible\n";
    exit(0);
}
int t[maxN];
int sz = 1 << 20;
void add(int ps, int vl) {
    for (ps += sz; ps; ps >>= 1)t[ps] += vl;
}
int get(int l, int r) {
    int res = 0;
    for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
        if (l % 2 == 1)res += t[l++];
        if (r % 2 == 0)res += t[r--];
    }
    return res;
}
int find(int nmb, int tl = 0, int tr = sz - 1, int v = 1) {
    if (tl == tr)return tl;
    int m = (tr + tl) / 2;
    if (t[2 * v] < nmb) {
        nmb -= t[2 * v];
        return find(nmb, m + 1, tr, 2 * v + 1);
    }
    return find(nmb, tl, m, 2 * v);
}
int p[maxN];
int cnt[maxN];
vector<vector<int>>g;
set<int>vlss[maxN];
vector<vector<tuple<int, int, int>>>qw;
int ans[maxN];

void dfs(int v, int pr = -1) {
    if (cnt[p[v]]) {
        add(cnt[p[v]], -1);
        vlss[cnt[p[v]]].erase(p[v]);
    }
    ++cnt[p[v]];
    add(cnt[p[v]], 1);
    vlss[cnt[p[v]]].insert(p[v]);
    for (auto x : g[v]) {
        if (x == pr)
            continue;
        dfs(x, v);
    }
    for (auto qq : qw[v]) {
        int lw, nb, idx;
        tie(lw, nb, idx) = qq;
        int cnt_bf = get(0, lw - 1);
        nb += cnt_bf;
        if (nb > t[1]) {
            ans[idx] = -1;
            continue;
        }
        ans[idx] = *vlss[find(nb)].begin();
    }
    add(cnt[p[v]], -1);
    vlss[cnt[p[v]]].erase(p[v]);
    --cnt[p[v]];
    if (cnt[p[v]]) {
        add(cnt[p[v]], 1);
        vlss[cnt[p[v]]].insert(p[v]);
    }
}
void solve() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    g.assign(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i < n; ++i) {
        int pp;
        cin >> pp;
        g[--pp].push_back(i);
    }
    qw.assign(n, vector<tuple<int, int, int>>());
    for (int i = 0; i < q; ++i) {
        int v, l, k;
        cin >> v >> l >> k;
        qw[--v].push_back(make_tuple(l, k, i));
    }
    dfs(0);
    for (int i = 0; i < q; ++i)cout << ans[i] << " "; cout << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(20);
    srand(time(0));
#ifdef _DEBUG
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
    //freopen("hear.in", "r", stdin); freopen("hear.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}