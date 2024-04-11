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
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int used[maxN];
int color[maxN];
vector<pair<int, int>> g2[maxN];
int d[maxN];

void solve() {
    int n,m; cin >> n >> m;
    range(i, m) {
        int u, v, t; cin >> u >> v >> t;
        if (u == v) continue;
        g2[v].emplace_back(u, t);
    }
    range(i, n + 1) color[i] = d[i] = -1;
    queue<int> q;
    q.push(n);
    used[n] = 1;
    d[n] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto &p: g2[v]) {
            if (used[p.first]) continue;
            if (color[p.first] == -1) {
                color[p.first] = p.second ^ 1;
            } else if (color[p.first] == p.second){
                used[p.first] = 1;
                q.push(p.first);
                d[p.first] = d[v] + 1;
            }
        }
    }
    cout << d[1] << "\n";
    for(int i = 1; i <= n; ++i) {
        if (color[i] == -1) color[i] = 0;
        cout << color[i];
    }
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