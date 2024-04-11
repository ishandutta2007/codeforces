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
const ll maxN = 1 << 19, maxT = 119, A = 179, K = 450;
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
int t[32][maxN];
int sz = 1;
void sett(int p, char c) {
    p += sz;
    for (int i = 0; i < 32; ++i) {
        if (i != 1 && i != 2 && i != 4)t[i][p] = INF;
        else t[i][p] = 1;
    }
    c -= 'a';
    t[1 << c][p] = 0;
}
void mrg(int v) {
    for (int i = 0; i < 32; ++i) {
        t[i][v] = INF;
    }
    int l = 2 * v, r = 2 * v + 1;
    for (int lm = 0; lm < 32; ++lm) {
        if (t[lm][l] == INF)continue;
        for (int rm = 0; rm < 32; ++rm) {
            if (t[rm][r] == INF)continue;
            if (lm % 2 == 1 && (rm & 16) != 0)
                continue;
            if ((lm & 8) != 0 && (rm & 4) != 0)
                continue;
            int msk = lm | rm;
            if ((lm & 1) && (rm & 2))msk |= 8;
            if ((lm & 2) && (rm & 4))msk |= 16;
            t[msk][v] =
                min(t[msk][v], t[lm][l] + t[rm][r]);
        }
    }
}
void solve() {
    int n, q;
    cin >> n >> q;
    while (sz < n)sz <<= 1;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        sett(i, s[i]);
    } 
    for (int i = sz - 1; i > 0; --i) {
        mrg(i);
    }
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        sett(--p, c);
        for (p = (p + sz) / 2; p; p >>= 1)mrg(p);
        int ans = t[0][1];
        for (int i = 0; i < 32; ++i)ans = min(ans, t[i][1]);
        cout << ans << "\n";
    }
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