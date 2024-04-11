
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

struct Fenv {
    static const int n = 3e5 + 10;
    int fenv[n];
    void add(int r, int x) {
        for (; r < n; r |= r + 1)
            fenv[r] += x;
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & r + 1) - 1)
            ans += fenv[r];
        return ans;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} fenv;

pii shrink(pii a) {
    int g = __gcd(abs(a.f), abs(a.s));
    a.f /= g;
    a.s /= g;
    return a;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<vector<pii>> a(n);
    vector<pii> occ;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        a[i] = vector<pii>(s);
        cin >> a[i];
        vector<pii> b(s);
        for (int j = 0; j < s; ++j) {
            pii from = a[i][j], to = a[i][(j + 1) % s];
            b[j] = shrink({to.f - from.f, to.s - from.s});
        }
        for (auto i : b) occ.pb(i);
        a[i] = b;
    }
    sort(occ);
    occ.resize(unique(all(occ)) - occ.begin());
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(a[i]); ++j) 
            b.pb(lower_bound(all(occ), a[i][j]) - occ.begin());
    }
    vector<int> pref(n);
    for (int i = 0; i < n; ++i) pref[i] = sz(a[i]);
    for (int i = 1; i < n; ++i) pref[i] += pref[i - 1];
    int q;
    cin >> q;
    vector<pair<pii, int>> query(q);
    int cnt = 0;
    for (auto &i : query) {
        cin >> i.f;
        --i.f.f, --i.f.s;
        int left = i.f.f > 0 ? pref[i.f.f - 1] : 0;
        int right = pref[i.f.s] - 1;
        i.f = {left, right};
        i.s = cnt++;
    }
    sort(query);
    vector<vector<int>> pos(sz(occ));
    for (int i = 0; i < sz(b); ++i) pos[b[i]].pb(i);
    for (int i = 0; i < sz(pos); ++i) fenv.add(pos[i][0], 1);
    vector<int> ptr(sz(occ));
    vector<int> ans(q);
    int l = 0;
    for (auto i : query) {
        while (l < i.f.f) {
            if (++ptr[b[l]] < sz(pos[b[l]])) fenv.add(pos[b[l]][ptr[b[l]]], 1);
            ++l;
        }
        ans[i.s] = fenv.get(i.f.f, i.f.s);
    }
    for (auto i : ans) cout << i << '\n';
    return 0;
}