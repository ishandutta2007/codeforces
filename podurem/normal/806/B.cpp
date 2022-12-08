#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stderr)

const int dd = (int)120 + 7;

int cnt[6], C, n;
int X[6] = { 2, 4, 8, 16, 32, 64 };
int P[5];
int CC[6] = { 500, 1000, 1500, 2000, 2500, 3000 };
int A[dd][5];

void go(int i) {
    if (i == 5) {
        double A1 = 0, A2 = 0;
        for (int j = 0; j < 5; ++j) if (A[0][j] != -1)
            A1 += CC[P[j]] * (1.0 - 1.0 * A[0][j] / 250);
        for (int j = 0; j < 5; ++j) if (A[1][j] != -1)
            A2 += CC[P[j]] * (1.0 - 1.0 * A[1][j] / 250);
        if (A1 > A2)
            exit(0 * printf("%d", C - n));
        return;
    }
    for (int ii = 0; ii < 6; ++ii) {
        int nl;
        if (ii < 5) nl = (C - cnt[i] * X[ii] + X[ii] * 300) / X[ii] - 299;
        else nl = 0;
        int nr = (2 * C - cnt[i] * X[ii] + X[ii] * 300) / X[ii] - 300;
        P[i] = ii;
        if ((nl <= 0 || A[0][i] != -1) && nl <= C - n && nr >= 0 && nl <= nr) go(i + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < 5; ++j) {
        scanf("%d", &A[i][j]);
        if (A[i][j] != -1)
            cnt[j]++;
    }
    for (int add = 0; add < 3721; ++add) {
        C = n + add;
        go(0);
    }
    puts("-1");
    return 0;
}