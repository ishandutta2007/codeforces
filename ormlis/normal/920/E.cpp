#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 2e5+1;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

unordered_set<int> g[maxN];
unordered_set<int> nocolor;
int color[maxN];

void dfs(int v, int col) {
    vector<int> todel;
    for(auto u: nocolor) {
        if (g[v].find(u) == g[v].end()) todel.push_back(u);
    }
    for(auto u: todel) {
        color[u] = col;
        nocolor.erase(u);
    }
    for(auto u: todel) {
        dfs(u, col);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    range(i, m) {
        int x, y; cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }
    for(int i = 1; i <= n; ++i) nocolor.insert(i);
    int clr = 1;
    for(int i = 1; i <= n; ++i) {
        if (!color[i]) {dfs(i, clr); clr++;}
    }
    vector<int> colors(clr-1);
    for(int i = 1; i <= n; ++i) colors[color[i]-1]++;
    sort(all(colors));
    cout << colors.size() << '\n';
    range(i, clr-1) cout << colors[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}