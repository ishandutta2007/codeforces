#include <cstdio>
#include <cassert>

const int dx[] = {-1, -1};
const int dy[] = {-1, 1};

inline int ni() {
    int c = getchar();
    while (c < '0' || c > '9') c = getchar();
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}

inline int abs(int x) {
    return x < 0 ? -x : x;
}

const int N = 1111;

long long b[N][N], left[N][N], right[N][N], diag[N][N][2], sum[N][N];
long long up[N], down[N];
int a[N][N];

inline long long gs(int x1, int x2, int y1, int y2) {
    --x2;
    --y2;
    long long ret = b[x2][y2];
    if (x1 > 0) ret -= b[x1 - 1][y2];
    if (y1 > 0) ret -= b[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) ret += b[x1 - 1][y1 - 1];
    return ret;
}

int main() {
    int n = ni();
    int m = ni();
    int k = ni();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = a[i][j] = ni();
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++) 
            b[i][j] += b[i][j - 1];
    for (int i = 1; i < n; i++) 
        for (int j = 0; j < m; j++)
            b[i][j] += b[i - 1][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < 2; dir++) {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (x >= i) continue;
                if (x < 0 || y < 0 || x >= n || y >= m) {
                    diag[i][j][dir] = a[i][j];
                } else {
                    diag[i][j][dir] = diag[x][y][dir] + a[i][j];
                    int xx = i + dx[dir] * k;
                    int yy = j + dy[dir] * k;
                    if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
                        
                    } else {
                        diag[i][j][dir] -= a[xx][yy];
                    }
                }
            }
        }
    }
    long long best = -1;
    int bi = -1;
    int bj = -1;
    for (int i = k - 1; i <= n - k; i++) {
        for (int j = k - 1; j <= m - k; j++) {
            if (i == k - 1 && j == k - 1) {
                left[i][j] = right[i][j] = down[i] = up[i] = sum[i][j] = 0;
                for (int x = i - k + 1; x <= i + k - 1; x++) {
                    for (int y = j - k + 1; y <= j + k - 1; y++) {
                        int dist = abs(x - i) + abs(y - j);
                        if (dist >= k) continue;
                        int val = a[x][y];
                        if (x >= i) down[i] += val;
                        if (x <= i) up[i] += val;
                        if (y <= j) {
                            left[i][j] += val;
                        }
                        if (y >= j) right[i][j] += val;
                        sum[i][j] += (long long) val * (k - dist);
                    }
                }
            } else if (j == k - 1) {
                down[i] = down[i - 1] + diag[i + k - 1][j][0] + diag[i + k - 1][j][1] - a[i + k - 1][j] - gs(i - 1, i, 0, k + k - 1);
                up[i] = up[i - 1] - diag[i - 1][j + k - 1][0] - diag[i - 1][j - k + 1][1] + a[i - k][j] + gs(i, i + 1, 0, k + k - 1);
                sum[i][j] = sum[i - 1][j] - up[i - 1] + down[i];
                left[i][j] = left[i - 1][j] - diag[i - 1][j - k + 1][1] + diag[i + k - 1][j][0];
                right[i][j] = right[i - 1][j] - diag[i - 1][j + k - 1][0] + diag[i + k - 1][j][1];
            } else {
                left[i][j] = left[i][j - 1] + gs(i - k + 1, i + k, j, j + 1) - diag[i + k - 1][j - 1][0] - diag[i][j - k][1] + a[i][j - k];
//                printf("%I64d %I64d %I64d\n", gs(i - k + 1, i + k, j, j + 1), diag[i + k - 1][j - 1][0], diag[i][j - k][1]);
                right[i][j] = right[i][j - 1] - gs(i - k + 1, i + k, j - 1, j) + diag[i][j + k - 1][0] + diag[i + k - 1][j][1] - a[i][j + k - 1];
                sum[i][j] = sum[i][j - 1] + right[i][j] - left[i][j - 1];
            }
            if (sum[i][j] > best) {
                best = sum[i][j];
                bi = i;
                bj = j;
            }
/*            long long ss = 0;
            for (int x = i - k + 1; x <= i + k - 1; x++) {
                for (int y = j - k + 1; y <= j + k - 1; y++) {
                    int dist = abs(x - i) + abs(y - j);
                    if (dist >= k) continue;
                    int val = a[x][y];
                    ss += (long long) val * (k - dist);
                }
            }
            assert(ss == sum[i][j]);*/
//            printf("%d %d %I64d %I64d %I64d\n", i, j, sum[i][j], left[i][j], right[i][j]);
        }
    }
    printf("%d %d\n", bi + 1, bj + 1);
}