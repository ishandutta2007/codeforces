#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;

int T, N, x, y;
long long ans;
char s[MAX_N];

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        scanf("%s", s + 1);
        x = 0, y = 0, ans = 0;
        for (int i = 1; i <= N; i ++) {
            (s[i] == '0' ? x : y) ++;
        }
        if (x && y) ans = 1ll * x * y;
        x = 0, y = 0;
        for (int i = 1; i <= N; i ++) {
            x = s[i] == '0' ? x + 1 : 0;
            y = max(y, x);
        }
        ans = max(ans, 1ll * y * y);
        x = 0, y = 0;
        for (int i = 1; i <= N; i ++) {
            x = s[i] == '1' ? x + 1 : 0;
            y = max(y, x);
        }
        ans = max(ans, 1ll * y * y);
        printf("%lld\n", ans);
    }
    return 0;
}