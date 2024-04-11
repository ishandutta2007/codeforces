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

#ifdef DEBUG
    template<class T> T to_dbg(T x) { return x; }
    template<class T, class U> string to_dbg(pair<T, U> p) {
        stringstream ss;
        ss << '{' << p.f << ',' << p.s << '}';
        return ss.str();
    }
    string to_dbg(string s) { return "\"" + s + "\""; }
    template<class T> string to_dbg(vector<T> a) {
        stringstream ss;
        ss << '{';
        if (sz(a)) ss << to_dbg(a[0]);
        for (int i = 1; i < sz(a); ++i)
            ss << "," << to_dbg(a[i]);
        ss << '}';
        return ss.str();
    }
    template<class T>
    void dbgout(T x) { cout << to_dbg(x) << endl; }
    template<class T, class... U>
    void dbgout(T t, U... u) {
        cout << to_dbg(t) << ", ";
        dbgout(u...);
    }
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__);
#else
    #define dbg(...) 0
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

vector<string> s;
vector<vector<bool>> used;
int n, m;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || used[x][y] || s[x][y] != '#') return;
    used[x][y] = true;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

signed main() {
    FAST; FIXED;
    cin >> n >> m;
    s = vector<string> (n);
    cin >> s;
    vector<int> cx(n), cy(m);
    for (int i = 0; i < n; ++i) {
        int mn = mod, mx = -1, cnt = 0;
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '#') {
                checkmin(mn, j);
                checkmax(mx, j);
                ++cnt;
            }
        cx[i] = cnt;
        if (cnt > 0 && cnt != mx - mn + 1) {
            cout << -1;
            return 0;
        }
    }
    for (int j = 0; j < m; ++j) {
        int mn = mod, mx = -1, cnt = 0;
        for (int i = 0; i < n; ++i)
            if (s[i][j] == '#') {
                checkmin(mn, i);
                checkmax(mx, i);
                ++cnt;
            }
        cy[j] = cnt;
        if (cnt > 0 && cnt != mx - mn + 1) {
            cout << -1;
            return 0;
        }
    }
    vector<bool> canx(n), cany(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (cx[i] == 0 && cy[j] == 0) {
                canx[i] = true;
                cany[j] = true;
            }
    for (int i = 0; i < n; ++i)
        if (cx[i] == 0 && !canx[i]) {
            cout << -1;
            return 0;
        }
    for (int j = 0; j < m; ++j)
        if (cy[j] == 0 && !cany[j]) {
            cout << -1;
            return 0;
        }
    int ans = 0;
    used = vector<vector<bool>>(n, vector<bool>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            if (s[i][j] == '#' && !used[i][j]) {
                ++ans;
                dfs(i, j);
            }
    cout << ans;
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}