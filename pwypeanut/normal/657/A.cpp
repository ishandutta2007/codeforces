#include <bits/stdc++.h>
using namespace std;

int N, D, H;

int main() {
    scanf("%d%d%d", &N, &D, &H);
    if (D == 1) {
        if (N != 2 || H != 1) {
            printf("-1\n");
            return 0;
        } else {
            printf("1 2\n");
            return 0;
        }
    } else if (D == H) {
        for (int i = 1; i <= H; i++) printf("%d %d\n", i, i + 1);
        for (int i = H + 2; i <= N; i++) printf("%d %d\n", H, i);
    } else {
        if (D > 2 * H) {
            printf("-1\n");
            return 0;
        }
        for (int i = 1; i <= H; i++) printf("%d %d\n", i, i + 1);
        printf("%d %d\n", 1, H + 2);
        for (int i = H + 2; i <= D; i++) printf("%d %d\n", i, i + 1);
        for (int i = D + 2; i <= N; i++) printf("1 %d\n", i);
    }
}