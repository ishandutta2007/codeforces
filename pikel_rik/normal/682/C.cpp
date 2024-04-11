#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, a[N];
vector<pair<int, int>> g[N];

int ans = 0;

void dfs(int x = 1, int p = -1, ll dep = 0) {
    if (a[x] >= dep)
        ans += 1;
    else return;

    for (auto pi : g[x]) {
        if (pi.first == p) continue;
        dfs(pi.first, x, max((ll)pi.second, dep + pi.second));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        int p, c; cin >> p >> c;
        g[i+1].emplace_back(p, c);
        g[p].emplace_back(i + 1, c);
    }

    dfs();

    cout << n - ans << "\n";
    return 0;
}