#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300000 + 5;

int T, N;
char a[MAX_N], b[MAX_N], c[MAX_N], s[MAX_N];

void gen(char A[], char B[], char x) {
    for (int i = 1, j = 1, k = 1; j <= N * 2 || k <= N * 2; i ++) {
        if (j > N * 2) {
            s[i] = B[k];
        } else if (k > N * 2) {
            s[i] = A[j];
        } else if (A[j] == x && B[k] == x) {
            s[i] = x;
        } else {
            s[i] = x ^ 1;
        }
        j += A[j] == s[i];
        k += B[k] == s[i];
    }
}
int main() {
    scanf("%d", &T);
    for (; T --; ) {
        scanf("%d%s%s%s", &N, a + 1, b + 1, c + 1);
        N = strlen(a + 1) >> 1;
        int sa = 0, sb = 0, sc = 0;
        for (int i = 1; i <= N * 2; i ++) {
            sa += a[i] - '0';
            sb += b[i] - '0';
            sc += c[i] - '0';
        }
        if (sa <= N) {
            if (sb <= N) {
                gen(a, b, '0');
            } else if (sc <= N) {
                gen(a, c, '0');
            } else {
                gen(b, c, '1');
            }
        } else {
            if (sb > N) {
                gen(a, b, '1');
            } else if (sc > N) {
                gen(a, c, '1');
            } else {
                gen(b, c, '0');
            }
        }
        printf("%s\n", s + 1);

        for (int i = 1; i <= N * 3; i ++) {
            a[i] = b[i] = c[i] = s[i] = 0;
        }
    }
    return 0;
}