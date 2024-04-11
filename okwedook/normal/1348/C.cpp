#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

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

string solve1(map<char, int> cnt, int k) {
    string ans;
    for (auto i : cnt)
        ans += string((i.s + k - 1) / k, i.f);
    return ans;
}

string solve2(map<char, int> cnt, int k) {
    string ans;
    int curr = 0;
    for (auto i : cnt) {
        if (curr == 0) ans += string(i.s - k + 1, i.f);
        else ans += string(i.s, i.f);
        ++curr;
    }
    return ans;
}

string solve3(map<char, int> cnt, int k) {
    string ans;
    for (auto i : cnt) {
        ans += string((i.s + k - 1) / k, i.f);
        if (i.s % k != 0) k = i.s % k;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s);
    if (s[0] != s[k - 1]) {
        cout << s[k - 1] << '\n';
        return;
    }
    map<char, int> cnt;
    for (auto i : s) cnt[i]++;
    if (sz(cnt) == 1) {
        for (auto i : cnt) {
            int x = (i.s + k - 1) / k;
            cout << string(x, i.f) << '\n';
            return;
        }
    }
    cout << min(solve2(cnt, k), solve3(cnt, k)) << '\n';
}

signed main() {
    FAST; FIXED;
    int t;
    cin >> t;
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}