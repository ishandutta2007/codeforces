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
#include <complex>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
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

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

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

void makepref(vector<int> &p) {
    for (int i = 1; i < sz(p); ++i)
        p[i] += p[i - 1];
}

void makediff(vector<int> &p) {
    for (int i = sz(p) - 1; i > 0; --i)
        p[i] -= p[i - 1];
}

int get(vector<int> &p, int l, int r) {
    return l == 0 ? p[r] : p[r] - p[l - 1];
}

signed main() {
    FAST; FIXED;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sum(30, vector<int>(n + 1));
    vector<pair<pii, int>> d;
    d.reserve(m);
    for (int i = 0; i < m; ++i) {
        int l, r, q;
        cin >> l >> r >> q;
        --l;
        for (int j = 0; j < 30; ++j)
            if (q >> j & 1) {
                ++sum[j][l];
                --sum[j][r];
            }
        d.pb({{l, r}, q});
    }
    for (auto &i : sum) {
        makepref(i);
        for (auto &j : i)
            j = !!j;
        makepref(i);
    }
    for (auto i : d) {
        int l = i.f.f, r = i.f.s, q = i.s;
        for (int j = 0; j < 30; ++j) 
            if ((q >> j & 1) == 0 && get(sum[j], l, r - 1) == r - l) {
                cout << "NO";
                return 0;
            }
    }
    cout << "YES\n";
    for (auto &i : sum) makediff(i);
    for (int i = 0; i < n; ++i) {
        int v = 0;
        for (int j = 0; j < 30; ++j)
            v |= (1 << j) * sum[j][i];
        cout << v << ' ';
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}