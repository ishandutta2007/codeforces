#include<cstdio>

using namespace std;
const int N = 100 + 10;

int a[N];

int main() {
    int n, x ,y;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    scanf("%d %d", &x, &y);
    int ans, rest;
    ans = rest = 0;
    for (int i = 1; i <= n; i++) {
        if (x <= rest && rest <= y && x <= sum && sum <= y) ans = i;
        rest += a[i];
        sum -= a[i];
    }
    printf("%d", ans);
    return 0;
}