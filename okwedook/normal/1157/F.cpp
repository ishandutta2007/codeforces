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
    vector<int> a(n);
    cin >> a;
    sort(a);
    map<int, int> cnt;
    for (auto i : a) cnt[i]++;
    int l = 0, mn = 0;
    int ans = -1;
    pii answer = {0, -1};
    for (int i = 0; i < n; ++i) {
        while (cnt[a[l]] == 1 && l < i) ++l;
        if (l > 0 && a[l] - a[l - 1] <= 1) --l;
        checkmax(l, mn);
        if (cnt[a[i]] == 1) checkmax(mn, i);
        if (i > 0 && a[i] - a[i - 1] > 1) checkmax(mn, i), l = i;
        if (ifmax(ans, i - l)) answer = {l, i};
    } 
    vector<int> b(a.begin() + answer.f, a.begin() + answer.s + 1);
    n = sz(b);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        if (i & 1) c[n - i / 2 - 1] = b[i];
        else c[i / 2] = b[i];
    }
    cout << n << '\n';
    for (auto i : c) cout << i << ' ';
    return 0;
}