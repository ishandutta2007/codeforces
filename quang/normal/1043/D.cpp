#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 20;

int n, m;
int a[M][N];
int pos[M][N];

bool check(int u, int v) {
    for (int i = 1; i <= m; i++) {
        if (pos[i][u] + 1 != pos[i][v]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", a[i] + j);
            pos[i][a[i][j]] = j;
        }
    }
    long long res = 1;
    int len = 1;
    for (int i = 2; i <= n; i++) {
        if (check(a[1][i - 1], a[1][i])) {
            len++;
        } else {
            len = 1;
        }
        res += len;
    }
    cout << res << endl;
    return 0;
}