#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 400000 + 5;
const int P = 1000000007;

int T, N, a[MAX_N], b[MAX_N];

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        for (int i = 1, x; i <= N; i ++) {
            scanf("%d", &x), a[x] = i;
        }
        for (int i = 1, x; i <= N; i ++) {
            scanf("%d", &x), b[i] = a[x];
        }
        int ans = 1;
        for (int i = 1; i <= N; i ++) {
            if (!b[i]) continue;
            ans <<= 1, ans -= ans >= P ? P : 0;
            for (int j = b[i], k; j != i; k = b[j], b[j] = 0, j = k);
        }
        printf("%d\n", ans);
    }
    return 0;
}