#include <bits/stdc++.h>

using namespace std;

int N;
int sx, sy;
int c[8];

int main() {
    scanf("%d%d%d", &N, &sx, &sy);
    for (int i = 1; i <= N; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < sx) {
            if (y < sy) {
                c[0] ++;
            } else if (y == sy) {
                c[1] ++;
            } else {
                c[2] ++;
            }
        } else if (x == sx) {
            if (y < sy) {
                c[3] ++;
            } else {
                c[4] ++;
            }
        } else {
            if (y < sy) {
                c[5] ++;
            } else if (y == sy) {
                c[6] ++;
            } else {
                c[7] ++;
            }
        }
    }
    int ans1 = c[0] + c[1] + c[2];
    int ans3 = c[0] + c[3] + c[5];
    int ans4 = c[2] + c[4] + c[7];
    int ans6 = c[5] + c[6] + c[7];
    int ans = max(max(ans1, ans3), max(ans4, ans6));
    printf("%d\n", ans);
    // printf("%d %d %d %d\n", ans1, ans3, ans4, ans6);
    if (ans1 == ans) {
        printf("%d %d\n", sx - 1, sy);
    } else if (ans3 == ans) {
        printf("%d %d\n", sx, sy - 1);
    } else if (ans4 == ans) {
        printf("%d %d\n", sx, sy + 1);
    } else {
        printf("%d %d\n", sx + 1, sy);
    }
    return 0;
}