#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000 + 5;

int T, N, M;
vector<int> f[MAX_N];
int b[MAX_N], c[MAX_N];

int main() {
    scanf("%d", &T);
    for (; T --; ) {
        scanf("%d%d", &N, &M);
        for (int i = 1, k; i <= M; i ++) {
            scanf("%d", &k);
            for (int j = 1, x; j <= k; j ++) {
                scanf("%d", &x);
                f[i].push_back(x);
            }
            b[i] = f[i][0];
            c[b[i]] ++;
        }
        int k = 0;
        for (int i = 1; i <= N; i ++) {
            if (c[i] > M + 1 >> 1) {
                k = i;
                break;
            }
        }
        if (k) {
            for (int i = 1; i <= M && c[k] > M + 1 >> 1; i ++) {
                if (b[i] == k && (int) f[i].size() > 1) {
                    b[i] = f[i][1];
                    c[k] --;
                }
            }
        }
        if (c[k] <= M + 1 >> 1) {
            printf("YES\n");
            for (int i = 1; i <= M; i ++) {
                printf("%d%c", b[i], i < M ? ' ' : '\n');
            }
        } else {
            printf("NO\n");
        }

        for (int i = 1; i <= N; i ++) c[i] = 0;
        for (int i = 1; i <= M; i ++) f[i].clear();
    }
    return 0;
}