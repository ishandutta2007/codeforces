#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
 
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
#define FIXED cout << fixed << setprecision(6)
#define RANDOM srand(94385)
#define ll long long
#define ld double
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

void solve(ld &x, ld a, ld b, ld c) {
    ld D = b * b - 4 * a * c;
    checkmax(D, 0);
    D = sqrtf(D);
    ld x1 = (-b - D) / (2 * a);
    ld x2 = (-b + D) / (2 * a);
    x = x1 < 0 ? x2 : x1;
    checkmax(x, 0);
    checkmin(x, 1);
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<ld> mx(n), mn(n);
    cin >> mx >> mn;
    vector<ld> sum(n);
    for (int i = 0; i < n; ++i) sum[i] = mn[i] + mx[i];
    auto pref = mx;
    for (int i = 1; i < n; ++i) pref[i] += pref[i - 1];
    ld A = 0, B = 0;
    vector<ld> a(n), b(n); 
    for (int i = 0; i < n; ++i) {
        solve(b[i], -1, sum[i] + A - B, B * (sum[i] + A) - pref[i]);
        a[i] = sum[i] - b[i];
        A += a[i];
        B += b[i];
    }
    for (auto i : a) cout << i << ' ';
    cout << '\n';
    for (auto i : b) cout << i << ' ';
    return 0;
}