#include <cstdio>
#include <algorithm>

using namespace std;

long long const INF = 1LL << 60;    
int xs[12345];
int left[12345], right[12345];
long long dp[12345];

int main() {
    int n, sx;
    scanf("%d%d", &n, &sx);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", left + i, right + i);
        xs[i * 2] = left[i];
        xs[i * 2 + 1] = right[i];
    }
    xs[2 * n] = sx;
    sort(xs, xs + 2 * n + 1);
    int cn = (int) (unique(xs, xs + 2 * n + 1) - xs);
    for (int i = 0; i < n; i++) {
        left[i] = (int) (lower_bound(xs, xs + cn, left[i]) - xs);
        right[i] = (int) (lower_bound(xs, xs + cn, right[i]) - xs);
    }
    sx = (int) (lower_bound(xs, xs + cn, sx) - xs);
    for (int i = 0; i < cn; i++) dp[i] = INF;
    dp[sx] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < cn; j++) 
            if (dp[j] > dp[j - 1] + (xs[j] - xs[j - 1]))
                dp[j] = dp[j - 1] + (xs[j] - xs[j - 1]);
        for (int j = cn - 2; j >= 0; j--) 
            if (dp[j] > dp[j + 1] + (xs[j + 1] - xs[j]))
                dp[j] = dp[j + 1] + (xs[j + 1] - xs[j]);
        for (int j = 0; j < cn; j++) {
            dp[j] += (left[i] <= j && j <= right[i]) ? 0 : j < left[i] ? xs[left[i]] - xs[j] : xs[j] - xs[right[i]];
        }
    }
    long long ans = INF;
    for (int i = 0; i < cn; i++) if (ans > dp[i]) ans = dp[i];
    printf("%lld\n", ans);
}