#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1001;
constexpr int BIT = 10;

int P[MAX][MAX]; // prefix sum of input
int Sparse[BIT][BIT][MAX][MAX]; // sparse table of maximum square starting(top left) from (i, j)
int LOG2[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    LOG2[1] = 0;
    for (int i = 2; i < MAX; i++) {
        LOG2[i] = LOG2[i / 2] + 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> P[i][j];
            P[i][j] += P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (P[i][j] - P[i - 1][j] - P[i][j - 1] + P[i - 1][j - 1] == 0) {
                Sparse[0][0][i][j] = 0;
                continue;
            }
            for (int l = 0, r = min(N - i + 1, M - j + 1), mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
                int sum = P[i + mid - 1][j + mid - 1] - P[i + mid - 1][j - 1] - P[i - 1][j + mid - 1] + P[i - 1][j - 1];
                if (sum == mid * mid) {
                    Sparse[0][0][i][j] = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
    }

    for (int l = 1; l < BIT; l++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (j + (1 << (l - 1)) <= M) {
                    Sparse[0][l][i][j] = max(Sparse[0][l - 1][i][j], Sparse[0][l - 1][i][j + (1 << (l - 1))]);
                } else {
                    Sparse[0][l][i][j] = Sparse[0][l - 1][i][j];
                }
            }
        }
    }

    for (int k = 1; k < BIT; k++) {
        for (int l = 0; l < BIT; l++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (i + (1 << (k - 1)) <= N) {
                        Sparse[k][l][i][j] = max(Sparse[k - 1][l][i][j], Sparse[k - 1][l][i + (1 << (k - 1))][j]);
                    } else {
                        Sparse[k][l][i][j] = Sparse[k - 1][l][i][j];
                    }
                }
            }
        }
    }
    
    auto rmq = [&](int i1, int j1, int i2, int j2) { // range maximum query
        i2 = min(i2, N);
        j2 = min(j2, M);
        int logr = LOG2[i2 - i1 + 1];
        int logc = LOG2[j2 - j1 + 1];
        return max({
            Sparse[logr][logc][i1]                  [j1],
            Sparse[logr][logc][i2 - (1 << logr) + 1][j1],
            Sparse[logr][logc][i1]                  [j2 - (1 << logc) + 1],
            Sparse[logr][logc][i2 - (1 << logr) + 1][j2 - (1 << logc) + 1]
        });
    };

    int Q;
    cin >> Q;
    for (int qi = 0; qi < Q; qi++) {
        int x[2], y[2];
        for (int i = 0; i < 2; i++) {
            cin >> x[i] >> y[i];
        }
        int ans = 0;
        for (int l = 0, r = min(x[1] - x[0] + 1, y[1] - y[0] + 1), mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
            if (rmq(x[0], y[0], x[1] - mid + 1, y[1] - mid + 1) >= mid) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}