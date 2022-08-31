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
const int maxN = 5e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
int c[maxN];

void solve() {
    int n, m;
    cin >> n >> m;
    range(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<pair<int, int>> p(n);
    range(i, n) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(all(p));
    for(auto &[cl, v]: p) {
        sort(all(g[v]), [&] (int a, int b) {return c[a] < c[b];});
        c[v] = 1;
        for(auto &u: g[v]) {
            if (c[u] == c[v]) c[v]++;
        }
        if (cl != c[v]) {
            cout << "-1\n";
            return;
        }
    }
    range(i, n) cout << p[i].second + 1 << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}