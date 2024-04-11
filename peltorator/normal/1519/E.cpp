#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

vector<vector<int>> takes;
vector<vector<pair<int, int>>> g;
vector<int> h;
vector<int> used;

int dfs(int v, int pr) {
    used[v] = 1;
    int curin = 0;
    for (auto [u, ind] : g[v]) {
        if (ind == pr) {
            continue;
        } else if (used[u] && h[u] < h[v]) {
            takes[v].push_back(ind);
            curin++;
        } else if (!used[u]) {
            h[u] = h[v] + 1;
            int tou = dfs(u, ind);
            if (tou) {
                takes[v].push_back(ind);
                curin++;
            } else {
                takes[u].push_back(ind);
            }
        }
    }
    if (curin % 2 == 1) {
        return 0;
    } else {
        return 1;
    }
}

int solve() {
    int m;
    if (!(cin >> m )) {
        return 1;
    }
    map<pair<ll, ll>, int> inds;
    int curind = 0;
    vector<int> left, right;
    for (int i = 0; i < m; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll l1x = a * d, l1y = b * (c + d);
        ll l1gcd = gcd(l1x, l1y);
        l1x /= l1gcd;
        l1y /= l1gcd;
        if (!inds.count({l1x, l1y})) {
            inds[{l1x, l1y}] = curind++;
        }
        left.push_back(inds[{l1x, l1y}]);

        ll l2x = (a + b) * d, l2y = b * c;
        ll l2gcd = gcd(l2x, l2y);
        l2x /= l2gcd;
        l2y /= l2gcd;
        if (!inds.count({l2x, l2y})) {
            inds[{l2x, l2y}] = curind++;
        }
        right.push_back(inds[{l2x, l2y}]);
    }
    int n = curind;
    g.clear();
    g.resize(n);
    for (int i = 0; i < m; i++) {
        g[left[i]].push_back({right[i], i});
        g[right[i]].push_back({left[i], i});
    }
    takes.clear();
    takes.resize(n);
    used.assign(n, 0);
    h.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            h[i] = 0;
            dfs(i, -1);
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < sz(takes[i]); j += 2) {
            ans.push_back({takes[i][j], takes[i][j + 1]});
        }
    }
    cout << sz(ans) << '\n';
    for (auto [l, r] : ans) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}