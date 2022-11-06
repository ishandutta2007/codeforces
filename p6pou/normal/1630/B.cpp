#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;

int T, N, K;
int a[MAX_N], c[MAX_N];
int ans, ansx, ansy;

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
            c[a[i]] ++;
        }
        ans = 1e9;
        for (int x = 1, y = 1, t = -N; x <= N; t -= c[x] * 2, x ++) {
            for (; y <= N && t < K; y ++) {
                t += c[y] * 2;
            }
            if (t >= K && ans > y - x) {
                ans = y - x;
                ansx = x;
                ansy = y - 1;
            }
        }
        printf("%d %d\n", ansx, ansy);
        vector<int> p;
        p.push_back(0);
        for (int i = 1, t = 0, k = 1; i <= N && k < K; i ++) {
            t += ansx <= a[i] && a[i] <= ansy ? 1 : -1;
            if (t == k) {
                p.push_back(i);
                k ++;
            }
        }
        p.push_back(N);
        for (int i = 1; i < (int)p.size(); i ++) {
            printf("%d %d\n", p[i - 1] + 1, p[i]);
        }
        for (int i = 1; i <= N; i ++) {
            c[i] = 0;
        }
    }
    return 0;
}