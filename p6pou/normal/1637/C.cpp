#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const int MAX_N = 100000 + 5;

int T, N, a[MAX_N];

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
        }
        i64 sum = 0;
        int cnt = 0, ma = 0;
        for (int i = 2; i < N; i ++) {
            sum += a[i];
            cnt += a[i] & 1;
            ma = max(ma, a[i]);
        }
        if (cnt == 0) {
            printf("%lld\n", sum >> 1);
        } else if (ma == 1 || N == 3) {
            printf("-1\n");
        } else {
            printf("%lld\n", sum + cnt >> 1);
        }
    }
    return 0;
}