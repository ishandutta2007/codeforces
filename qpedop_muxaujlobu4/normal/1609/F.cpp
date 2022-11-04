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
int count(const ll& v) {
    int cnt(0);
    for (int i = 0; i < 60; ++i)
        if ((v & (1LL << i)) != 0)++cnt;
    return cnt;
}
const int cnt_b(60);
ll a[maxN];
int cnt[maxN], cntt[maxN];
ll mx[maxN];
ll mn[maxN];
ll ans(0);
void rec(int l, int r) {
    if (l + 1 == r) {
        ++ans;
        return;
    }
    int m = (l + r) / 2;
    rec(l, m);
    rec(m, r);
    mx[m] = mn[m] = a[m];
    mx[m - 1] = mn[m - 1] = a[m - 1];
    cntt[m] = cnt[m];
    cntt[m - 1] = cnt[m - 1];
    for (int i = m + 1; i < r; ++i) {
        mx[i] = max(mx[i - 1], a[i]), mn[i] = min(mn[i - 1], a[i]);
        cntt[i] = (mn[i] == a[i] ? cnt[i] : cntt[i - 1]);
    }
    for (int i = m - 2; i >= l; --i) {
        mx[i] = max(mx[i + 1], a[i]), mn[i] = min(mn[i + 1], a[i]);
        cntt[i] = (mn[i] == a[i] ? cnt[i] : cntt[i + 1]);
    }
    vector<int>mn_y(cnt_b), mn_y1(cnt_b);
    for (int i = r - 1; i >= m; --i) {
        ++mn_y[cntt[i]];
    }
    int need = 0;
    int y = m;
    int y1 = m;
    mn_y1 = mn_y;
    for (int i = m - 1; i >= l; --i) {
        if (m - 1 == i || mx[i] != mx[i + 1])need = cnt[i];
        while (y < r && mn[i] < mn[y]) {
            --mn_y[cntt[y++]];
        }
        while (y1 < r && mx[i] > mx[y1]) {
            --mn_y1[cntt[y1++]];
        }
        if (y <= y1) {
            ans += mn_y[need] - mn_y1[need];
        }
        if (cntt[i] == need) {
            ans += min(y1, y) - m;
        }
    }
    for (int i = 0; i < cnt_b; ++i)mn_y[i] = 0;
    for (int i = l; i < m; ++i) {
        ++mn_y[cntt[i]];
    }
    mn_y1 = mn_y;
    need = 0;
    y = m, y1 = m;
    for (int i = m; i < r; ++i) {
        if (m == i || mx[i] != mx[i - 1])need = cnt[i];
        while (y > l && mn[i] <= mn[y - 1]) {
            --mn_y[cntt[--y]];
        }
        while (y1 > l && mx[i] >= mx[y1 - 1]) {
            --mn_y1[cntt[--y1]];
        }
        if (y >= y1) {
            ans += mn_y[need] - mn_y1[need];
        }
        if (cntt[i] == need) {
            ans += m - max(y, y1);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[i] = count(a[i]);
    }
    rec(0, n);
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
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}