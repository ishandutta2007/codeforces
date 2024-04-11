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
ll ans = 0;
mt19937_64 gen;
ll n;

void solve(vector<ll> a) {
    vector<ll> h(n + 1);
    for (int i = 0; i <= n; ++i)
        h[i] = gen();
    vector<ll> pref(n);
    for (int i = 0; i < n; ++i) pref[i] = h[a[i]];
    for (int i = 1; i < n; ++i) pref[i] ^= pref[i - 1];
    for (int i = 2; i <= n; ++i) h[i] ^= h[i - 1];
    for (int i = 0; i < n; ++i)
        if (a[i] == 1) {
            int mx = 1;
            for (int j = i + 1; j < n && a[j] > 1; ++j) {
                checkmax(mx, a[j]);
                int left = j - mx + 1;
                int right = j;
                //cout << left << ' ' << right << '\n';
                ll check = pref[right];
                if (left > 0) check ^= pref[left - 1];
                ans += check == h[mx];
            }
        }
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    for (auto i : a) ans += i == 1;
    solve(a);
    reverse(a);
    solve(a);
    cout << ans;
    return 0;
}