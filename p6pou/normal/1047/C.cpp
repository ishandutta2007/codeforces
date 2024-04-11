#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300000 + 5;
const int MAX_A = 15000000 + 5;

int N, A, a[MAX_N], d = 0, ans;
int mp[MAX_A], prime[MAX_A >> 3], np, c[MAX_A];

inline int gcd(int x, int y) {
    while (y) {
        int t = x % y;
        x = y;
        y = t;
    }
    return x;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
        A = A < a[i] ? a[i] : A;
        d = gcd(a[i], d);
    }
    if (A == d) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= N; i ++) {
        a[i] /= d;
    }
    A /= d;
    for (int i = 2; i <= A; i ++) {
        if (!mp[i]) {
            mp[i] = i;
            prime[++ np] = i;
        }
        for (int j = 1; j <= np && i * prime[j] <= A; j ++) {
            mp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    for (int i = 1; i <= N; i ++) {
        int x = a[i];
        while (x > 1) {
            int p = mp[x];
            c[p] ++;
            while (x % p == 0) {
                x /= p;
            }
        }
    }
    for (int i = 1; i <= A; i ++) {
        ans = ans < c[i] ? c[i] : ans;
    }
    printf("%d\n", N - ans);
    return 0;
}