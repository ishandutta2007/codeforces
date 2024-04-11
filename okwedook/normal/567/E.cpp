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

signed main() {
    FAST; FIXED;
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;
    vector<vector<pair<int, ll>>> G(n), rev(n);
    vector<pair<pii, ll>> edge;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        edge.pb({{u, v}, w});
        G[u].pb({v, w});
        rev[v].pb({u, w});
    }
    auto getdist = [&](int s, const vector<vector<pair<int, ll>>> &G) {
        vector<ll> dist(n, inf);
        dist[s] = 0;
        auto cmp = [&](int i, int j) {
            return dist[i] > dist[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> que(cmp);
        que.push(s);
        while (sz(que)) {
            auto f = que.top();
            que.pop();
            for (auto i : G[f])
                if (ifmin(dist[i.f], dist[f] + i.s))
                    que.push(i.f);
        }
        return dist;
    };
    auto ds = getdist(s, G), dt = getdist(t, rev);
    vector<pll> check;
    map<ll, int> cnts, cntt;
    for (auto &i : edge) {
        if (ds[i.f.f] + dt[i.f.s] + i.s == ds[t]) {
            check.pb({ds[i.f.f], ds[i.f.f] + i.s});
            ++cnts[ds[i.f.f]];
            ++cntt[dt[i.f.s]];
        }
    }
    sort(check);
    for (int i = 1; i < sz(check); ++i)
        checkmax(check[i].s, check[i - 1].s);
    for (auto &i : edge) {
        if (ds[i.f.f] + dt[i.f.s] + i.s == ds[t]) {
            pll x = pll(ds[i.f.f], ds[i.f.f] + i.s);
            auto it = lower_bound(all(check), x);
            bool flag = *it == x;
            if (++it != check.end())
                if (*it == x) flag = false;
            if (flag && cnts[ds[i.f.f]] == 1 && cntt[dt[i.f.s]] == 1) {
                cout << "YES\n";
            } else if (i.s > 1) cout << "CAN " << 1 << '\n';
            else cout << "NO\n";
        } else {
            ll need = ds[i.f.f] + dt[i.f.s] + i.s - ds[t] + 1;
            if (need < i.s) cout << "CAN " << need << '\n';
            else cout << "NO\n";
        }
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}