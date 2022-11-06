#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;
const int F = 300;

int N, A, a[MAX_N];
int X, p[MAX_N << 1];
int cnt[MAX_N];
int ans;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
        A = max(A, a[i]);
        cnt[a[i]] ++;
        if (cnt[X] < cnt[a[i]]) {
            X = a[i];
        }
    }
    if (cnt[X] == N) {
        printf("0\n");
        return 0;
    }
    for (int y = 1; y <= A; y ++) {
        if (y != X && cnt[y] > F) {
            for (int i = 0; i <= N * 2; i ++) {
                p[i] = N + 1;
            }
            p[N] = 0;
            int t = N;
            for (int i = 1; i <= N; i ++) {
                t += a[i] == X;
                t -= a[i] == y;
                ans = max(ans, i - p[t]);
                p[t] = min(p[t], i);
            }
        }
    }
    for (int f = 1; f <= F && f <= N >> 1; f ++) {
        for (int i = 1; i <= A; i ++) {
            cnt[i] = 0;
        }
        int t = 0;
        for (int r = 1, l = 1; r <= N; r ++) {
            for (; l <= r && cnt[a[r]] == f; l ++) {
                t -= cnt[a[l]] == f;
                cnt[a[l]] --;
            }
            cnt[a[r]] ++;
            t += cnt[a[r]] == f;
            if (t >= 2) {
                ans = max(ans, r - l + 1);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}