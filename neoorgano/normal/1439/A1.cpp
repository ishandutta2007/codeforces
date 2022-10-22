#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int arr[MAXN][MAXN];
vector<array<int, 6>> ans;

int n, m;

void get(int x, int y) {
    array<array<int, 2>, 2> d;
    int cnt = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            d[i][j] = arr[x + i][y + j];
            cnt += d[i][j];
        }
    }
    if (cnt == 0) {
        return;
    }
    if (cnt == 4) {
        ans.push_back({x, y, x + 1, y, x, y + 1});
        arr[x][y] ^= 1; arr[x + 1][y] ^= 1; arr[x][y + 1] ^= 1;
        get(x, y);
        return;
    }
    vector<array<int, 2>> cur;
    vector<array<int, 2>> nl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (d[i][j]) {
                cur.push_back({i + x, j + y});
            } else {
                nl.push_back({i + x, j + y});
            }
        }
    }
    if (cnt == 3) {
        array<int, 6> el;
        for (int i = 0; i < 3; ++i) {
            el[2 * i] = cur[i][0];
            el[2 * i + 1] = cur[i][1];
            arr[cur[i][0]][cur[i][1]] ^= 1;
        }
        ans.push_back(el);
        get(x, y);
        return;
    }
    array<int, 6> el;
    for (int i = 0; i < 2; ++i) {
        el[2 * i] = nl[i][0];
        el[2 * i + 1] = nl[i][1];
        arr[nl[i][0]][nl[i][1]] ^= 1;
    }
    el[4] = cur[0][0];
    el[5] = cur[0][1];
    arr[cur[0][0]][cur[0][1]] ^= 1;
    ans.push_back(el);
    get(x, y);
    return;
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        ans.clear();
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                arr[i][j] = s[j] - '0';
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == 1) {
                    int x = i, y = j;
                    if (x == n - 1) {
                        x--;
                    }
                    if (y == m - 1) {
                        y--;
                    }
                    get(x, y);
                }
            }
        }
        cout << ans.size() << endl;
        for (auto elem : ans) {
            for (int i = 0; i < 6; ++i) {
                cout << elem[i] + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}