#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100 + 5;
const int MAX_S = 10000 + 5;

int T, N;
int S, P, C, D, A, B;
int a[MAX_N], b[MAX_N], c[MAX_N];
bitset<MAX_S> f;

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        S = 0, P = 0;
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
            P += a[i] * a[i];
            S += a[i];
        }
        C = 0;
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &b[i]);
            P += b[i] * b[i];
            S += b[i];
            c[i] = abs(a[i] - b[i]);
            C += c[i];
        }
        f.reset();
        f[0] = 1;
        for (int i = 1; i <= N; i ++) {
            f |= f << c[i];
        }
        for (int i = C >> 1; i >= 0; i --) {
            if (f[i]) {
                D = i;
                break;
            }
        }
        D = C - D * 2;
        A = S + D >> 1;
        B = S - D >> 1;
        P *= N - 2;
        P += A * A + B * B;
        printf("%d\n", P);
    }
    return 0;
}