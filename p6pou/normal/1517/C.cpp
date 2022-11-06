#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500 + 5;

int N;
int a[MAX_N][MAX_N];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i][i]);
    }
    for (int i = 0; i < N; i ++) {
        int t = 0;
        for (int j = 1; j + i <= N; j ++) {
            if (a[j + i][j] == i + 1) {
                t = 1;
            } else if (t == 0) {
                a[j + i + 1][j] = a[j + i][j];
            } else {
                a[j + i][j - 1] = a[j + i][j];
            }
        }
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= i; j ++) {
            printf("%d%c", a[i][j], j < i ? ' ' : '\n');
        }
    }
    return 0;
}