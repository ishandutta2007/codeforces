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
 
vector<vector<pair<ll, int>>> G;
 
signed main() {
    FAST; FIXED; RANDOM;
    int n, m, k;
    cin >> n >> m >> k;
    G = vector<vector<pair<ll, int>>>(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        G[u].pb({w, v});
        G[v].pb({w, u});
    }
    for (int i = 0; i < n; ++i) {
        sort(G[i]);
        while (sz(G[i]) > k) G[i].popb();
    }
    vector<ll> dists;
    set<pair<ll, int>> st;
    map<int, ll> mp;
    for (int i = 0; i < n; ++i) {
        st = {{0, i}};
        mp = {{i, 0}};
        vector<ll> nd;
        int cnt = k + 1;
        while (sz(st) && cnt--) {
            auto f = *st.begin();
            st.erase(f);
            if (f.f > 0) nd.pb(f.f);
            for (auto i : G[f.s]) {
                if (sz(st) == k && f.f + i.f >= (--st.end())->f ||
                    sz(dists) == k * 2 && f.f + i.f >= dists.back()) break;
                if (!mp.count(i.s) || mp[i.s] > f.f + i.f) {
                    st.erase({mp[i.s], i.s});
                    mp[i.s] = f.f + i.f;
                    st.insert({mp[i.s], i.s});
                    if (sz(st) > k) {
                        auto last = *--st.end();
                        mp.erase(last.s);
                        st.erase(last);
                    }
                }
            }
        }
        int p = sz(dists);
        for (auto i : nd) dists.pb(i);
        inplace_merge(dists.begin(), dists.begin() + p, dists.end());
        while (sz(dists) > k * 2) dists.popb();
    }
    cout << dists.back();
    return 0;
}