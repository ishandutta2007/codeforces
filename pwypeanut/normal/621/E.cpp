#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, B, K, X, arr[50005], dp[50005][105], a[10];
map< pair<int, int>, int> M;

int modpow(int b, int p, int m) {
    if (p == 0) return 1 % m;
    else if (p == 1) return b % m;
    else if (p % 2 == 0) {
        int a = modpow(b, p/2, m);
        return ((long long)a * a) % m;
    } else {
        int a = modpow(b, p/2, m);
        return ((((long long)a * a) % m) * b) % m;
    }
}

int dnc(int n, int t) {
    if (M.find(make_pair(n, t)) != M.end()) return M[make_pair(n, t)];
    if (n == 0) {
        if (t == 0) return 1;
        else return 0;
    } else if (n == 1) {
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if (i % X == t) {
                ans += a[i];
                ans %= MOD;
            }
        }
        return M[make_pair(n, t)] = ans;
    }

    int l = n / 2, r = n - l;
    long long ans[X];
    for (int i = 0; i < X; i++) ans[i] = 0;

    for (int i = 0; i < X; i++) {
        for (int j = 0; j < X; j++) {
            int a = dnc(l, i), b = dnc(r, j);
            int resmod = ((modpow(10, r, X) * i) % X + j) % X;
            ans[resmod] += (long long)a * b;
            ans[resmod] %= MOD;
        }
    }
    for (int i = 0; i < X; i++) M[make_pair(n, i)] = ans[i];
    return ans[t];
}

int main() {
    scanf("%d%d%d%d", &N, &B, &K, &X);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < N; i++) a[arr[i]]++;
    printf("%d\n", dnc(B, K));
}