#pragma GCC optimize("O3", "unroll-all-loops")
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
#include <complex>
 
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

void makepref(vector<int> &pref) {
    for (int i = 1; i < sz(pref); ++i)
        pref[i] += pref[i - 1];
}

int get(vector<int> &pref, int r) {
    return r < 0 ? 0 : pref[r];
}

int get(vector<int> &pref, int l, int r) {
    if (l > r) return 0;
    return get(pref, r) - get(pref, l - 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;
    map<int, int> st;
    for (auto i : p) st[i]++;
    vector<int> cnt;
    for (auto i : st) cnt.pb(i.s);
    reverse(cnt);
    if (sz(cnt) < 4) {
        cout << "0 0 0\n";
        return;
    }
    int allsum = 0;
    int ptr = 1;
    vector<int> pref = cnt;
    makepref(pref);
    vector<int> answer = {0, 0, 0};
    for (int b = 0; b < sz(cnt); ++b) {
        allsum += cnt[b];
        if (allsum * 2 > n) break;
        if (b < 2) continue;
        while (get(pref, 1, ptr) < get(pref, ptr + 1, b)) ++ptr;
        int val = min(get(pref, 1, ptr), get(pref, ptr + 1, b));
        bool flag = false;
        if (ptr > 1) {
            int newval = min(get(pref, 1, ptr - 1), get(pref, ptr, b));
            if (ifmax(val, newval)) flag = true;
        }
        if (val > cnt[0]) {
            answer.clear();
            answer.pb(cnt[0]);
            answer.pb(get(pref, 1, ptr - flag));
            answer.pb(get(pref, ptr + 1 - flag, b));
        }
    }
    for (auto i : answer) cout << i << ' ';
    cout << '\n';
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}