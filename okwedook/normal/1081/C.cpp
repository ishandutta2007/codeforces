#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define inf 4000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

const int mod = 998244353;

struct modular {
    int val;
    modular(ll x = 0) { val = x % mod; if (val < 0) val += mod; }
    modular(ll a, ll b) { *this += a; *this /= b; }

    modular& operator+=(modular const &b) { val += b.val; if (val >= mod) val -= mod; return *this; }
    modular& operator-=(modular const &b) { val -= b.val; if (val < 0) val += mod; return *this; }
    modular& operator*=(modular const &b) { val = (val * (ll)b.val) % mod; return *this; }

    friend modular mypow(modular a, ll n) {
        modular res = 1;
        while (n) { if (n & 1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend modular inv(modular a) { return mypow(a, mod - 2); }
    modular& operator/=(modular const& b) { return *this *= inv(b); }
    friend modular operator+(modular a, const modular &b) { return a += b; }
    friend modular operator-(modular a, const modular &b) { return a -= b; }
    friend modular operator-(modular a) { return 0 - a; }
    friend modular operator*(modular a, const modular &b) { return a *= b; }
    friend modular operator/(modular a, const modular &b) { return a /= b; }
    friend ostream& operator<<(ostream& stream, const modular &a) { return stream << a.val; }
    friend bool operator==(modular const &a, modular const &b) { return a.val == b.val; }
    friend bool operator!=(modular const &a, modular const &b) { return a.val == b.val; }
};

signed main() {
    FAST; FIXED; RANDOM;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<modular>> dp(n + 1, vector<modular>(k + 1));
    dp[1][0] = m;
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= k; ++j) {
            if (j < k) dp[i][j + 1] += dp[i - 1][j] * (m - 1);
            dp[i][j] += dp[i - 1][j];
        }
    cout << dp[n][k];
    return 0;
}