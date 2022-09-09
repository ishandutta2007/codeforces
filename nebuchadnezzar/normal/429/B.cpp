#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second

using namespace std;
const int MAXN = 1005;

int n, m;
long long w[MAXN][MAXN];
long long din[4][MAXN][MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> w[i][j];
            /*
            din[0][i][j] = w[i][j];
            din[1][i][j] = w[i][j];
            din[2][i][j] = w[i][j];
            din[3][i][j] = w[i][j];
            */
        }
    } 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                din[0][i][j] = w[i][j];
            }
            if (i > 0) {
                din[0][i][j] = max(din[0][i][j], din[0][i - 1][j] + w[i][j]);
            }
            if (j > 0) {
                din[0][i][j] = max(din[0][i][j], din[0][i][j - 1] + w[i][j]);
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (i == n - 1 && j == 0) {
                din[1][i][j] = w[i][j];
            }
            if (i < n - 1) {
                din[1][i][j] = max(din[1][i][j], din[1][i + 1][j] + w[i][j]);
            }
            if (j > 0) {
                din[1][i][j] = max(din[1][i][j], din[1][i][j - 1] + w[i][j]);
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i == n - 1 && j == m - 1) {
                din[2][i][j] = w[i][j];
            }
            if (i < n - 1) {
                din[2][i][j] = max(din[2][i][j], din[2][i + 1][j] + w[i][j]);
            }
            if (j < m - 1) {
                din[2][i][j] = max(din[2][i][j], din[2][i][j + 1] + w[i][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i == 0 && j == m - 1) {
                din[3][i][j] = w[i][j];
            }
            if (i > 0) {
                din[3][i][j] = max(din[3][i][j], din[3][i - 1][j] + w[i][j]);
            }
            if (j < m - 1) {
                din[3][i][j] = max(din[3][i][j], din[3][i][j + 1] + w[i][j]);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (0 < i && i < n - 1 && 0 < j && j < m - 1) {
                //cout << i << " " << j << " " << din[1][i - 1][j] << endl;
                ans = max(ans, max(din[0][i - 1][j] + din[1][i][j - 1] + din[2][i + 1][j] + din[3][i][j + 1], din[0][i][j - 1] + din[1][i + 1][j] + din[2][i][j + 1] + din[3][i - 1][j]));
            }
        }
    }
    cout << ans << endl;
    return 0;
}