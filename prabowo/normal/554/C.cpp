#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

typedef long long LL;

int k;
int dp[1002][1002];

int f(int pos, int sisa) {
    if (sisa < 0) return 0;
    if (pos == 0) return (sisa == 0);
    if (dp[pos][sisa] != -1) return dp[pos][sisa];
    return dp[pos][sisa] = (f(pos-1, sisa) + f(pos, sisa-1)) % MOD;
}

int main() {

    scanf("%d", &k);
    int c;
    LL ans = 1;
    int now = 1;
    memset(dp, -1, sizeof dp);

    for (int i=0; i<k; i++) {
        scanf("%d", &c);
        ans *= f(now, c-1);
        ans %= MOD;
        now += c;
    }

    printf("%I64d\n", ans);

    return 0;
}