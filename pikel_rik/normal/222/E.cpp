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

ll n, m, k, res[52][52];

void multiply(ll a[][52], ll b[][52]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = 0;
            for (int k = 0; k < m; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j] % mod) % mod;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = res[i][j];
        }
    }
}

void matexp(ll ans[][52], ll adj[][52]) {
    n -= 1;
    while (n > 0) {
        if (n & 1) multiply(ans, adj);
        multiply(adj, adj);
        n /= 2;
    }
}

int id(char ch) {
    if (ch >= 'a' and ch <= 'z')
        return ch - 'a';
    return ch - 'A' + 26;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;
    ll adj[52][52], ans[52][52];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            adj[i][j] = 1;
            if (i == j) ans[i][j] = 1;
            else ans[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        char ch1, ch2;
        cin >> ch1 >> ch2;

        adj[id(ch1)][id(ch2)] = 0;
    }

    matexp(ans, adj);
    ll sum = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            sum = (sum + ans[i][j]) % mod;
        }
    }

    cout << sum << "\n";
    return 0;
}