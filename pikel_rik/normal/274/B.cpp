#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, a[N];
vector<int> g[N];
pair<ll, ll> ans[N];

void dfs(int x, int p) {
    ll max_a = 0, max_b = 0;

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x);

        max_a = max(max_a, ans[i].first);
        max_b = max(max_b, ans[i].second);
    }

    ll diff = a[x] + max_a - max_b;
    if (diff >= 0)
        max_b += diff;
    else max_a -= diff;

    ans[x] = {max_a, max_b};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dfs(1, 0);

    cout << ans[1].first + ans[1].second << "\n";
    return 0;
}