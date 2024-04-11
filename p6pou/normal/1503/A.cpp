#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;

int T, N;
char s[MAX_N], a[MAX_N], b[MAX_N];
int fa[MAX_N], fb[MAX_N];

void solve() {
    int x = 0, y = 0;
    for (int i = N; i >= 1; i --) {
        if (s[i] == '1') {
            fa[i] = ++ x;
            fb[i] = ++ y;
        } else {
            int t = x == y ? 1 : -1;
            fa[i] = x += t;
            fb[i] = y -= t;
        }
        // printf("i=%d fa=%d, fb=%d\n", i, fa[i], fb[i]);
        if (x < 0 || y < 0) {
            printf("NO\n");
            return;
        }
    }
    x = 0, y = 0;
    for (int i = 1; i <= N; i ++) {
        // printf("i=%d, x=%d, y=%d\n", i, x, y);
        if (x < 0 || y < 0 || x > fa[i] || y > fb[i]) {
            printf("NO\n");
            return;
        }
        if (s[i] == '1') {
            if (x == fa[i] || y == fb[i]) {
                a[i] = b[i] = ')';
                x --, y --;
            } else {
                a[i] = b[i] = '(';
                x ++, y ++;
            }
        } else {
            if (x + 1 > fa[i + 1]) {
                a[i] = ')', x --;
                b[i] = '(', y ++;
            } else if (y + 1 > fb[i + 1]) {
                a[i] = '(', x ++;
                b[i] = ')', y --;
            } else if (x > y) {
                a[i] = ')', x --;
                b[i] = '(', y ++;
            } else {
                a[i] = '(', x ++;
                b[i] = ')', y --;
            }
        }
    }
    printf("YES\n%s\n%s\n", a + 1, b + 1);
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%s", &N, s + 1);
        solve();
        for (int i = 0; i <= N; i ++) {
            s[i] = a[i] = b[i] = 0;
        }
    }
    return 0;
}