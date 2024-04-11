#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;

int N, a[MAX_N], ans;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + N);
    for (int i = 1; i <= N; i ++) {
        int l = a[i], r = a[i], res = 1;
        for (int j = 0; j < 30; j ++) {
            int cnt = upper_bound(a + 1, a + 1 + N, r ^ 1 << j) - lower_bound(a + 1, a + 1 + N, l ^ 1 << j);
            res += cnt > 0;
            l &= ~(1 << j);
            r |= 1 << j;
        }
        ans = max(ans, res);
    }
    printf("%d\n", N - ans);
    return 0;
}