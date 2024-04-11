#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int SZ = 22;
const ll MOD = 1e9 + 7;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct matrix {
    int m[SZ][SZ];
    matrix() {
        memset(m, 0, sizeof m);        
    }

    matrix operator*(matrix m1) {
        matrix ret;
        for (int i = 0; i < SZ; ++i) {
            for (int j = 0; j < SZ; ++j) {
                ll now = 0;
                for (int k = 0; k < SZ; ++k) {
                    now = (now + (ll) m[i][k] * m1.m[k][j]) % MOD;
                }
                ret.m[i][j] = now;
            }
        }
        return ret;
    }
};

matrix ONE;

matrix m_pow(matrix m, int a) {
    if (a == 0) {
        return ONE;
    }
    matrix ret = m_pow(m, a / 2);
    ret = ret * ret;
    if (a & 1) {
        ret = ret * m;
    }
    return ret;
}

int n, m, q;
int cond[20][20];

int main() {
    for (int i = 0; i < SZ; ++i) {
        ONE.m[i][i] = 1;
    }
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d%d", &n, &m, &q);

    int prev = 1;
    matrix situation = ONE;    
    situation.m[0][0] = 1;
    matrix step;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            step.m[i * m + j][i * m + j] = 1;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    step.m[i * m + j][nx * m + ny] = 1;
                }
            }
        }
    }
    
    

    for (int i = 0; i < q; ++i) {
        int type, x, y, t;
        scanf("%d%d%d%d", &type, &x, &y, &t);
        --x;--y;
        if (type == 2) {
            situation = situation * m_pow(step, t - prev);
            step.m[x * m + y][x * m + y] = 0;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    step.m[x * m + y][nx * m + ny] = 0;
                    step.m[nx * m + ny][x * m + y] = 0;
                }
            }
            situation.m[x][y] = 0;
            cond[x][y] = 1;
            prev = t;
        } else if (type == 3) {
            situation = situation * m_pow(step, t - prev);
            step.m[x * m + y][x * m + y] = 1;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && !cond[nx][ny]) {
                    step.m[x * m + y][nx * m + ny] = 1;
                    step.m[nx * m + ny][x * m + y] = 1;
                }
            }
            cond[x][y] = 0;
            prev = t;
        } else {
            situation = situation * m_pow(step, t - prev);            
            cout << situation.m[0][x * m + y] << "\n";
            prev = t;
        }
        /*
        cerr << "step:\n";
        for (int i = 0; i < n * m; ++i) {
            for (int j = 0; j < n * m; ++j) {
                cerr << step.m[i][j] << " ";
            }
            cerr << endl;
        }
        cerr << "sit:\n";
        for (int i = 0; i < n * m; ++i) {
            for (int j = 0; j < n * m; ++j) {
                cerr << situation.m[i][j] << " ";
            }
            cerr << endl;
        }
        */
    }

    return 0;
}