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
const int mod = 998244353;
const ld eps = 1e-6, pi = acosl(-1);
const ll maxN = 5010, maxT = 5, A = 179, mid = 150;
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
vector<ll>pw;
ll get(string s) {
    ll ans = 0;
    int n = s.length();
    vector<vector<ll>>dp(3, vector<ll>(n + 1));
    dp[0][0] = 1;
    int c1 = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '*') {
            dp[0][i] = (dp[1][i - 1] + dp[0][i - 1] + dp[2][i - 1]) % mod;
        }
        else {
            ++c1;
            dp[0][i] = (dp[1][i - 1] + dp[0][i - 1] + dp[2][i - 1]) % mod;
            dp[2][i] = (dp[1][i - 1]);
            dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % mod;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] != '*') {
            --c1;
            ans = (ans + dp[2][i] * pw[c1]) % mod;
        }
    }


    return ans;
}
void solve() {
    int n, m;
    cin >> n >> m;
    pw.assign(n * m + 1, 1);
    for (int i = 1; i <= n * m; ++i)pw[i] = (pw[i - 1] * 2) % mod;
    vector<vector<char>>a(n, vector<char>(m));
    int cnt = n * m;
    for (auto& vec : a)
        for (auto& x : vec) {
            cin >> x;
            if (x == '*')--cnt;
        }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        int c1 = 0;
        for (int j = 0; j < m; ++j) {
            s.push_back(a[i][j]);
            if (s.back() != '*')++c1;
        }
        ans = (ans + pw[cnt - c1] * get(s)) % mod;
    }
    for (int j = 0; j < m; ++j) {
        string s;
        int c1 = 0;
        for (int i = 0; i < n; ++i) {
            s.push_back(a[i][j]);
            if (s.back() != '*')++c1;
        }
        ans = (ans + pw[cnt - c1] * get(s)) % mod;
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(1);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
    //freopen("dishes.in", "r", stdin); freopen("dishes.out", "w", stdout);
#endif
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}