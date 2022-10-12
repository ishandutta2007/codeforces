#include<cstdio>
#include<algorithm>

int n, l, r, x;
int c[20];

int main() {
    scanf("%d %d %d %d", &n, &l, &r, &x);
    for (int i=0; i<n; i++) scanf("%d", &c[i]);

    int ans = 0;
    for (int i=0; i<(1<<n); i++) {
        int cnt = 0;
        int maks = 0;
        int mini = 2000000;
        int sum = 0;
        for (int j=0; j<n; j++) {
            if ((i >> j) & 1) {
                cnt++;
                maks = std::max(maks, c[j]);
                mini = std::min(mini, c[j]);
                sum += c[j];
            }
        }

        ans += (cnt > 1 && sum >= l && sum <= r && maks-mini >= x);
    }

    printf("%d\n", ans);

    return 0;
}