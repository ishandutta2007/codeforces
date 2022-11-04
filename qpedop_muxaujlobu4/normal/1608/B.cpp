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
const int mod = 1000000007;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 30010, maxT = 310, A = 179, K = 450;
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
    ll n, a, b;
    cin >> n >> a >> b;
    if (a + b > n - 2 || abs(a - b) > 1) {
        cout << "-1\n";
        return;
    }
    vector<int>v(n);
    int l = 1, r = 1;
    v[0] = 1;
    bool now_mx = true;
    if (b > a)now_mx = false;
    for (int i = 1; i < n; ++i) {
        bool cng = a + b != 0;
        if (now_mx) {
            v[i] = ++r;
            if (a)
                --a;
        }
        else {
            v[i] = --l;
            if (b)--b;
        }
        now_mx ^= cng;
       /* if (a + b == 0) {
            if (i == 1 || v[i - 1] > v[i - 2])v[i] = ++r;
            else v[i] = --l;
        }
        else {
            if (now_mx) {
                v[i] = ++r;
                --a;
            }
            else v[i] = --l, --b;
            now_mx ^= true;
        }*/
    }
    for (auto& x : v) {
        if (l != 1) {
            x += -l + 1;
        }
    }

    for (auto x : v)cout << x << " ";
    cout << "\n";
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