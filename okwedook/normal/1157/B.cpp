#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <bitset>
#include <random>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(38242)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define f first
#define s second
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto &i : s) i -= '0';
    vector<int> a(10);
    for (int i = 1; i < 10; ++i) cin >> a[i];
    vector<int> c(10);
    for (int i = 0; i < 10; ++i) c[i] = i;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (a[s[i]] < s[i] && l >= 0) break;
        if (c[s[i]] == s[i] && a[s[i]] > s[i]) {
            if (l == -1) l = i;
            r = i;
            c[s[i]] = a[i];
        }
        if (c[s[i]] != s[i]) r = i;
    }
    if (l >= 0) 
        for (int i = l; i <= r; ++i) s[i] = a[s[i]];
    for (auto &i : s) i += '0';
    cout << s;
    return 0;
}