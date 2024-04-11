#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

// @author: pashka

using namespace std;

vector<vector<bool>> a;
vector<vector<bool>> z;
vector<int> p;
vector<int> w;

int get(int x) {
    if (p[x] != x) p[x] = get(p[x]);
    return p[x];
}

void join(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return;
    if (w[x] < w[y]) {
        p[x] = y;
        w[y] += w[x];
    } else {
        p[y] = x;
        w[x] += w[y];
    }
}

int n, m;
int pp;

void dfs(int x, int y) {
    if (x < 0 || x == n || y < 0 || y == m || z[x][y] || !a[x][y] || pp == 0) return;
    z[x][y] = true;
    pp--;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {
    long long k;
    scanf("%d%d%I64d", &n, &m, &k);

    vector<pair<int, pair<int, int>>> cells(n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c;
            scanf("%d", &c);
            cells[i * m + j] = make_pair(c, make_pair(i, j));
        }
    }

    sort(cells.begin(), cells.end());
    a.assign(n, vector<bool>(m, false));
    z.assign(n, vector<bool>(m, false));
    p.assign(n * m, 0);
    w.assign(n * m, 1);
    for (int i = 0; i < n * m; i++) {
        p[i] = i;
    }

    for (int i = n * m - 1; i >= 0; i--) {
        int c = cells[i].first;
        int x = cells[i].second.first;
        int y = cells[i].second.second;
        a[x][y] = true;
        if (x > 0 && a[x - 1][y]) {
            join(x * m + y, (x - 1) * m + y);
        }
        if (x < n - 1 && a[x + 1][y]) {
            join(x * m + y, (x + 1) * m + y);
        }
        if (y > 0 && a[x][y - 1]) {
            join(x * m + y, x * m + y - 1);
        }
        if (y < m - 1 && a[x][y + 1]) {
            join(x * m + y, x * m + y + 1);
        }
        int r = get(x * m + y);
//        cout << x << " " << y << " " << c << " " << w[r] << endl;
        if (k % c == 0 && w[r] >= k / c) {
            cout << "YES" << endl;
            pp = (int) (k / c);
            dfs(x, y);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << (z[i][j] ? c : 0) << " ";
                }
                cout << endl;
            }
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}