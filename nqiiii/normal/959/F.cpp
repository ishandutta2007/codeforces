#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000, mod = 1000000007;
int n, q, a[maxN + 10][21], ans[maxN + 10];

bool Insert(int *a, int v) {
    for (int i = 20; i >= 0; --i)
        if (v >> i & 1) {
            if (a[i]) v ^= a[i];
            else {
                a[i] = v; return 1;
            }
        }
    return 0;
}

bool Query(int *a, int v) {
    for (int i = 20; i >= 0; --i)
        if (v >> i & 1) {
            if (a[i]) v ^= a[i];
            else return 0;
        }
    return 1;
}

int main() {
    scanf("%d%d", &n, &q);
    ans[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        memcpy(a[i], a[i - 1], sizeof a[i]);
        ans[i] = ans[i - 1];
        if (!Insert(a[i], x)) ans[i] = ans[i] * 2 % mod;
    }
    while (q--) {
        int l, x; scanf("%d%d", &l, &x);
        printf("%d\n", Query(a[l], x) ? ans[l] : 0);
    }
}