#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 100;
const int md = 998244353;
const ll INF = 2e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        g[x - 1].push_back(i);
    }
    vector<int> dwn(n);
    function<void(int)> dfs1 = [&](int v) {
        for (auto &u : g[v]) {
            dfs1(u);
            dwn[v] = max(dwn[v], dwn[u] + 1);
        }
    };
    vector<int> answer;
    function<void(int)> dfs = [&](int v) {
        answer.push_back(v);
        k--;
        if (k == 0) return;
        sort(all(g[v]), [&](const int i, const int j) {
            return dwn[i] > dwn[j];
        });
        for (auto &u : g[v]) {
            dfs(u);
            answer.push_back(v);
            if (k == 0) break;
        }
    };
    dfs1(0);
    dfs(0);
    reverse(all(answer));
    vector<bool> was(n);
    while (answer.size() > 1) {
        if (was[answer[(int)answer.size() - 2]]) break;
        was[answer.back()] = true;
        answer.pop_back();
    }
    cout << (int)answer.size() - 1 << '\n';
    for (auto &x : answer) cout << x + 1 << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}