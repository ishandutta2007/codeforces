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
#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
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
const ll INF = 1e18;
const int mod = 1000000007;
const ld eps = 1e-9, pi = acosl(-1);
const ll maxN = 5100, maxT = 110, A = 179, mid = 150;
ll bp(ll et, ll b) {
    ll res = 1;
    for (int i = 30; i >= 0; --i) {
        res = (res * res) % mod;
        if ((b & (1 << i)) != 0)res = (res * et) % mod;
    }
    return res;
}
void panic() {
    cout << "Impossible.\n";
    exit(0);
}
const int bsz = 9;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>a(m);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        a[--v] ^= 1;
    }
    vector<int>p(m + 1);
    for (int i = 0; i < m; ++i) {
        p[i + 1] = p[i] + a[i];
    }
    vector<vector<vector<char>>>vi(bsz);
    for (int b = 0; b < bsz; ++b) {
        int ln = 1 << (b + 1);
        vi[b].resize(ln);
        for (int st = 0; st < ln; ++st) {
            vi[b][st].push_back(0);
            for (int i = 0; i < m; ++i) {
                int tmp = (i - st + ln) % ln;
                if (tmp >= ln / 2 && a[i]) {
                    vi[b][st].push_back(1 ^ vi[b][st].back());
                }
                else {
                    vi[b][st].push_back(vi[b][st].back());
                }
            }
        }
    }
 
    int q;
    cin >> q;
    string s;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        bool f = 0;
        for (int b = 0; b < 19; ++b) {
            ll res = 0;
            if (b < bsz) {
                int ln = 1 << (b + 1);
                int st = l % ln;
                res = vi[b][st][r] ^ vi[b][st][l];
            }
            else {
                int ln = (1 << b);
                for (int i = l; i + ln <= r; i += 2 * ln) {
                    res += (p[min(i + 2 * ln, r)] - p[i + ln]);
                }
            }
            f |= res % 2 != 0;
        }
        if (f)s.push_back('A');
        else s.push_back('B');
    }
    cout << s;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(2);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
    //freopen("dishes.in", "r", stdin); freopen("dishes.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}