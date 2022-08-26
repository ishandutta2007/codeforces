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
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 5e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
int h[maxN];
vector<int> ans;
int need;
bool finded = false;
void dfs(int v) {
    if (h[v] == need) {
        ans.push_back(v);
        finded = true;
        return;
    }
    for(auto &u: g[v]) {
        if (h[u]) continue;
        h[u] = h[v] + 1;
        dfs(u);
        if (finded) {
            ans.push_back(v);
            return;
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        g[i].clear();
        h[i] = 0;
    }
    ans.clear();
    finded = false;
    range(i, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    need = (n - 1) / 2 + 1;
    h[1] = 1;
    dfs(1);
    if (finded) {
        cout << "PATH\n";
        cout << need << "\n";
        range(i, need) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    vector<int> a(n);
    range(i, n) a[i] = i + 1;
    sort(rall(a), [&] (int &x, int &y) {
        return h[x] < h[y];
    });
    vector<pair<int, int>> answ;
    int prev = a[0];
    for(int i = 1; i < n; ++i) {
        if (h[a[i]] != h[a[i-1]]) prev = -1;
        if (prev == -1) prev = a[i];
        else {
            answ.emplace_back(prev, a[i]);
            prev = -1;
        }
    }

    cout << "PAIRING\n";
    cout << answ.size() << "\n";
    range(i, (int)answ.size()) {
        cout << answ[i].first << " " << answ[i].second << "\n";
    }
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