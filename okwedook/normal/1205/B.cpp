
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

const int N = 121;

bool can[N][N][N][N]; //[cnt][past][from][to]

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    set<pii> edge;
    for (ll l = 0; l < 60; ++l) {
        vector<int> ind;
        for (int i = 0; i < n; ++i)
            if (a[i] & (1ll << l)) ind.pb(i);
        if (sz(ind) >= 3) {
            cout << 3;
            return 0;
        }
        if (sz(ind) == 2) edge.insert({ind[0], ind[1]});
    }
    map<int, int> shrink;
    for (auto i : edge) {
        shrink[i.f];
        shrink[i.s];
    }
    int cnt = 0;
    for (auto &i : shrink) i.s = cnt++;
    vector<pii> change;
    for (auto i : edge) change.pb({shrink[i.f], shrink[i.s]});
    edge.clear();
    for (auto i : change) edge.insert(i);
    for (int i = 0; i < cnt; ++i) 
        for (int p = 0; p < cnt; ++p) 
            can[0][p][i][i] = true;
    for (int c = 1; c <= cnt; ++c) {
        for (int from = 0; from < cnt; ++from)
            for (int past = 0; past < cnt; ++past)
                for (int to = 0; to < cnt; ++to)
                    if (can[c - 1][past][from][to])
                        for (auto e : edge) {
                            if (e.f == to && e.s != past) can[c][to][from][e.s] = true;
                            if (e.s == to && e.f != past) can[c][to][from][e.f] = true;
                        }
    }
    int ans = cnt + 1;
    for (int c = 3; c <= cnt; ++c) {
        for (int from = 0; from < cnt; ++from)
            for (int p = 0; p < cnt; ++p)
                if (can[c][p][from][from]) {
                    checkmin(ans, c);
                    goto go;
                }
    }
    go:
    if (ans > cnt) cout << -1;
    else cout << ans;
    return 0;
}