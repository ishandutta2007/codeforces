#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int H, W, N, dp[2005], fac[300005], g, x, y;
vector< pair<int, int> > V;

long long mul_inv(long long a, long long b) {
	long long b0 = b, t, q;
	long long x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int choose(int n, int k) {
    if (n < 0) return 0;
    if (k < 0) return 0;
    if (k > n) return 0;
    long long divisor = (long long)fac[k] * fac[n-k];
    divisor %= MOD;
    return ((long long)fac[n] * (mul_inv(divisor, 1000000007) % MOD)) % MOD;
}

int f(int x) {
    if (dp[x] != -1) return dp[x];
    if (x == 0) return dp[x] = choose(V[x].first, V[x].second);
    long long ans = choose(V[x].first, V[x].second);
    for (int i = 0; i < x; i++) {
        long long potato = (long long)f(i) * choose(V[x].first - V[i].first, V[x].second - V[i].second);
        potato %= MOD;
        ans -= potato;
        ans += MOD;
        ans %= MOD;
    }
    return dp[x] = ans;
}

int main() {
    fac[0] = 1;
    long long cur = 1;
    for (int i = 1; i <= 300000; i++) {
        cur *= i;
        cur %= MOD;
        fac[i] = cur;
    }
    scanf("%d%d%d", &H, &W, &N);
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        //printf("%d %d\n", a+b, a);
        V.push_back(make_pair(a+b, a));
    }
    sort(V.begin(), V.end());
    memset(dp, -1, sizeof(dp));
    long long ans = choose(H + W-2, H-1);
    for (int i = 0; i < N; i++) {
        long long m = (long long)f(i) * choose(H + W - 2 - V[i].first, H - 1 - V[i].second);
        m %= MOD;
        ans -= m;
        ans += MOD;
        ans %= MOD;
    }
    //for (int i= 0; i <N; i++) printf("%d %d\n", i, dp[i]);
    printf("%d\n", int(ans));
}