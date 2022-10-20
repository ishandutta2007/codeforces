#include <bits/stdc++.h>

using namespace std;

const int N = 70100;
const int M = 4e6;

int n;
char s[N][10];
int res[N], t[N];
int val[M], nxt[10][M], cnt;

int main() {
    scanf("%d", &n);
    for (int i =1 ; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= 9; l++) {
            int cur = 0;
            for (int r = l; r <= 9; r++) {
                int foo =  nxt[s[i][r] - '0'][cur];
                if (!foo) {
                    foo = ++cnt;
                    nxt[s[i][r] - '0'][cur] = foo;
                }
                cur = foo;
                if (val[cur] == 0 || val[cur] == i) {
                    val[cur] = i;
                } else {
                    val[cur] = -1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        res[i] = 100;
        for (int l = 1; l <= 9; l++) {
            int cur = 0;
            for (int r = l; r <= 9; r++) {
                int foo =  nxt[s[i][r] - '0'][cur];
                if (!foo) {
                    exit(1);
                }
                cur = foo;
                if (val[cur] == i && res[i] > r - l + 1) {
                    res[i] = r - l + 1;
                    t[i] = l;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < res[i]; j++) {
            putchar(s[i][j + t[i]]);
        }
        printf("\n");
    }
    return 0;
}