#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 400000 + 5;

int T, N, a[MAX_N];
long long ans;

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
        }
        ans = a[0] = a[N + 1] = 0;
        for (int i = 1; i <= N; i ++) {
            int t = max(a[i - 1], a[i + 1]);
            if (a[i] > t) {
                ans += a[i] - t;
                a[i] = t;
            }
        }
        for (int i = 1; i <= N + 1; i ++) {
            ans += abs(a[i] - a[i - 1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}