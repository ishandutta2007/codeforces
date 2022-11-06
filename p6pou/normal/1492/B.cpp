#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000 + 5;

int T, N;
int a[MAX_N], b[MAX_N], p[MAX_N];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
            b[i] = max(a[i], b[i - 1]);
            p[a[i]] = i;
        }
        for (int i = N; i >= 1; i = p[b[i]] - 1) {
            for (int j = p[b[i]]; j <= i; j ++) {
                printf("%d ", a[j]);
            }
        }
        printf("\n");
    }
    return 0;
}