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
const int N = 2e5 + 5;

int n, a[N], d[N], cyc = 0;
bool visited[N], cycle[N];

void dfs(int i, int dep = 0) {
    if (cycle[i])
        return;

    if (visited[i]) {
        cyc = dep - d[i];
        return;
    }

    d[i] = dep;
    visited[i] = true;
    dfs(a[i], dep + 1);
}

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n % 2 != 0) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cyc = 0;
            dfs(i);

            int ptr = i;
            while (!cycle[ptr]) {
                cycle[ptr] = true;
                ptr = a[ptr];
            }

            if (cyc > 0)
                ans.push_back(cyc);
        }
    }

    n -= accumulate(all(ans), 0);

    ll res = modexp(2, n);
    for (int i : ans)
        res = res * (modexp(2, i) - 2) % mod;

    cout << res << "\n";
    return 0;
}