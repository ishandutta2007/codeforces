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

graph G;
vector<int> val;
int cnt = 0;

void dfs(int v) {
    reverse(G[v]);
    for (auto i : G[v]) 
        dfs(i);
    val[v] = cnt++;
}

void solve() {
    int n;
    cin >> n;
    vector<int> next(n);
    cin >> next;
    for (auto &i : next) --i;
    for (int i = 0; i < n; ++i)
        if (next[i] >= 0 && next[i] <= i) {
            cout << -1 << '\n';
            return;
        }
    if (next.back() >= 0 && next.back() != n) {
        cout << -1;
        return;
    }
    for (int i = n - 1; i >= 0; --i)
        if (next[i] < 0) next[i] = i + 1;
    cnt = 0;
    G = graph(n + 1);
    for (int i = 0; i < n; ++i) G[next[i]].pb(i);
    val = vector<int>(n + 1);
    dfs(n);
    vector<int> st(1, n);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
        while (sz(st) && val[st.back()] < val[i]) st.popb();
        ans[i] = st.back();
        st.pb(i);
    }
    if (ans != next) cout << -1;
    else {
        for (int i = 0; i < n; ++i) cout << val[i] + 1 << ' ';
    }
    cout << '\n';
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}