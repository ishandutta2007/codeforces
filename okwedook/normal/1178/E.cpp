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
 
signed main() {
    FAST; FIXED; RANDOM;
    string s;
    cin >> s;
    vector<int> a, b, c;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == 'a') a.pb(i);
        if (s[i] == 'b') b.pb(i);
        if (s[i] == 'c') c.pb(i);
    }
    int last = sz(s);
    int need = sz(s) / 2, got = 0;
    string l = "", r = "";
    for (int i = 0; i < sz(s) / 2 && i < last; ++i) {
        if (s[i] == 'a') {
            while (sz(a) && a.back() >= last) a.popb();
            if (sz(a) && a.back() > i && got + 2 + (a.back() - i - 1) / 2 >= need) {
                l += s[i];
                r += s[a.back()];
                last = a.back();
                got += 2;
            }
        }
        if (s[i] == 'b') {
            while (sz(b)  && b.back() >= last) b.popb();
            if (sz(b) && b.back() > i  && got + 2 + (b.back() - i - 1) / 2 >= need) {
                l += s[i];
                r += s[b.back()];
                last = b.back();
                got += 2;
            }
        }
        if (s[i] == 'c') {
            while (sz(c) && c.back() >= last) c.popb();
            if (sz(c) && c.back() > i  && got + 2 + (c.back() - i - 1) / 2 >= need) {
                l += s[i];
                r += s[c.back()];
                last = c.back();
                got += 2;
            }
        }
    }
    reverse(r);
    if (sz(l) + sz(r) < need) l += s[last - 1];
    l += r;
    cout << l;
    return 0;
}