#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50 + 5;

int T, N, M;
char a[MAX_N][MAX_N];

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d%d", &N, &M);
        int r = 0, w = 0;
        for (int i = 1; i <= N; i ++) {
            scanf("%s", a[i] + 1);
            for (int j = 1; j <= M; j ++) {
                if (a[i][j] == 'R') r |= 1 << (i + j & 1);
                if (a[i][j] == 'W') w |= 1 << (i + j & 1);
            }
        }
        if (r == 3 || w == 3 || (r & w)) {
            printf("NO\n");
        } else {
            if (r + w == 0) r = 1;
            else if (!r) r = 3 ^ w;
            printf("YES\n");
            for (int i = 1; i <= N; i ++) {
                for (int j = 1; j <= M; j ++) {
                    printf("%c", r >> (i + j & 1) & 1 ? 'R' : 'W');
                }
                printf("\n");
            }
        }
    }
    return 0;
}