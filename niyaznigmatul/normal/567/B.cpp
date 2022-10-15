#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;

int type[N], was[N], need[N], a[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int c = getchar();
        while (c <= 32) c = getchar();
        type[i] = c == '-' ? -1 : 1;
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
        if (!was[a[i]] && type[i] < 0) {
            need[i] = true;
        }
        if (type[i] > 0) was[a[i]] = true; else was[a[i]] = false;
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (need[i]) {
            was[a[i]] = true;
            ++c;
        }
    }
    int ans = c;
    for (int i = 0; i < n; i++) {
        if (type[i] > 0) {
            ++c;
        } else {
            --c;
        }
        ans = max(ans, c);
    }
    printf("%d\n", ans);
}