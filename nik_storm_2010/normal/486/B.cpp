#include <cstdio>

using namespace std;
const int N = 200;

int a[N][N], b[N][N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &b[i][j]);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (b[i][j] == 1) continue;
        for (int k = 0; k < m; k++) a[i][k] = 0;
        for (int k = 0; k < n; k++) a[k][j] = 0;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        int res = 0;
        for (int k = 0; k < m; k++) res |= a[i][k];
        for (int k = 0; k < n; k++) res |= a[k][j];
        if (res != b[i][j]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        printf("%d", a[i][j]);
        if (j + 1 == m) printf("\n"); else printf(" ");
    }
    return 0;
}