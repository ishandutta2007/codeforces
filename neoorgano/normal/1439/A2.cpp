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

void get2(int i, int j) {
    int d;
    if (i == 0) {
        d = 1;
    } else {
        d = -1;
    }
    int cnt = 0;
    for (int k = 0; k < 3; ++k) {
        cnt += arr[i][j + k];
    }
    if (cnt == 0) {
        return;
    } else if (cnt == 3) {
        ans.push_back({i, j, i, j + 1, i + d, j + 1});
        ans.push_back({i, j + 1, i + d, j + 1, i + d, j + 2});
        ans.push_back({i, j + 1, i, j + 2, i + d, j + 2});
    } else if (cnt == 1) {
        if (arr[i][j] == 1 || arr[i][j + 1] == 1) {
            get(min(i, i + d), j);
        } else {
            get(min(i, i + d), j + 1);
        }
    } else if (arr[i][j] == 0) {
        ans.push_back({i, j + 1, i + d, j + 1, i + d, j + 2});
        ans.push_back({i, j + 2, i + d, j + 1, i + d, j + 2});
    } else if (arr[i][j + 2] == 0) {
        ans.push_back({i, j, i + d, j, i + d, j + 1});
        ans.push_back({i, j + 1, i + d, j, i + d, j + 1});
    } else {
        ans.push_back({i, j, i, j + 1, i + d, j + 1});
        ans.push_back({i + d, j + 1, i, j + 1, i, j + 2});
    }
    for (int k = 0; k < 3; ++k) {
        arr[i][j + k] = 0;
    }
}

void get3(int i, int j) {
    int d;
    if (j == 0) {
        d = 1;
    } else {
        d = -1;
    }
    int cnt = 0;
    for (int k = 0; k < 3; ++k) {
        cnt += arr[i + k][j];
    }
    if (cnt == 0) {
        return;
    } else if (cnt == 3) {
        ans.push_back({i, j, i + 1, j, i + 1, j + d});
        ans.push_back({i + 1, j, i + 1, j + d, i + 2, j + d});
        ans.push_back({i + 1, j, i + 2, j, i + 2, j + d});
    } else if (cnt == 1) {
        if (arr[i][j] == 1 || arr[i + 1][j] == 1) {
            get(i, min(j, j + d));
        } else {
            get(i + 1, min(j, j + d));
        }
    } else if (arr[i][j] == 0) {
        ans.push_back({i + 1, j, i + 1, j + d, i + 2, j + d});
        ans.push_back({i + 2, j, i + 1, j + d, i + 2, j + d});
    } else if (arr[i + 2][j] == 0) {
        ans.push_back({i, j, i, j + d, i + 1, j + d});
        ans.push_back({i + 1, j, i, j + d, i + 1, j + d});
    } else {
        ans.push_back({i, j, i + 1, j, i + 1, j + d});
        ans.push_back({i + 1, j + d, i + 1, j, i + 2, j});
    }
    for (int k = 0; k < 3; ++k) {
        arr[i + k][j] = 0;
    }
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        ans.clear();
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                arr[i][j] = s[j] - '0';
            }
        }
        int dn = n % 2 + 2;
        int dm = m % 2 + 2;
        for (int i = 0; i < n - dn; i += 2) {
            for (int j = 0; j < m - dm; j += 2) {
                get(i, j);
            }
        }
        if (dm == 2) {
            for (int i = 0; i < n - dn; i += 2) {
                get(i, m - dm);
            }
        } else {
            for (int i = 0; i < n - dn; ++i) {
                get2(i, m - dm);
            }
        }
        if (dn == 2) {
            for (int i = 0; i < m - dm; i += 2) {
                get(n - dn, i);
            }
        } else {
            for (int i = 0; i < m - dm; ++i) {
                get3(n - dn, i);
            }
        }
        if (dn == 2) {
            if (dm == 2) {
                get(n - dn, m - dm);
            } else {
                get2(n - 2, m - dm);
                get2(n - 1, m - dm);
            }
        } else {
            for (int i = m - dm; i < m; ++i) {
                get3(n - dn, i);
            }
        }
        int k = ans.size();
        assert(k <= n * m);
        cout << k << endl;
        for (auto elem : ans) {
            for (int i = 0; i < 6; ++i) {
                cout << elem[i] + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}