#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

bool mini(auto& x, const auto& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

bool maxi(auto& x, const auto& y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = (int) 1e5 + 123;

int n;
vector<int> g[N];
int dp[N];

void dfs(int v) {
    if (g[v].empty()) {
        dp[v] = 1;
        return;
    }
    for (int u : g[v]) {
        dfs(u);
        dp[v] += dp[u];
    }
}

int ans[N];

void run() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    dfs(1);
    vector<pair<int, int>> kek;
    for (int i = 1; i <= n; i++) {
        kek.emplace_back(dp[i], i);
    }
    sort(kek.begin(), kek.end());
    for (int i = 0; i < n; i++) {
        ans[i + 1] = kek[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}