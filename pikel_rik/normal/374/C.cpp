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
const int N = 1e3 + 5;

int n, m;
string a[N];
vector<int> g[N*N];

int dp[N*N];
bool cycle, visited[N*N], active[N*N];

char next(char c) {
    if (c == 'D')
        return 'I';
    if (c == 'I')
        return 'M';
    if (c == 'M')
        return 'A';
    return 'D';
}

int idx(int i, int j) {
    return i * m + j;
}

void dfs(int x) {
    dp[x] = 1;
    visited[x] = true;
    active[x] = true;

    for (int &i : g[x]) {
        if (!visited[i])
            dfs(i);
        else if (active[i])
            cycle = true;
        dp[x] = max(dp[x], 1 + dp[i]);
    }

    active[x] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 and a[i - 1][j] == next(a[i][j])) {
                g[idx(i, j)].push_back(idx(i - 1, j));
            }
            if (j > 0 and a[i][j - 1] == next(a[i][j])) {
                g[idx(i, j)].push_back(idx(i, j - 1));
            }
            if (i + 1 < n and a[i + 1][j] == next(a[i][j])) {
                g[idx(i, j)].push_back(idx(i + 1, j));
            }
            if (j + 1 < m and a[i][j + 1] == next(a[i][j])) {
                g[idx(i, j)].push_back(idx(i, j + 1));
            }
        }
    }

    for (int i = 0; i < n * m; i++) {
        if (!visited[i] and a[i / m][i % m] == 'D')
            dfs(i);
    }

    int ans = *max_element(dp, dp + N*N);
    ans /= 4;

    if (cycle)
        cout << "Poor Inna!\n";
    else if (!ans)
        cout << "Poor Dima!\n";
    else cout << ans << "\n";
    return 0;
}