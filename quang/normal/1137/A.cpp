#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
int a[N][N];
pair<int, int> b[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++) {
        vector<int> val;
        for (int j = 1; j <= m; j++) val.push_back(a[i][j]);
        sort(val.begin(), val.end());
        val.resize(unique(val.begin(), val.end()) - val.begin());
        for (int j = 1; j <= m; j++) {
            int pos = lower_bound(val.begin(), val.end(), a[i][j]) - val.begin();
            b[i][j].first = max(b[i][j].first, pos);
            b[i][j].second = max(b[i][j].second, (int)val.size() - pos - 1);
        }
    }

    for (int j = 1; j <= m; j++) {
        vector<int> val;
        for (int i = 1; i <= n; i++) val.push_back(a[i][j]);
        sort(val.begin(), val.end());
        val.resize(unique(val.begin(), val.end()) - val.begin());
        for (int i = 1; i <= n; i++) {
            int pos = lower_bound(val.begin(), val.end(), a[i][j]) - val.begin();
            b[i][j].first = max(b[i][j].first, pos);
            b[i][j].second = max(b[i][j].second, (int)val.size() - pos - 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j].second + b[i][j].first + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}