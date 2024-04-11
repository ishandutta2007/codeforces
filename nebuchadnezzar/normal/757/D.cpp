#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 80;
const ll MOD = 1e9 + 7;
const int MAXV = 1 << 20;

int n;
char s[MAXN];
int d[MAXN][MAXV];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);
    scanf("%s", s);

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        d[i + 1][0] = 1;
        int cur = 0;
        int bp = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (s[j] == '1') {
                if (bp > 10) {
                    break;
                }
                cur += 1 << bp;
                if (cur > 20) {
                    break;
                }
            }
            if (cur) {
                int q = 1 << (cur - 1);
                //cerr << i << " " << j << " " << cur << endl;
                if (i - j <= 4) {
                    for (int k = 0; k < MAXV; ++k) {
                        d[i + 1][k | q] += d[j + 1][k];
                        if (d[i + 1][k | q] >= MOD) {
                            d[i + 1][k | q] -= MOD;
                        }
                    }
                } else {
                    int c = j - 1;
                    while (c >= 0 && s[c] == '0') {
                        --c;
                    }
                    ++c;
                    for (int k = 0; k < MAXV; ++k) {
                        d[i + 1][k | q] += d[j + 1][k] - d[c][k];
                        if (d[i + 1][k | q] < 0) {
                            d[i + 1][k | q] += MOD;
                        }
                        if (d[i + 1][k | q] >= MOD) {
                            d[i + 1][k | q] -= MOD;
                        }
                    }
                    break;
                }
            }
            ++bp;
        }
        if (i - 4 >= 0) {
            for (int j = 0; j < MAXV; ++j) {
                d[i - 3][j] += d[i - 4][j];
                if (d[i - 3][j] > MOD) {
                    d[i - 3][j] -= MOD;
                }
            }
        }
        for (int j = 1; j <= 20; ++j) {
            ans = (ans + d[i + 1][(1 << j) - 1]) % MOD;
        }
    }

    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cerr << d[i][j] << " ";
        }
        cerr << endl;
    }*/

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}