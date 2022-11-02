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
#define eps 1e-13
#define mod 1000000007
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

int conv(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    return c - '0';
}

string conv(int x) {
    string ans = "";
    for (int i = 0; i < 4; ++i) ans += x & 1, x >>= 1;
    reverse(ans);
    return ans;
}

vector<vector<int>> pref;

int get(int y, int x) {
    if (x < 0 || y < 0) return 0;
    return pref[y][x];
}

int get(int y1, int x1, int y2, int x2) {
    --y1, --x1;
    return get(y2, x2) - get(y1, x2) - get(y2, x1) + get(y1, x1);
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n / 4; ++j) {
            char c;
            cin >> c;
            arr[i] += conv(conv(c));
        }
    pref = vector<vector<int>> (n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            pref[i][j] = get(i - 1, j) + get(i, j - 1) - get(i - 1, j - 1) + arr[i][j];
    ll ans = 1;
    for (ll x = 2; x <= n; ++x)
        if (n % x == 0) {
            bool flag = true;
            for (int i = 0; i < n; i += x)
                for (int j = 0; j < n; j += x) {
                    int s = get(i, j, i + x - 1, j + x - 1);
                    if (!(s == 0 || s == x * x)) flag = false; 
                }
            if (flag) ans = x;
        }
    cout << ans;
    return 0;
}