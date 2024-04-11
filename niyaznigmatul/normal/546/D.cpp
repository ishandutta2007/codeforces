#include <bits/stdc++.h>

int const N = 5123456;

long long pr[N];

int main() {
    for (int i = 2; i < N; i++) {
        if (!pr[i]) {
            for (int j = i; j < N; j += i) {
                int f = j;
                while (f % i == 0) f /= i, pr[j]++;
            }
        }
    }
    for (int i = 2; i < N; i++) pr[i] += pr[i - 1];
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", pr[x] - pr[y]);
    }
}