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

vector<vector<pii>> add, del;
vector<multiset<int>> st;
ll sum = 0;

void insert(multiset<int> &st, int x) {
    sum -= sz(st) ? *(--st.end()) : 0;
    st.insert(x);
    sum += sz(st) ? *(--st.end()) : 0;
}

void erase(multiset<int> &st, int x) {
    sum -= sz(st) ? *(--st.end()) : 0;
    st.erase(st.lower_bound(x));
    sum += sz(st) ? *(--st.end()) : 0;
}

void segm(int l, int r, int x, int i) {
    if (l > r) return;
    add[l].pb({x, i});
    del[r].pb({x, i});
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, w;
    cin >> n >> w;
    add = del = vector<vector<pii>>(w);
    st = vector<multiset<int>>(n);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        vector<int> b(l);
        cin >> b;
        segm(l, w - 1, 0, i);
        segm(0, w - l - 1, 0, i);
        for (int j = 0; j < l; ++j) {
            int mn = j;
            int mx = w - (l - 1 - j) - 1;
            segm(mn, mx, b[j], i);
        }
    }
    for (int i = 0; i < w; ++i) {
        for (auto j : add[i]) insert(st[j.s], j.f);
        cout << sum << ' ';
        for (auto j : del[i]) erase(st[j.s], j.f);
    }
    return 0;
}