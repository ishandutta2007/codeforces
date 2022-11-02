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
#include <complex>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
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
#define mod 12600
#define inf 3000000000000000007ll
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

void makepref(vector<int> &a) {
    for (int i = 1; i < sz(a); ++i) a[i] += a[i - 1];
}

int get(vector<int> &a, int r) {
    if (r < 0) return 0;
    return a[r];
}

int get(vector<int> &a, int l, int r) {
    if (r < l) return 0;
    return get(a, r) - get(a, l - 1);
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    cin >> a;
    vector<int> top(n, -1), down(n, n), left(n, -1), right(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n && a[i][j] == 'W'; ++j) 
            left[i] = j;
        for (int j = n - 1; j >= 0 && a[i][j] == 'W'; --j)
            right[i] = j;
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n && a[i][j] == 'W'; ++i)
            top[j] = i;
        for (int i = n - 1; i >= 0 && a[i][j] == 'W'; --i)
            down[j] = i;
    }
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        x[i] = down[i] == 0;
        y[i] = right[i] == 0;
    }
    makepref(x);
    makepref(y);
    vector<vector<int>> hor(n - k + 1, vector<int> (n)), vert(n - k + 1, vector<int>(n));
    for (int i = 0; i + k <= n; ++i) {
        int from = i;
        int to = i + k - 1;
        for (int j = 0; j < n; ++j) 
            hor[i][j] = top[j] + 1 >= from && down[j] - 1 <= to;
        makepref(hor[i]);
    }
    for (int j = 0; j + k <= n; ++j) {
        int from = j;
        int to = j + k - 1;
        for (int i = 0; i < n; ++i)
            vert[j][i] = left[i] + 1 >= from && right[i] - 1 <= to;
        makepref(vert[j]);
    }
    int ans = 0;
    for (int i = 0; i + k <= n; ++i)
        for (int j = 0; j + k <= n; ++j) {
            checkmax(ans, get(x, 0, j - 1) + get(x, j + k, n - 1) + 
                            get(y, 0, i - 1) + get(y, i + k, n - 1) +
                            get(hor[i], j, j + k - 1) + 
                            get(vert[j], i, i + k - 1));
        }
    cout << ans;
    return 0;
}