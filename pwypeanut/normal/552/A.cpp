#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ans += ((long long)c - a + 1) * (d - b + 1);
    }
    printf("%I64d\n", ans);
}