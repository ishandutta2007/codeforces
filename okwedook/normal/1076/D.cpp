#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
#define inf 4000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<pll, ll>>> G(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        G[u].pb({{w, v}, i});
        G[v].pb({{w, u}, i});
    }
    for (auto &i : G) sort(i);
    set<pll> st;
    vector<ll> dp(n, inf);
    vector<ll> p(n, -1);
    vector<bool> used(n);
    dp[0] = 0;
    st.insert({0, 0});
    vector<int> ans;
    while (sz(st)) {
        auto fr = *(st.begin());
        st.erase(fr);
        used[fr.s] = true;
        if (p[fr.s] != -1) ans.pb(p[fr.s]), --k;
        if (k == 0) break;
        for (auto i : G[fr.s]) {
            if (!used[i.f.s] && dp[i.f.s] > i.f.f + fr.f) {
                st.erase(pll(dp[i.f.s], i.f.s));
                dp[i.f.s] = i.f.f + fr.f;
                p[i.f.s] = i.s;
                st.insert({dp[i.f.s], i.f.s});
            }
        }
    }
    cout << sz(ans) << '\n';
    for (auto i : ans) cout << i + 1 << ' ';
    return 0;
}