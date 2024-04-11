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
const int MAXN = 200;

int n;
int field[2][MAXN * 2][MAXN * 2];

void mark(int q, int x, int y, int val) {
    if (0 <= x && x < MAXN * 2 && 0 <= y && y < MAXN * 2) {
        field[q][x][y] |= val;
    }
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);
    vector<int> inp;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        inp.puba(num);
    }

    inp.resize(100, 0);

    int flag = 0;
    for (int i = 30; i >= 0; i -= 2) {
        for (int x = 0; x < MAXN * 2; ++x) {
            for (int y = 0; y < MAXN * 2; ++y) {
                field[flag][x][y] = 0;
            }
        }
        int nx = MAXN, ny = MAXN;
        for (int j = 0; j < inp[i]; ++j) {
            field[flag][nx][ny] = 1;
            nx += 1;
        }
        --nx;
        for (int k = 0; k < inp[i + 1]; ++k) {
            field[flag][nx + k + 1][ny + k + 1] = 1;
            field[flag][nx + k + 1][ny - k - 1] = 1;
        }
        
        int k = inp[i + 1];
        for (int x = -MAXN; x < MAXN; ++x) {
            for (int y = -MAXN; y < MAXN; ++y) {
                //cerr << field[!(flag)][x + MAXN][y + MAXN];
                mark(flag, nx + k + 1 + x, ny + k + y, field[!(flag)][x + MAXN][y + MAXN]);
                mark(flag, nx + k + y, ny + k + 1 + x, field[!(flag)][x + MAXN][y + MAXN]);

                mark(flag, nx + k + 1 + x, ny - k + y, field[!(flag)][x + MAXN][y + MAXN]);
                mark(flag, nx + k + y, ny - k - 1 - x, field[!(flag)][x + MAXN][y + MAXN]);
            }
            //cerr << endl;
        }
        flag ^= 1;
    }

    flag ^= 1;

    int res = 0;

    for (int i = 0; i < MAXN * 2; ++i) {
        for (int j = 0; j < MAXN * 2; ++j) {
            res += field[flag][i][j];
            //cerr << field[flag][i][j];
        }
        //cerr << endl;
    }

    cout << res << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}