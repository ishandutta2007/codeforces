#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a[N];
vector<int> g[N];

ll dfs(int x, int p) {
    vector<ll> v;
    int s = 0;

    for (int &i : g[x]) {
        if (i == p or !a[i]) continue;
        a[i]--;
        v.push_back(dfs(i, x));
        s += a[i];
    }

    sort(all(v));
    ll r = 0;

    while (a[x] and v.size()) {
        r += v.back() + 2;
        a[x]--;
        v.pop_back();
    }

    int y = min(a[x], s);
    r += 2 * y;
    a[x] -= y;
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int s;
    cin >> s;
    cout << dfs(s, 0) << "\n";
    return 0;
}