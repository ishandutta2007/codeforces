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

bool check1(ll x, ll y) {
    int l1 = abs(x);
    int r1 = abs(y);
    int l2 = abs(x - y);
    int r2 = abs(x + y);
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);
    return l2 <= l1 && r2 >= r1;
}

bool check(ll x, ll y) {
    return check1(x, y) || check1(y, x);
}

struct Fenv {
    static const int n = 1e9 + 10;
    hashmap<int, int> fenv;
    void add(int r) {
        for (; r < n; r |= r + 1) fenv[r]++;
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            if (fenv.count(r)) ans += fenv[r];
        return ans;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} fenv;

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    for (auto &i : a) i = abs(i);
    sort(a);
    int ptr = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        while (a[ptr] * 2 < a[i]) ++ptr;
        ans += (i - ptr);
    }
    cout << ans;
    return 0;
}