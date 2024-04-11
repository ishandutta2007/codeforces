//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
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
const ll INF = 1e18 + 100;
const int mod = 998244353;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 200010, maxT = 200000, A = 179, K = 450;
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
vector<int>g[maxN];
int dep[maxN];
int cntt[maxN];
int tmr[maxN], tt(0);
int pr[maxN];
void dfs(int v, int dd = 1, int p = -1) {
    dep[v] = dd;
    cntt[v] = 1;
    tmr[v] = tt++;
    pr[v] = p;
    for (auto x : g[v]) {
        if (x == p)continue;
        dfs(x, dd + 1, v);
        cntt[v] += cntt[x];
    }
}
int sz(1);
int used[maxN];
pair<int, int > t[maxN * 4];
int push[maxN * 4];
void pushh(int v) {
    t[v].first += push[v];
    if (v < sz) {
        push[2 * v] += push[v];
        push[2 * v + 1] += push[v];
    }
    push[v] = 0;
}
void add(int l, int r, int tl = 0, int tr = sz - 1, int v = 1) {
    if (l <= tl && tr <= r) {
        push[v] += -1;
        pushh(v);
        return;
    }
    int m = (tr + tl) / 2;
    if (l <= m)add(l, r, tl, m, 2 * v);
    if (r > m)add(l, r, m + 1, tr, 2 * v + 1);
    pushh(2 * v);
    pushh(2 * v + 1);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0);
    vector<int>lns;
    for (int i = 1; i < n; ++i)if (g[i].size() == 1)lns.push_back(1);
    sort(lns.begin(), lns.end());
    if (lns.size() <= k) {
        ll ans = 0;
        for (int i = lns.size(); i <= k; ++i) {
            if (i == n)break;
            ans = max(ans, (ll)i * (n - i));
        }
        cout << ans << "\n";
        return;
    }
    ll enemy(n);
    while (sz < n)sz <<= 1;
    for (int i = 0; i < n; ++i) {
        t[tmr[i] + sz].second = i;
        t[tmr[i] + sz].first = dep[i];
    }
    for (int i = sz - 1; i > 0; --i) {
        t[i] = max(t[2 * i], t[2 * i + 1]);
    }
    for (int i = 0; i < k; ++i) {
        pushh(1);
        int vv = t[1].second;
        enemy -= t[1].first;
        while (vv != -1 && !used[vv]) {
            add(tmr[vv], tmr[vv] + cntt[vv] - 1);
            used[vv] = 1;
            vv = pr[vv];
        }
    }
    ll ans = INF;
    for (int i = 0; i <= enemy; ++i) {
        ll w = n - i - k;
        ans = min(ans, w * (k - i));
    }
    cout << ans << endl;
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
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}