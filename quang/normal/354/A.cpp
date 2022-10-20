#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 123456789876532ll
#define N 100010

using namespace std;

int n, l, r, q1, q2;
long long w[N];

int main() {
    //fi, fo;
    scanf("%d %d %d %d %d", &n, &l, &r, &q1, &q2);
    w[0] = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        w[i] = w[i - 1] + x;
    }
    long long res = MAX;
    for(int i = 0; i <= n; i++) {
        long long cur = w[i] * l + (w[n] - w[i]) * r;
        if ( i > n - i ) cur = cur + 1ll * (2 * i - n - 1) * q1;
        if ( i < n - i ) cur = cur + 1ll * (n - 2 * i - 1) * q2;
        res = min(res, cur);
    }
    cout << res;
    return 0;
}