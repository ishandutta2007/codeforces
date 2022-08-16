#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (auto &s : a) cin >> s;

    vector<vector<int>> deg(n, vector<int>(m)), ans(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                deg[i][j] = -1;
            } else {
                if (i + 1 < n && a[i + 1][j] == '.') deg[i][j] += 1;
                if (j + 1 < m && a[i][j + 1] == '.') deg[i][j] += 1;
                if (i > 0 && a[i - 1][j] == '.') deg[i][j] += 1;
                if (j > 0 && a[i][j - 1] == '.') deg[i][j] += 1;
            }
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && deg[i][j] == 0) {
                return cout << "Not unique\n", 0;
            }
            if (a[i][j] == '.' && deg[i][j] == 1) {
                q.emplace(i, j);
            }
        }
    }

    auto occupy = [&](int i, int j) -> void {
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                deg[ni][nj] -= 1;
                if (deg[ni][nj] == 1) {
                    q.emplace(ni, nj);
                }
            }
        }
    };

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        if (a[i][j] != '.') continue;
        occupy(i, j);

        if (i + 1 < n && a[i + 1][j] == '.') {
            a[i][j] = '^', a[i + 1][j] = 'v', occupy(i + 1, j);
        } else if (j + 1 < m && a[i][j + 1] == '.') {
            a[i][j] = '<', a[i][j + 1] = '>', occupy(i, j + 1);
        } else if (i > 0 && a[i - 1][j] == '.') {
            a[i][j] = 'v', a[i - 1][j] = '^', occupy(i - 1, j);
        } else if (j > 0 && a[i][j - 1] == '.') {
            a[i][j] = '>', a[i][j - 1] = '<', occupy(i, j - 1);
        }
    }

    int not_visited = 0;
    for (int i = 0; i < n; i++) not_visited += count(a[i].begin(), a[i].end(), '.');

    if (not_visited != 0) {
        return cout << "Not unique\n", 0;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}