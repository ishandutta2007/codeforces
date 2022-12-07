#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;
const int P = 998244353;

int T, N, M;
int a[MAX_N];

int solve(int m, int x) {
    vector<int> p;
    if (~x & 1) {
        p.push_back(2);
        x /= x & -x;
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            p.push_back(i);
            for (; x % i == 0; x /= i);
        }
    }
    if (x > 1) p.push_back(x);
    int n = p.size(), res = 0;
    for (int s = 0; s < 1 << n; s ++) {
        int t = 1, c = 1;
        for (int i = 0; i < n; i ++) {
            if (s >> i & 1) {
                t *= p[i], c = -c;
            }
        }
        t = m / t % P;
        res = (res + t * c + P) % P;
    }
    return res;
}

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
        }
        int ans = 1;
        for (int i = 2; i <= N; i ++) {
            if (a[i - 1] % a[i] != 0) {
                ans = 0;
                break;
            } else if (a[i] == a[i - 1]) {
                ans = 1ll * ans * (M / a[i]) % P;
            } else {
                ans = 1ll * ans * solve(M / a[i], a[i - 1] / a[i]) % P;
            }
            // printf("i=%d, ans=%d\n", i, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}