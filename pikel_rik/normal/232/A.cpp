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
const int N = 100 + 5;

int k, n = 2, i = 0;
bool adj[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;

    while (k > 0) {
        if (k < i) i = 0, n++;
        adj[n - 1][i] = adj[i][n - 1] = true;
        k -= i;
        i++;
        if (i >= n - 1 && k) i = 0, n++;
    }

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j];
        }
        cout << '\n';
    }
    return 0;
}