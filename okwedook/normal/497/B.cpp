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

int get(vector<int> &pref, int l, int r) {
    if (l == 0) return pref[r];
    return pref[r] - pref[l - 1];
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> c1(n), c2(n);
    for (int i = 0; i < n; ++i) {
        c1[i] = a[i] == 1;
        c2[i] = a[i] == 2;
    }
    for (int i = 1; i < n; ++i) {
        c1[i] += c1[i - 1];
        c2[i] += c2[i - 1];
    }
    vector<pii> ans;
    for (int t = n; t >= 1; --t) {
        int curr = 0, cnt1 = 0, cnt2 = 0, last = -1;
        bool flag = true;
        while (curr < n) {
            int l = curr - 1, r = n;
            while (r - l > 1) {
                int m = r + l >> 1;
                if (max(get(c1, curr, m), get(c2, curr, m)) < t) l = m;
                else r = m;
            }
            if (max(get(c1, curr, r), get(c2, curr, r)) != t) {
                flag = false;
                break;
            }
            if (get(c1, curr, r) > get(c2, curr, r)) ++cnt1, last = 1;
            else ++cnt2, last = 2;
            curr = r + 1;
        }
        if (flag && (last == 1 && cnt1 > cnt2 || last == 2 && cnt2 > cnt1)) ans.pb({max(cnt1, cnt2), t});
    }
    sort(ans);
    cout << sz(ans) << '\n';
    for (auto i : ans) cout << i.f << ' ' << i.s << '\n';
    return 0;
}