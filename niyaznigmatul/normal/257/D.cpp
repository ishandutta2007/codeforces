#include <cstdio>


int a[123456], b[123456];

int main() {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d", a + i);
     int cur = a[n - 1];
     for (int i = n - 2; i >= 0; i--) {
        if (cur > 0) {
            b[i] = 1;
            cur -= a[i];
        } else {
            cur += a[i];
        }
     }
     if (cur < 0) {
        for (int i = 0; i < n; i++) b[i] = !b[i];
     }
     for (int i = 0; i < n; i++) putchar("+-"[b[i]]);
     puts("");
}