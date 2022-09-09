#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 105;

int r, s, p;

double d[3][MAXN][MAXN][MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> r >> s >> p;

    for (int i = 0; i <= r; ++i) {
        for (int j = 0; j <= s; ++j) {
            for (int k = 0; k <= p; ++k) {
                if (j) {
                    if (i + k) {
                        for (int i2 = 0; i2 < 3; ++i2) {
                            d[i2][i][j][k] += (double) (i * j) / (i * j + j * k + i * k) * d[i2][i][j - 1][k];
                        }
                    } else {
                        d[1][i][j][k] = 1;
                    }
                }
                if (i) {
                    if (j + k) {
                        for (int i2 = 0; i2 < 3; ++i2) {
                            d[i2][i][j][k] += (double) (i * k) / (i * j + j * k + i * k) * d[i2][i - 1][j][k];
                        }
                    } else {
                        d[0][i][j][k] = 1;
                    }
                }
                if (k) {
                    if (i + j) {
                        for (int i2 = 0; i2 < 3; ++i2) {
                            d[i2][i][j][k] += (double) (j * k) / (i * j + j * k + i * k) * d[i2][i][j][k - 1];
                        }
                    } else {
                        d[2][i][j][k] = 1;
                    }
                }
            }
        }
    }

    printf("%.10lf %.10lf %.10lf\n", d[0][r][s][p], d[1][r][s][p], d[2][r][s][p]);

    return 0;
}