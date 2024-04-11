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
const ll maxN = 1 << 20, maxT = 310, A = 179, K = 450;
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
int p[maxN];
void build() {
    for (int j = 2; j < maxN; ++j) {
        if (p[j])
            continue;
        p[j] = 1;
        for (int k = 2 * j; k < maxN; k += j)
            p[k] = 2;
    }
}
void solve() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>>a(e);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        a[i % e].push_back(p[v]);
    }
    ll ans = 0;
    for (const auto &vec : a) {
        int sz = vec.size();
        vector<int>ps(sz + 1);
        for (int j = 0; j < sz; ++j) {
            ps[j + 1] = ps[j] + vec[j];
        }
        for (int j = 0; j < sz; ++j) {
            if (ps.back() == ps[j])
                continue;
            int r = lower_bound(ps.begin(), ps.end(), ps[j] + 2) - ps.begin();
            int l = lower_bound(ps.begin(), ps.end(), ps[j] + 1) - ps.begin();
            l = max(l, j + 2);
            ans += max(r - l, 0);
        }
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
    build();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}