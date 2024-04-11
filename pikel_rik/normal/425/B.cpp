#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 9;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

    int ans = INT_MAX;
    for (int j = 0; j < m; j++) {
        int cost = 0;
        for (int jj = 0; jj < m; jj++) {
            int c1 = 0, c2 = 0;
            for (int i = 0; i < n; i++) {
                if (a[i][jj] == a[i][j])
                    c2++;
                else c1++;
            }
            cost += min(c1, c2);
        }
        ans = min(ans, cost);
    }

    for (int i = 0; i < n; i++) {
        int cost = 0;
        for (int ii = 0; ii < n; ii++) {
            int c1 = 0, c2 = 0;
            for (int j = 0; j < m; j++) {
                if (a[ii][j] == a[i][j])
                    c2++;
                else c1++;
            }
            cost += min(c1, c2);
        }
        ans = min(ans, cost);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += accumulate(a[i].begin(), a[i].end(), 0);
    }
    ans = min(ans, min(sum, n * m - sum));
    cout << (ans <= k ? ans : -1) << '\n';
    return 0;
}