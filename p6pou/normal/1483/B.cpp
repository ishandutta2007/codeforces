#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000 + 5;

int T, N;
int a[MAX_N], al[MAX_N], ar[MAX_N];
set<int> p;
int K, ans[MAX_N];

inline int gcd(int x, int y) {
    for (register int t; y; t = x, x = y, y = t % y);
    return x;
}

int main() {
    scanf("%d", &T);
    for (; T --; ) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
            al[i] = i > 1 ? i - 1 : N;
            ar[i] = i < N ? i + 1 : 1;
        }
        for (int i = 1; i <= N; i ++) {
            if (gcd(a[al[i]], a[i]) == 1) {
                p.insert(i);
            }
        }
        int k = 1;
        while (N > 1 && (int)p.size()) {
            k = ar[k];
            auto it = p.lower_bound(k);
            if (it == p.end()) it = p.begin();
            int i = *it;
            p.erase(i);
            if (p.count(ar[i])) p.erase(ar[i]);
            if (gcd(a[al[i]], a[ar[i]]) == 1) p.insert(ar[i]);
            ar[al[i]] = ar[i];
            al[ar[i]] = al[i];
            k = ar[i];
            N --, ans[++ K] = i;

            // printf("a: ");
            // i = k;
            // do {
            //     printf("%d ", a[i]);
            //     i = ar[i];
            // } while (i != k);
            // printf("\n");
        }
        if (N == 1 && a[k] == 1) ans[++ K] = k;
        printf("%d ", K);
        for (int i = 1; i <= K; i ++) {
            printf("%d%c", ans[i], i < K ? ' ' : '\n');
        }
        K = 0, p.clear();
    }
    return 0;
}