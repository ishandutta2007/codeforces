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
#include <cassert>
 
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
 
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (auto &i : s) i -= '0';
    for (auto &i : t) i -= '0';
    vector<int> cnt(4);
    for (int i = 0; i < n; ++i)
        ++cnt[s[i] + t[i] * 2];
    for (int cnt1 = 0; cnt1 <= cnt[1]; ++cnt1)
        for (int cnt2 = 0; cnt2 <= cnt[2]; ++cnt2) {
                int cnt3 = cnt[2] + cnt[3] - cnt1 - cnt2;
                if (cnt3 & 1) continue;
                cnt3 /= 2;
                int cnt0 = n / 2 - cnt1 - cnt3 - cnt2;
                if (cnt3 > cnt[3] || cnt0 > cnt[0] || cnt0 < 0 || cnt3 < 0) continue;
                for (int i = 0; i < n; ++i) {
                    int type = s[i] + 2 * t[i];
                    if (cnt0 && type == 0) cout << i + 1 << ' ', --cnt0;
                    if (cnt1 && type == 1) cout << i + 1 << ' ', --cnt1;
                    if (cnt2 && type == 2) cout << i + 1 << ' ', --cnt2;
                    if (cnt3 && type == 3) cout << i + 1 << ' ', --cnt3;
                }
                return 0;
            }
    cout << -1;
    return 0;
}