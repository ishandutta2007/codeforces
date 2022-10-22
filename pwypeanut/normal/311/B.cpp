#include <bits/stdc++.h>
using namespace std;

// f(x, p) = f(i, p - 1) + T[x] * (x - i) - pre[x - 1] + pre[i - 1]

int N, M, P, D[100005], H[100005], T[100005];
long long pre[100005], offset;
long long dp[105][100005];

void compute(int l, int s, int e, int x, int y) {
    if (s > e) return;
    int m = (s + e) / 2;
    long long best = 1000000000000000000ll;
    int pos = -1;
    for (int i = x; i <= min(y, m); i++) {
        long long cur = dp[l-1][i] + (long long)((m == 0) ? 0 : T[m - 1]) * (m - i) - ((m == 0) ? 0 : pre[m - 1]) + ((i == 0) ? 0 : pre[i - 1]);
        if (cur < best) {
            best = cur;
            pos = i;
        }
    }
    assert(pos != -1);
    dp[l][m] = best;
    compute(l, s, m-1, x, pos);
    compute(l, m+1, e, pos, y);
}

int main() {//freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &N, &M, &P);
    for (int i = 1; i < N; i++) scanf("%d", &D[i]);
    for (int i = 0; i < M; i++) scanf("%d%d", &H[i], &T[i]);
    for (int i = 1; i < N; i++) D[i] += D[i-1];
    for (int i = 0; i < M; i++) T[i] -= D[H[i] - 1];
    sort(T, T + M);
    pre[0] = T[0];
    for (int i = 1; i < M; i++) pre[i] = pre[i-1] + T[i];
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= P; i++) {
        compute(i, 0, M, 0, M);
    }
    cout << dp[P][M] << endl;
}