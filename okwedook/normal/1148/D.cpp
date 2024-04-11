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

vector<int> greedyup(vector<pair<pii, int>> a) {
    int last = 6e5;
    vector<int> ans;
    for (int i = 0; i < sz(a); ++i) {
        if (last > a[i].f.f) {
            ans.pb(a[i].s);
            last = a[i].f.s;
        }
    }
    return ans;
}

vector<int> greedydown(vector<pair<pii, int>> a) {
    int last = 0;
    vector<int> ans;
    for (int i = 0; i < sz(a); ++i) {
        if (last < a[i].f.f) {
            ans.pb(a[i].s);
            last = a[i].f.s;
        }
    }
    return ans;
}

bool operator>(const vector<int> &a, const vector<int> &b) {
    return sz(a) > sz(b);
}

bool operator<(const vector<int> &a, const vector<int> &b) {
    return sz(a) < sz(b);
}

bool cmp1(const pair<pii, int> &a, const pair<pii, int> &b) {
    return a.f.s > b.f.s;
}

bool cmp2(const pair<pii, int> &a, const pair<pii, int> &b) {
    return a.f.s < b.f.s;
}

bool cmp3(const pair<pii, int> &a, const pair<pii, int> &b) {
    return a.f.f < b.f.f;
}

bool cmp4(const pair<pii, int> &a, const pair<pii, int> &b) {
    return a.f.f > b.f.f;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<pair<pii, int>> a, b;
    for (int i = 0; i < n; ++i) {
        int c, d;
        cin >> c >> d;
        if (c < d) a.pb({{c, d}, i});
        else b.pb({{c, d}, i});
    }
    vector<int> ans;
    sort(all(a), cmp1);
    sort(all(b), cmp1);
    checkmax(ans, greedyup(a));
    checkmax(ans, greedydown(b));
    sort(all(a), cmp2);
    sort(all(b), cmp2);
    checkmax(ans, greedyup(a));
    checkmax(ans, greedydown(b));
    sort(all(a), cmp3);
    sort(all(b), cmp3);
    checkmax(ans, greedyup(a));
    checkmax(ans, greedydown(b));
    sort(all(a), cmp4);
    sort(all(b), cmp4);
    checkmax(ans, greedyup(a));
    checkmax(ans, greedydown(b));
    cout << sz(ans) << '\n';
    for (auto i : ans) cout << i + 1 << ' ';
    return 0;
}