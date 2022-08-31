#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int n, m;
vector<vector<int>> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        vector<int> dist(n, -1);

        for (int i = 0; i < n; i++) {
            if (a[i][j] % m == (j + 1) % m and a[i][j] / m >= (j == m - 1) and a[i][j] / m < n + (j == m - 1)) {
                int pos = a[i][j] / m - (j == m - 1);
                dist[i] = (pos <= i ? i - pos : i + n - pos);
            }
        }

        int best = n;

        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[dist[i]]++;
        }

        for (auto &[dist, cnt] : mp) {
            if (dist == -1) continue;
            best = min(best, dist + n - cnt);
        }
        ans += best;
    }

    cout << ans << "\n";
    return 0;
}