#include <bits/stdc++.h>
    
int const N = 42;

    int p1[N], p2[N], row[N], col[N], mind[N], from[N], was[N];
    int a[N][N], b[N][N], c[N][N];
    int n;
    int nn;
    
    void getMatching() {
        for (int i = 0; i < n; i++) {
            if ((nn >> i) & 1) {
                p2[p1[i]] = -1;
                p1[i] = -1;
                int allMin = 1 << 30;
                for (int j = 0; j < n; j++) {
                    allMin = std::min(allMin, a[i][j] - col[j]);
                }
                row[i] = allMin;
            }
        }
        for (int i = 0; i < n; i++) {
            if (p1[i] >= 0) {
                continue;
            }
            std::fill(was, was + n, 0);
            std::fill(mind, mind + n, 1 << 30);
            int cur = i;
            int curPair = -1;
            do {
                if (curPair >= 0) {
                    was[curPair] = true;
                    cur = p2[curPair];
                }
                int d = 1 << 30;
                int minPair = -1;
                for (int j = 0; j < n; j++) {
                    if (was[j]) {
                        continue;
                    }
                    int val = a[cur][j] - row[cur] - col[j];
                    if (val < mind[j]) {
                        mind[j] = val;
                        from[j] = curPair;
                    }
                    if (mind[j] < d) {
                        d = mind[j];
                        minPair = j;
                    }
                }
                row[i] += d;
                for (int j = 0; j < n; j++) {
                    if (was[j]) {
                        col[j] -= d;
                        row[p2[j]] += d;
                    } else {
                        mind[j] -= d;
                    }
                }
                curPair = minPair;
            } while (p2[curPair] >= 0);
            while (from[curPair] >= 0) {
                int prev = from[curPair];
                p2[curPair] = p2[prev];
                p1[p2[prev]] = curPair;
                curPair = prev;
            }
            p2[curPair] = i;
            p1[i] = curPair;
        }
    }

    int main() {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", c[i] + j);
                c[i][j] = -c[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", b[i] + j);
                b[i][j] = -b[i][j];
            }
        }
        std::fill(p1, p1 + n, -1);
        std::fill(p2, p2 + n, -1);
        int ans = 1 << 30;
        int lastmask = -1;
        for (int mask = 0; mask < 1 << n; mask++) {
            if (__builtin_popcount(mask) != n / 2) continue;
            if (lastmask >= 0) {
                nn = lastmask ^ mask;
            } else nn = -1;
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 0) {
                    for (int j = 0; j < n; j++) a[i][j] = b[i][j];
                } else {
                    for (int j = 0; j < n; j++) a[i][j] = c[i][j];
                }
            }
            getMatching();
            int sum = 0;
            for (int i = 0; i < n; i++) sum += a[i][p1[i]];
            ans = std::min(ans, sum);
            lastmask = mask;
        }
        printf("%d\n", -ans);
    }