#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int N, M, A[200005], B[200005], cntA[200005], cntB[200005];
long long fac[200005];

int qexp(int b, int p) {
    if (p == 0) return 1;
    else if (p == 1) return b % MOD;
    else {
        long long val = qexp(b, p / 2);
        val *= val;
        val %= MOD;
        if (p % 2 == 1) {
            val *= b;
            val %= MOD;
        }
        return val;
    }
}

int fw[200005];

void upd(int p, int v) {
    p++;
    for (int i = p; i <= 200001; i += (i & (-i))) fw[i] += v;
}

int qry(int p) {
    p++;
    int ans = 0;
    for (int i = p; i > 0; i -= (i & (-i))) ans += fw[i];
    return ans;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < M; i++) scanf("%d", &B[i]);
    for (int i = 0; i < N; i++) cntA[A[i]]++;
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    long long botprod = 1;
    for (int i = 1; i <= 200000; i++) {
        botprod *= fac[cntA[i]];
        botprod %= MOD;
    }
    for (int i = 1; i <= 200000; i++) {
        upd(i, cntA[i]);
    }
    long long ans = 0;
    for (int i = 0; i < min(N, M); i++) {
        int qrypt = i == N - 1 && i != M - 1 ? qry(B[i]) : qry(B[i] - 1);
        long long res = (((fac[N - i - 1] * qexp(botprod, MOD - 2)) % MOD) * qrypt) % MOD;
        //printf("res: %lld, %lld, %d\n", res, botprod, qry(B[i] - 1));
        ans += res;
        ans %= MOD;
        upd(B[i], -1);
        cntA[B[i]]--;
        if (cntA[B[i]] < 0) {
            break;
        }
        botprod *= qexp(fac[cntA[B[i]] + 1], MOD - 2);
        botprod %= MOD;
        botprod *= fac[cntA[B[i]]];
        botprod %= MOD;
    }
    printf("%lld\n", ans);
}