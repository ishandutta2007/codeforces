#include <bits/stdc++.h>

using namespace std;

const int MAX_R = 60 + 5;

int T, R, C;
char a[MAX_R][MAX_R];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &R, &C);
        for (int i = 1; i <= R; i ++) {
            scanf("%s", a[i] + 1);
        }

        //0 or 5
        int cnt = 0;
        for (int i = 1; i <= R; i ++) {
            for (int j = 1; j <= C; j ++) {
                cnt += a[i][j] == 'A';
            }
        }
        if (cnt == 0) {
            printf("MORTAL\n");
            continue;
        }
        if (cnt == R * C) {
            printf("0\n");
            continue;
        }

        //1
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= R; i ++) {
            c1 += a[i][1] == 'A';
            c2 += a[i][C] == 'A';
        }
        if (c1 == R || c2 == R) {
            printf("1\n");
            continue;
        }
        int c3 = 0, c4 = 0;
        for (int i = 1; i <= C; i ++) {
            c3 += a[1][i] == 'A';
            c4 += a[R][i] == 'A';
        }
        if (c3 == C || c4 == C) {
            printf("1\n");
            continue;
        }
        
        //2
        if (a[1][1] == 'A' || a[1][C] == 'A' || a[R][1] == 'A' || a[R][C] == 'A') {
            printf("2\n");
            continue;
        }
        bool ok_2 = false;
        for (int i = 1; i <= R; i ++) {
            int c = 0;
            for (int j = 1; j <= C; j ++) {
                c += a[i][j] == 'A';
            }
            if (c == C) {
                ok_2 = true;
                break;
            }
        }
        if (ok_2) {
            printf("2\n");
            continue;
        }
        for (int j = 1; j <= C; j ++) {
            int c = 0;
            for (int i = 1; i <= R; i ++) {
                c += a[i][j] == 'A';
            }
            if (c == R) {
                ok_2 = true;
                break;
            }
        }
        if (ok_2) {
            printf("2\n");
            continue;
        }



        //3 or 4
        if (c1 || c2 || c3 || c4) {
            printf("3\n");
        } else {
            printf("4\n");
        }
    }
    return 0;
}