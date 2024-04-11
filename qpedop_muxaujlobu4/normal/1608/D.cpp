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
const ll maxN = 200010, maxT = 310, A = 179, K = 450;
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
ll f[maxN], g[maxN];
void build() {
    f[0] = g[0] = 1;
    for (int i = 1; i < maxN; ++i) {
        f[i] = f[i - 1] * i % mod;
        g[i] = bp(f[i], mod - 2);
    }
}
ll c(int n, int k) {
    return f[n] * g[k] % mod * g[n - k] % mod;
}
void solve() {
    build();
    int n;
    cin >> n;
    int l_min(0), l_max(0), r_min(0), r_max(0);
    vector<string>ss(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ss[i] = s;
        if (s[0] == 'W')++l_min, ++l_max;
        else if (s[0] == '?')++l_max;
        if (s[1] == 'B')++r_min, ++r_max;
        else if (s[1] == '?')++r_max;
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (l_min <= i && i <= l_max &&
            r_min <= i && i <= r_max) {
            ans += c(l_max - l_min, i - l_min) * c(r_max - r_min, i - r_min);
            ans %= mod;
        }
    }
    if (n != 1) {
        ll mn = 1;
        ll bw = 1, wb = 1;
        for (auto x : ss) {
            if (x == "WW" || x == "BB") {
                mn = 0;
                wb = 0;
                bw = 0;
            }
            else {
                if (x == "??") {
                    mn *= 2;
                    mn %= mod;
                }
                else {
                    if (x[0] == 'W' || x[1] == 'B')wb = 0;
                    else {
                        if (x[0] == 'B' || x[1] == 'W')bw = 0;
                    }
                }
            }
        }
        ans = ans + mod + bw + wb - mn;
        ans %= mod;
        ans += mod;
        ans %= mod;
    }
    cout << ans % mod << "\n";
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