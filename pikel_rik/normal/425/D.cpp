#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5;

int n, qi;
pair<int, int> a[N];
vector<int> coord_x[N + 1], coord_y[N + 1];

vector<pair<int, int>> queries[N + 1];

void addQuery(int x, int y) {
    if (x >= 0) {
        queries[x].emplace_back(y, qi++);
    }
}

vector<bool> ans;
void processQueries() {
    ans.assign(qi, false);
    for (int x = 0; x <= N; x++) {
        sort(queries[x].begin(), queries[x].end());
        int ptr = 0;
        for (auto& [y, idx] : queries[x]) {
            while (ptr < coord_x[x].size() and coord_x[x][ptr] < y) {
                ptr++;
            }
            if (ptr < coord_x[x].size() and coord_x[x][ptr] == y) {
                ans[idx] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        coord_x[a[i].first].push_back(a[i].second);
        coord_y[a[i].second].push_back(a[i].first);
    }

    for (int i = 0; i <= N; i++) {
        sort(coord_x[i].begin(), coord_x[i].end());
        sort(coord_y[i].begin(), coord_y[i].end());
    }

    for (int i = 0; i < n; i++) {
        auto [x0, y0] = a[i];
        int idx_x = lower_bound(coord_x[x0].begin(), coord_x[x0].end(), y0) - coord_x[x0].begin();
        int idx_y = lower_bound(coord_y[y0].begin(), coord_y[y0].end(), x0) - coord_y[y0].begin();

        if (idx_x <= idx_y) {
            for (int j = 0; j < idx_x; j++) {
                int d = y0 - coord_x[x0][j]; //(x0, y0), (x0, y0 - d), (x0 - d, y0), (x0 - d, y0 - d)
                addQuery(x0 - d, y0);
                addQuery(x0 - d, y0 - d);
            }
        } else {
            for (int j = 0; j < idx_y; j++) {
                int d = x0 - coord_y[y0][j]; //(x0, y0), (x0 - d, y0), (x0, y0 - d), (x0 - d, y0 - d)
                addQuery(x0, y0 - d);
                addQuery(x0 - d, y0 - d);
            }
        }
    }

    processQueries();

    int cnt = 0;
    for (int i = 1; i < qi; i += 2) {
        cnt += ans[i - 1] && ans[i];
    }
    cout << cnt << '\n';
    return 0;
}