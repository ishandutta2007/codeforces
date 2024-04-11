#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &x, &y);
        ans = ans < x + y ? x + y : ans;
    }
    printf("%d\n", ans);
    return 0;
}