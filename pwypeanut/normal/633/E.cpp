#include <bits/stdc++.h>
using namespace std;

int N, K, v[1000005], c[1000005], stv[1000005][21], stc[1000005][21], ans[1000005];
double fac[1000005];

int qv(int l, int r) {
    if (r >= N) r = N - 1;
    int len = r - l + 1;
    for (int i = 20; i >= 0; i--) {
        if ((1 << i) <= len) {
            return max(stv[l][i], stv[r - (1 << i) + 1][i]) * 100;
        }
    }
}

int qc(int l, int r) {
    if (r >= N) r = N - 1;
    int len = r - l + 1;
    for (int i = 20; i >= 0; i--) {
        if ((1 << i) <= len) {
            return min(stc[l][i], stc[r - (1 << i) + 1][i]);
        }
    }
}

double choose(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    else return fac[n] / fac[k] / fac[n - k];
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &v[i]);
    for (int i = 0; i < N; i++) scanf("%d", &c[i]);
    for (int i = 0; i < N; i++) stv[i][0] = v[i];
    for (int i = 0; i < N; i++) stc[i][0] = c[i];
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j <= N - (1 << i); j++) {
            stv[j][i] = max(stv[j][i - 1], stv[j + (1 << (i - 1))][i - 1]);
            stc[j][i] = min(stc[j][i - 1], stc[j + (1 << (i - 1))][i - 1]);
        }
    }
    for (int i = 0; i < N; i++) {
        int bot = i, top = N, mid;
        while (bot + 1 < top) {
            mid = (bot + top) / 2;
            if (qv(i, mid) <= qc(i, mid)) bot = mid;
            else top = mid;
        }
        ans[i] = min(qv(i, bot), qc(i, bot));
        ans[i] = max(ans[i], min(qv(i, bot + 1), qc(i, bot + 1)));
    }
    sort(ans, ans + N);
    double a = 1;
    for (int i = 1; i <= 1000000; i++) {
        a *= i;
        fac[i] = a;
    }
    double an = 0, prob = (double)K / N;
    for (int i = 0; i < N; i++) {
        if (N - i - 1 < K - 1) break;
        an += prob * ans[i];
        if (N - i - 1 > 0) prob *= (1.00 - (double)(K - 1) / (N - i - 1));
        //an += choose(N - i - 1, K - 1) * ans[i];
    }
   // an /= choose(N, K);
    printf("%.8lf\n", an);
}