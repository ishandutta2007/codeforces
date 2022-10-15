#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;

int dp[N];
vector<int> from[N];
int xs[N];
int x[N], h[N];

int main() {
    int n;
    scanf("%d", &n);
    int cn = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", x + i, h + i);
        xs[cn++] = x[i] - h[i];
        xs[cn++] = x[i];
        xs[cn++] = x[i] + h[i];
    }
    sort(xs, xs + cn);
    cn = (int) (unique(xs, xs + cn) - xs);
    for (int i = 0; i < n; i++) {
        if (i == 0 || x[i] - h[i] > x[i - 1])
            from[lower_bound(xs, xs + cn, x[i]) - xs].push_back((int) (lower_bound(xs, xs + cn, x[i] - h[i]) - xs));
        if (i + 1 >= n || x[i] + h[i] < x[i + 1])
            from[lower_bound(xs, xs + cn, x[i] + h[i]) - xs].push_back((int) (lower_bound(xs, xs + cn, x[i]) - xs));
    }
    for (int i = 0; i < cn; i++) {
        if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
        for (int j : from[i]) {
            int val = j > 0 ? dp[j - 1] : 0;
            dp[i] = max(dp[i], val + 1);
        }
    }
    printf("%d\n", dp[cn - 1]);
}