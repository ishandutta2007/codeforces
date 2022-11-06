#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10000 + 5;

int T, N, a[MAX_N], b[MAX_N];

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
            b[i] = max(b[i - 1], a[i]);
        }
        int c = a[N], ok = 0;
        for (int i = N - 1; i >= 1; i --) {
            if (c < b[i]) ok = 1;
            c = min(c, a[i]);
        }
        printf(ok ? "YES\n" : "NO\n");
    }
    return 0;
}