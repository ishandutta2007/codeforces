#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1005;

int d[2][15][MAXN][MAXN];
char s1[MAXN], s2[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s%s", s1, s2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s1[i] != s2[j]) {
                for (int j2 = 0; j2 < k; ++j2) {
                    d[1][j2 + 1][i + 1][j + 1] = max(d[1][j2 + 1][i][j + 1], d[1][j2 + 1][i + 1][j]);
                }
                continue;
            }
            for (int j2 = 0; j2 < k; ++j2) {
                d[0][j2 + 1][i + 1][j + 1] = max(d[1][j2][i][j] + 1, d[0][j2 + 1][i][j] + 1);
                d[1][j2 + 1][i + 1][j + 1] = max(d[0][j2 + 1][i + 1][j + 1], max(d[1][j2 + 1][i][j + 1], d[1][j2 + 1][i + 1][j]));
            }
        }
    }

    //cerr << d[1][1][1][4] << endl;

    cout << d[1][k][n][m] << "\n";

    return 0;
}