#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
char a[N][N];
bool used[N][N];

bool canDo(int u, int v) {
    if (a[u - 1][v - 1] == '#' &&
        a[u - 1][v] == '#' &&
        a[u - 1][v + 1] == '#' &&
        a[u][v - 1] == '#' &&
        a[u][v + 1] == '#' &&
        a[u + 1][v - 1] == '#' &&
        a[u + 1][v] == '#' &&
        a[u + 1][v + 1] == '#'
    ) return 1;
    return 0;
}

void doIt(int u, int v) {
        used[u - 1][v - 1] = 1;
        used[u - 1][v] = 1;
        used[u - 1][v + 1] = 1;
        used[u][v - 1] = 1;
        used[u][v + 1] = 1;
        used[u + 1][v - 1] = 1;
        used[u + 1][v] = 1;
        used[u + 1][v + 1] =  1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            if (canDo(i, j)) {
                doIt(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (used[i][j]) {
                if (a[i][j] != '#') {
                    puts("NO");
                    return 0;
                }
            } else {
                if (a[i][j] == '#') {
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    puts("YES");
    return 0;
}