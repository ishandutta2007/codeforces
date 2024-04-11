#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

vvi g;
vi val;

ll dfs (int a, int p = 1, int depth = 0) {
    ll ans = 0;
    for (int &i : g[a]) {
        if (i == p) continue;
        ans += dfs(i, a, depth + 1);
    }
    val.push_back(depth - ans);
    return ans + 1;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    g.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    sort(all(val));
    reverse(all(val));

    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += val[i];
    }

    cout << ans;
    return 0;
}