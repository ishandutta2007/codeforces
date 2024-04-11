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

vector<pii> segm;

void solve(string s) {
    int n = sz(s);
    vector<int> next(n), prev(n);
    int p = -1;
    for (int i = 0; i < n; ++i) {
        prev[i] = p;
        if (s[i] == '1') p = i;
    }
    p = n;
    for (int i = n - 1; i >= 0; --i) {
        next[i] = p;
        if (s[i] == '1') p = i;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            int l = prev[i], r = next[i];
            while (l >= 0 && r < n) {
                if (i - l == r - i) {
                    segm.pb({l, r});
                    break;
                }
                if (i - l < r - i) {
                    if (i - (r - i) + 1 >= 0) l = prev[i - (r - i) + 1];
                    else break;
                } else {
                    if (i + (i - l) - 1 < n) r = next[i + (i - l) - 1];
                    else break;
                }
            }
        }
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    string s;
    cin >> s;
    solve(s);
    for (auto &i : s) i = char(((i - '0') ^ 1) + '0');
    solve(s);
    rsort(segm);    
    int r = sz(s);
    int ptr = 0;
    ll ans = 0;
    for (int l = sz(s) - 1; l >= 0; --l) {
        while (ptr < sz(segm) && segm[ptr].f >= l) checkmin(r, segm[ptr++].s);
        ans += sz(s) - r;
    }
    cout << ans;
    return 0;
}