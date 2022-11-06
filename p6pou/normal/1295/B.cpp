#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000 + 5;

int T, N, x;
char s[MAX_N];
int c[MAX_N << 1];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &N, &x);
        scanf("%s", s + 1);
        int k = 0, k0 = N, k1 = -N;
        for (int i = 1; i <= N; i ++) {
            c[N + k] ++;
            k0 = k0 > k ? k : k0;
            k1 = k1 < k ? k : k1;
            k += s[i] == '0' ? 1 : -1;
        }
        // printf("k=%d,k0=%d,k1=%d\n", k, k0, k1);
        if (k == 0) {
            if (x < k0 || x > k1) {
                printf("0\n");
            } else {
                printf("-1\n");
            }
        } else if (k > 0) {
            if (x > k1) {
                x = (x - k1) % k + k1;
                x -= x > k1 ? k : 0;
            }
            int ans = 0;
            while (x >= k0) {
                ans += c[N + x];
                x -= k;
            }
            printf("%d\n", ans);
        } else {
            if (x < k0) {
                x = (x - k0) % k + k0;
                x += x < k0 ? -k : 0;
            }
            int ans = 0;
            while (x <= k1) {
                ans += c[N + x];
                x += -k;
            }
            printf("%d\n", ans);
        }
        for (int i = 0; i <= N + N; i ++) {
            c[i] = 0;
        }
    }
    return 0;
}