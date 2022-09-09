#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 1005, bd = 10;

int n, m;
int field[MAXN][MAXN];
int d[MAXN][MAXN];
int sparse[bd][bd][MAXN][MAXN];
int arr[MAXN];

int get(int x1, int y1, int x2, int y2) {
    int c1 = arr[x2 - x1];
    int c2 = arr[y2 - y1];
    return max(max(sparse[c1][c2][x1][y1], sparse[c1][c2][x2 - (1 << c1)][y1]), 
               max(sparse[c1][c2][x1][y2 - (1 << c2)], sparse[c1][c2][x2 - (1 << c1)][y2 - (1 << c2)]));
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    for (int i = 1; i < MAXN; ++i) {
        arr[i] = arr[i - 1];
        if ((1 << (arr[i] + 1)) <= i) {
            ++arr[i];
        }
    }

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &field[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!field[i][j]) {
                continue;
            }
            d[i + 1][j + 1] = min(d[i + 1][j], d[i][j + 1]);
            int sz = d[i + 1][j + 1];
            if (field[i - sz][j - sz]) {
                ++d[i + 1][j + 1];
            }
        }
    }

    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cerr << d[i][j] << " ";
        }
        cerr << endl;
    }*/

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sparse[0][0][i][j] = d[i + 1][j + 1];
        }
    }
    
    for (int i = 0; i < bd; ++i) {
        for (int j = 0; j < bd; ++j) {
            if (!i && !j) {
                continue;
            }
            for (int x = 0; x <= n - (1 << i); ++x) {
                for (int y = 0; y <= m - (1 << j); ++y) {
                    if (!i) {
                        sparse[i][j][x][y] = max(sparse[i][j - 1][x][y], sparse[i][j - 1][x][y + (1 << (j - 1))]);
                    } else {
                        sparse[i][j][x][y] = max(sparse[i - 1][j][x][y], sparse[i - 1][j][x + (1 << (i - 1))][y]);
                    }
                }
            }
        }
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        --x1; --y1;
        int l = 0, r = min(x2 - x1, y2 - y1) + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (get(x1 + mid - 1, y1 + mid - 1, x2, y2) >= mid) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}