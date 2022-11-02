#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <deque>
#include <queue>
#include <random>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(15);
#define RANDOM srand(3654765)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>> 
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define eps 1e-9
#define mod 991929347
#define inf 3000000000000000007ll
#define hashmap unordered_map
#define hashset unordered_set
#define f first
#define s second
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < n; ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }

vector<int> z_func(string s) {
    int n = sz(s);
    vector<int> z(sz(s));
    z[0] = 0;
    int r = 0, past = 0;
    for (int i = 1; i < sz(s); ++i) {
        checkmax(r, i);
        z[i] = min(r - i, z[i - past]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
        if (ifmax(r, i + z[i])) past = i;
    }
    return z;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<vector<int>> z(n);
    for (int i = 0; i < n; ++i) z[i] = z_func(s.substr(i, n - i));
    vector<int> dp(n, mod);
    dp[0] = a;
    for (int i = 1; i < n; ++i) {
        checkmin(dp[i], dp[i - 1] + a);
        for (int j = i - 1; j >= 0; --j)
            if (s[j] == s[i]) checkmin(dp[i + min(i - j, z[j][i - j]) - 1], dp[i - 1] + b);
    }
    //for (auto i : dp) cout << i << ' ';
    cout << dp.back();
    return 0;
}