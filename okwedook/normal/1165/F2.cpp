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
#define mod 1000000007
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

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    cin >> k;
    vector<pii> sale(m);
    for (int i = 0; i < m; ++i) 
        cin >> sale[i].f >> sale[i].s;
    int l = 0, r = 4e5 + 10;
    while (r - l > 1) {
        int d = r + l >> 1;
        vector<int> mx(n, -1);
        for (auto i : sale)
            if (i.f <= d)
                checkmax(mx[i.s - 1], i.f);
        vector<pii> sale;
        for (int i = 0; i < n; ++i)
            if (mx[i] > 0) sale.pb({mx[i], i});
        sort(sale);
        vector<int> kcopy = k;
        int curr = 0, ptr = 0, ans = 0;
        for (int i = 1; i <= d; ++i) {
            ++curr;
            while (ptr < sz(sale) && sale[ptr].f < i) ++ptr;
            while (ptr < sz(sale) && sale[ptr].f == i) {
                int d = min(curr, kcopy[sale[ptr].s]);
                ans += d;
                curr -= d;
                kcopy[sale[ptr].s] -= d;
                ++ptr;
            }
        }
        for (auto i : kcopy) ans += 2 * i;
        if (ans > d) l = d;
        else r = d;
    }
    cout << r;
    return 0;
}