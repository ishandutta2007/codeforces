#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <random>
#include <cassert>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

const int N = 52;
const int T = 2502;

struct zet {
    int val;
    zet(ll x = 0) { val = x % mod; if (val < 0) val += mod; }
    zet(ll a, ll b) { *this += a; *this /= b; }

    zet& operator+=(zet const &b) { val += b.val; if (val >= mod) val -= mod; return *this; }
    zet& operator-=(zet const &b) { val -= b.val; if (val < 0) val += mod; return *this; }
    zet& operator*=(zet const &b) { val = (val * (ll)b.val) % mod; return *this; }

    friend zet mypow(zet a, ll n) {
        zet res = 1;
        while (n) { if (n & 1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend zet inv(zet a) { return mypow(a, mod - 2); }
    zet& operator/=(zet const& b) { return *this *= inv(b); }
    friend zet operator+(zet a, const zet &b) { return a += b; }
    friend zet operator-(zet a, const zet &b) { return a -= b; }
    friend zet operator-(zet a) { return 0 - a; }
    friend zet operator*(zet a, const zet &b) { return a *= b; }
    friend zet operator/(zet a, const zet &b) { return a /= b; }
    friend istream& operator>>(istream& stream, zet &a) { return stream >> a.val; }
    friend ostream& operator<<(ostream& stream, const zet &a) { return stream << a.val; }
    friend bool operator==(zet const &a, zet const &b) { return a.val == b.val; }
    friend bool operator!=(zet const &a, zet const &b) { return a.val != b.val; }
};

zet cnt[N][N][N][3];
zet dp[N][N][T];
zet d[N][T];

signed main() {
    FAST; FIXED; RANDOM;
    cnt[1][0][0][0] = 1;
    cnt[0][1][0][1] = 1;
    cnt[0][0][1][2] = 1;
    for (int sum = 2; sum < N; ++sum)
        for (int lastk = 0; lastk < sum; ++lastk)
        for (int lastb = 0; lastk + lastb < sum; ++lastb) {
            int lastc = sum - lastk - lastb - 1;
            for (int last = 0; last < 3; ++last)
                for (int now = 0; now < 3; ++now)
                    if (last != now) {
                        if (now == 0) {
                            cnt[lastk + 1][lastb][lastc][now] += cnt[lastk][lastb][lastc][last];
                        }
                        if (now == 1) {
                            cnt[lastk][lastb + 1][lastc][now] += cnt[lastk][lastb][lastc][last];
                        }
                        if (now == 2) {
                            cnt[lastk][lastb][lastc + 1][now] += cnt[lastk][lastb][lastc][last];
                        }
                    }
        }
    zet fact[N];
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                for (int l = 0; l < 3; ++l)
                    cnt[i][j][k][l] *= fact[i] * fact[j] * fact[k];
    int n, t;
    cin >> n >> t;
    vector<pii> a(n);
    cin >> a;
    vector<pii> br;
    vector<int> c;
    for (auto i : a)
        if (i.s < 3) br.pb(i);
        else c.pb(i.f);
    dp[0][0][0] = 1;
    d[0][0] = 1;
    for (auto i : br) {
        if (i.s == 1) {
            for (int k = N - 2; k >= 0; --k)
                for (int b = N - 2; b >= 0; --b)
                    for (int t = T - i.f - 1; t >= 0; --t)
                        dp[k + 1][b][t + i.f] += dp[k][b][t];
        } else {
            for (int k = N - 2; k >= 0; --k)
                for (int b = N - 2; b >= 0; --b)
                    for (int t = T - i.f - 1; t >= 0; --t)
                        dp[k][b + 1][t + i.f] += dp[k][b][t];
        }
    }
    for (auto i : c) {
        for (int c = N - 2; c >= 0; --c)
            for (int t = T - i - 1; t >= 0; --t)
                d[c + 1][t + i] += d[c][t];
    }
    zet ans = 0;
    for (int sumkb = 0; sumkb <= t; ++sumkb)
        for (int k = 0; k < N; ++k)
            for (int b = 0; k + b < N; ++b)
                    for (int c = 0; k + b + c < N; ++c)
                        ans += dp[k][b][sumkb] * d[c][t - sumkb] * (cnt[k][b][c][0] + cnt[k][b][c][1] + cnt[k][b][c][2]);
    cout << ans;
    return 0;
}