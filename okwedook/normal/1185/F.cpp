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

int readtype() {
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int t;
        cin >> t;
        ans |= (1 << (t - 1));
    }
    return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    vector<int> friends(512);
    for (int i = 0; i < n; ++i) 
        ++friends[readtype()];
    for (int i = sz(friends) - 1; i >= 0; --i)
        for (int j = 0; j < i; ++j)
            if ((j & i) == j) friends[i] += friends[j];
    vector<vector<pii>> pizza(512);
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        pizza[readtype()].pb({c, i});
    }
    vector<pair<int, pii>> pizzas;
    for (int i = 0; i < sz(pizza); ++i) {
        sort(pizza[i]);
        while (sz(pizza[i]) > 2) pizza[i].popb();
        for (auto j : pizza[i]) 
            pizzas.pb({i, j});
    }
    int mxcnt = 0;
    int ans = 2e9 + 10;
    pii answer = {-1, -1};
    for (int i = 0; i < sz(pizzas); ++i)
        for (int j = i + 1; j < sz(pizzas); ++j) {
            if (ifmax(mxcnt, friends[(pizzas[i].f | pizzas[j].f)])) {
                ans = pizzas[i].s.f + pizzas[j].s.f;
                answer = {pizzas[i].s.s, pizzas[j].s.s};
            }
            if (mxcnt == friends[(pizzas[i].f | pizzas[j].f)]) 
                if (ifmin(ans, pizzas[i].s.f + pizzas[j].s.f)) {
                    answer = {pizzas[i].s.s, pizzas[j].s.s};
                }
        }
    cout << answer.f + 1 << ' ' << answer.s + 1;
    return 0;
}