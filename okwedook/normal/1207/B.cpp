#define _CRT_SECURE_NO_WARNINGS
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
 
template<class T, class U> inline void checkmin(T & x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T& x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T& x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T& x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T& a) { sort(all(a)); }
template<class T> inline void rsort(T& a) { sort(rall(a)); }
template<class T> inline void reverse(T& a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U>& p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T>& a) { for (auto& i : a) str >> i; return str; }
 
bool f(graph& a, graph& b,int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (a[i][j] != b[i][j]) return false;
    }
    return true;
}
 
int min(int a, int b) {
    if (a > b) return b;
    else return a;
}
 
signed main() {
    FAST; FIXED; RANDOM;
    ll m, n, o = 0;
    graph a, b;
    cin >> n >> m;
    a.assign(n, vector<int>(m));
    b.assign(n, vector<int>(m));
    vector<int> c(1);
    vector<int> k(1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (a[i][j] == 1 && a[min(i + 1, n - 1)][j] == 1 && a[i][min(j + 1, m - 1)] == 1 && a[min(i + 1, n - 1)][min(j + 1, m - 1)] == 1) {
                o++;
                c[o - 1] = i;
                k[o - 1] = j;
                c.push_back(o);
                k.push_back(o);
                b[i][j] = 1, b[min(i + 1, n - 1)][j] = 1, b[i][min(j + 1, m - 1)] = 1, b[min(i + 1, n - 1)][min(j + 1, m - 1)] = 1;
            }
        }
    }
    if (f(a, b, n, m)) {
        cout << o << endl;
        for (int i = 0; i < o; ++i) cout << c[i] + 1 << " " << k[i] + 1 << endl;
    }
    else cout << -1;
    return 0;
}