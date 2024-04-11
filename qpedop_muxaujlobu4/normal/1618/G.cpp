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
const ll INF = 1000000000;
const int mod = 998244353;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 400010, maxT = 200000, A = 179, K = 450;
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
ll ans(0);
int f[maxN], sz[maxN], cnt[maxN];
vector<ll>ps;
int find(int v) { return (f[v] == v ? v : f[v] = find(f[v])); }
bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)return false;
    f[b] = a;
    ans -= ps[a + sz[a]] - ps[a + sz[a] - cnt[a]];
    ans -= ps[b + sz[b]] - ps[b + sz[b] - cnt[b]];
    cnt[a] += cnt[b];
    sz[a] += sz[b];
    ans += ps[a + sz[a]] - ps[a + sz[a] - cnt[a]];
    return true;
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<ll, ll>>qw(q), a(n + m);
    ps.assign(n + m + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = 1;
        ans += a[i].first;
    }
    for (int i = n; i < n + m; ++i) {
        cin >> a[i].first;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n + m; ++i) {
        ps[i + 1] = ps[i] + a[i].first;
    }
    for (int i = 0; i < q; ++i) {
        cin >> qw[i].first;
        qw[i].second = i;
    }
    sort(qw.begin(), qw.end());
    vector<ll>res(q);
    for (int i = 0; i < n + m; ++i) {
        f[i] = i;
        sz[i] = 1;
        cnt[i] = a[i].second;
    }
    set<pair<int, int>>to_uni;
    for (int i = 0; i < n + m - 1; ++i)to_uni.insert({ a[i + 1].first -
        a[i].first,i });
    for (auto x : qw) {
        ll k;
        int idx;
        tie(k, idx) = x;
        while (!to_uni.empty() && k >= (*to_uni.begin()).first) {
            int bb = (*to_uni.begin()).second;
            to_uni.erase(to_uni.begin());
            int _to = bb + sz[bb];
            if (_to + sz[_to] < n + m) {
                to_uni.erase({ a[_to + sz[_to]].first - a[_to + sz[_to] - 1].first,_to });
            }
            uni(bb, _to);
            if (bb + sz[bb] < n + m) {
                to_uni.insert({ a[bb + sz[bb]].first - a[bb + sz[bb] - 1].first,bb });
            }
        }
        res[idx] = ans;
    }
    for (auto x : res)cout << x << "\n";
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