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
const ll INF = 1e21 + 100;
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
void solve() {
    ll l, r;
    cin >> l >> r;
    ll msk = 0;
    ll ans = INF;
    int y = 20;
    while ((r & (1 << y)) == 0)--y;
    if ((l & (1 << y)) != 0) {
        cout << "0\n";
        return;
    }
    for (int i = y; i >= 0; --i) {
        ll r1 = r;
        ll l1 = l;
        ll cnt = 0;
        ll b = 1 << i;
        msk |= b;
        for (int j = i - 1; j >= 0; --j) {
            if ((r & b) != 0 && (r & (1 << j)) != 0) {
                cnt += 1 << j;
            }
            if ((r & (1 << j)) != 0) {
                r1 -= 1 << j;

            }
            if ((l & b) != 0 && (l & (1 << j)) == 0) {
                cnt += 1 << j;
            }
            if ((l & (1 << j)) == 0) {
                l1 += 1 << j;
            }
        }
        if ((b & r1))++cnt;
        --r1;
        if (b & l1)++cnt;
        ++l1;
        ll cc = r1 - l1 + 1;
        ll add = 0;
        if ((r1 & b) != 0 && (l1 & b) != 0)++add;
        cnt += (cc / b / 2 + add) * b;

        ans = min(ans, r - l + 1 - cnt);
    }
    cout << ans << "\n";
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