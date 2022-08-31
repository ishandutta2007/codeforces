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

ll modexp(ll x, ll n) {
    if (n == 0)
        return 1;
    ll ans = modexp((x * x) % mod, n / 2);
    if (n % 2) return (x * ans) % mod;
    return ans;
}

vector<int> g[2001];
bool visited[2001];

void dfs(int x) {
    visited[x] = true;

    for (int &i : g[x]) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    if (k > n) {
        cout << modexp(m, n) << "\n";
        return 0;
    }

    for (int i = 0; i + k - 1 < n; i++) {
        for (int j = 0; j < k / 2; j++) {
            g[i + j].push_back(i + k - j - 1);
            g[i + k - j - 1].push_back(i + j);
        }
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            c += 1;
        }
    }

    cout << modexp(m, c);
    return 0;
}