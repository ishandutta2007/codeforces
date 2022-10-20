#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 1010;

int n, m;
int val[N][N], A[N][N], B[N][N], C[N][N], D[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> val[i][j];
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    memset(C, -1, sizeof(C));
    memset(D, -1, sizeof(D));
    A[1][0] = B[n][0] = C[n][m + 1] = D[1][m + 1] = 0;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        A[i][j] = val[i][j] + max(A[i - 1][j], A[i][j - 1]);
    for(int i = n; i; i--)
    for(int j = 1; j <= m; j++)
        B[i][j] = val[i][j] + max(B[i][j - 1], B[i + 1][j]);
    for(int i = n; i; i--)
    for(int j = m; j; j--)
        C[i][j] = val[i][j] + max(C[i][j + 1], C[i + 1][j]);
    for(int i = 1; i <= n; i++)
    for(int j = m; j; j--)
        D[i][j] = val[i][j] + max(D[i - 1][j], D[i][j + 1]);
    int res = -1;
    for(int i = 2; i < n; i++)
    for(int j = 2; j < m; j++) {
        res = max(res, A[i - 1][j] + B[i][j - 1] + C[i + 1][j] + D[i][j + 1]);
        res = max(res, A[i][j - 1] + B[i + 1][j] + C[i][j + 1] + D[i - 1][j]);
    }
    cout << res;
    return 0;
}