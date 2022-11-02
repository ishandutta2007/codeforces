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

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

int n;

bool check(vector<pii> a, vector<pii> b) {
    vector<int> byr(n), byl(n);
    for (int i = 0; i < n; ++i) byr[i] = byl[i] = i;
    sort(all(byr), [&](int i, int j) {
        return a[i].s < a[j].s;
    });
    sort(all(byl), [&](int i, int j) {
        return a[i].f < a[j].f;
    });
    multiset<int> left, right;
    set<pii> r;
    for (auto i : byl) {
        left.insert(b[i].f);
        right.insert(b[i].s);
        r.insert({a[i].s, i});
        while (sz(r) && r.begin()->f < a[i].f) {
            int ind = r.begin()->s;
            left.erase(left.find(b[ind].f));
            right.erase(right.find(b[ind].s));
            r.erase(r.begin());
        }
        if (*(--left.end()) > *right.begin()) {
            cout << "NO";
            exit(0);
        }
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n;
    vector<pii> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    check(a, b);
    check(b, a);
    cout << "YES";
    return 0;
}