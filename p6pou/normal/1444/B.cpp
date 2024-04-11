#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300000 + 5;
const int P = 998244353;

int N, a[MAX_N];

int poewr_mod(int a, int b) {
    int c = 1;
    for (; b; b >>= 1) {
        c = b & 1 ? 1ll * c * a % P : c;
        a = 1ll * a * a % P;
    }
    return c;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N + N; i ++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + N + N);
    int x = 0, y = 1;
    for (int i = 1; i <= N; i ++) {
        x = (x + a[N + N + 1 - i] - a[i]) % P;
    }
    for (int i = 1; i <= N; i ++) {
        y = 1ll * y * i % P;
    }
    y = poewr_mod(y, P - 2);
    for (int i = 1; i <= N; i ++) {
        y = 1ll * y * (i + N) % P;
    }
    x = 1ll * x * y % P;
    printf("%d\n", x);
    return 0;
}