#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, a[N], b[N], mu[N], i1, f1[N], i2, f2[N];
ll zero, s1[N], s2[N];
int main() {
    cin >> n;
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, n) scanf("%d", &b[i]), b[i] -= a[i];
    mu[1] = 1, b[1]++;
    rep(i, 1, n) {
        if(mu[i] == 1) f1[++i1] = b[i];
        if(mu[i] == -1) f2[++i2] = b[i];
        if(mu[i] == 0) zero += abs(b[i]);
        for(int j = i * 2; j <= n; j += i) mu[j] -= mu[i], b[j] -= b[i];
    }
    sort(f1 + 1, f1 + i1 + 1), sort(f2 + 1, f2 + i2 + 1);
    rep(i, 1, i1) s1[i] = s1[i - 1] + f1[i];
    rep(i, 1, i2) s2[i] = s2[i - 1] + f2[i];
    cin >> n; int x;
    while(n--) {
        scanf("%d", &x);
        int i = lower_bound(f1 + 1, f1 + i1 + 1, -x) - f1 - 1;
        int j = lower_bound(f2 + 1, f2 + i2 + 1, x) - f2 - 1;
        printf("%lld\n", zero + x * ll(i1 - 2 * i - i2 + 2 * j) + s1[i1] - s1[i] * 2 + s2[i2] - s2[j] * 2);
    }
}