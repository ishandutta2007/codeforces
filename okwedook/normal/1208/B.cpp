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

int val[2000];
int cnt1 = 0, cnt = 0;

void add(int x) {
    if (val[x] == 1) --cnt1, ++cnt;
    if (val[x] == 0) ++cnt1;
    ++val[x];
}

void del(int x) {
    if (val[x] == 1) --cnt1;
    if (val[x] == 2) --cnt, ++cnt1;
    --val[x];
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    map<int, int> st;
    for (auto i : a) st[i];
    int c = 0;
    for (auto &i : st) i.s = c++;
    for (auto &i : a) i = st[i];
    vector<int> val(n);
    for (auto i : a) add(i);
    if (cnt == 0) {
        cout << 0;
        return 0;
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            del(a[j]);
            if (cnt == 0) checkmin(ans, j - i + 1);
        }
        for (int j = i; j < n; ++j) add(a[j]);
    }
    cout << ans;
    return 0;
}