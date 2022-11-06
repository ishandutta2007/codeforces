#include <bits/stdc++.h>

using namespace std;

int main() {
    long long T, N, ans;
    scanf("%lld", &T);
    for (; T --; ) {
        scanf("%lld", &N);
        if (N % 2050) {
            printf("-1\n");
        } else {
            N /= 2050, ans = 0;
            for (; N; ans += N % 10, N /= 10);
            printf("%lld\n", ans);
        }
    }
    return 0;
}