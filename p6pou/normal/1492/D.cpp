#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;

char a[MAX_N], b[MAX_N];

int main() {
    int A, B, K;
    scanf("%d%d%d", &A, &B, &K);
    if (K == 0) {
        for (int i = 1; i <= B; i ++) a[i] = '1';
        for (int i = 1; i <= A; i ++) a[B + i] = '0';
        printf("Yes\n%s\n%s\n", a + 1, a + 1);
    } else if (B == 1 || A == 0 || K >= A + B - 1) {
        printf("No\n");
    } else {
        int N = A + B;
        a[1] = b[1] = '1';
        a[N] = '0';
        b[N] = '1';
        a[N - K] = '1';
        b[N - K] = '0';
        for (int i = 1, j = 3; i <= N; i ++) {
            if (!a[i]) a[i] = b[i] = j <= B ? '1' : '0', j ++;
        }
        printf("Yes\n%s\n%s\n", a + 1, b + 1);
    }
    return 0;
}