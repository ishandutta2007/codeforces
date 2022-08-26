#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int cnt = INFi;
vector<int> centres;
vector<int> g[maxN];
int n;
int dfs(int v, int p) {
    int res = 0;
    int s = 1;
    for(auto &u: g[v]) {
        if (u == p) continue;
        int w = dfs(u, v);
        s += w;
        res = max(res, w);
    }
    res = max(res, n - s);
    if (cnt > res) {
        cnt = res;
        centres.clear();
    }
    if (cnt == res) {
        centres.push_back(v);
    }
    return s;
}

int dfs2(int v, int p) {
    for(auto &u: g[v]) {
        if (u == p) continue;
        return dfs2(u, v);
    }
    return v;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) g[i].clear();
    cnt = INFi;
    centres.clear();
    range(_, n - 1) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1);
    if (centres.size() == 1) {
        cout << 1 << " " << g[1][0] << "\n";
        cout << 1 << " " << g[1][0] << "\n";
        return;
    }
    int f = dfs2(centres[0], centres[1]);
    if (f != centres[0]) {
        cout << g[f][0] << " " << f << "\n";
        cout << f << " " << centres[1] << "\n";
        return;
    }
    f = dfs2(centres[1], centres[0]);
    cout << g[f][0] << " " << f << "\n";
    cout << f << " " << centres[0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}