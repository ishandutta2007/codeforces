#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int mi = m;
    vector<int> ans(m);
    for (int i = 0; i < m; ++i) {
        ans[i] = i + 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        vector<P> v(m);
        for (int j = 0; j < m; ++j) {
            v[j] = { a[j][i] - a[j][n - 1], j };
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int sum = 0;
        int cnt = 0;
        vector<bool> b(m);
        for (int j = 0; j < m; ++j) {
            if (sum + v[j].first < 0) break;
            sum += v[j].first;
            b[v[j].second] = true;
            ++cnt;
        }
        // cout << i << ' ' << cnt << ' ' << sum << '\n';
        if (mi > m - cnt) {
            mi = m - cnt;
            ans.clear();
            for (int j = 0; j < m; ++j) {
                if (!b[j]) ans.push_back(j + 1);
            }
        }
    }
    cout << mi << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}