#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define MAXN 30005

long long h, w, n, fac[200005], r, c, dp[2222], inv[200005];
pair<long long, long long> p[2222];

long long invv(long long x) {
    long long ret = 1;
    FORD (i, 30, 0) {
        ret *= ret;
        ret %= mod;
        if ((1 << i) & (mod - 2)) {
            ret *= x;
            ret %= mod;
        }
    }
    return ret;
}

long long getWays(int x, int y) {
    long long res = fac[x + y];
    res *= inv[x];
    res %= mod;
    res *= inv[y];
    res %= mod;
    return res;
}

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    fac[0] = 1;
    inv[0] = 1;
    FOR (i, 1, 200004) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
        inv[i] = invv(fac[i]);
    }
    // printf("%lld", getWays(2,3));return 0;
    // cin >> h >> w >> n;
    scanf("%lld %lld %lld", &h, &w, &n);
    REP (i, n) {
        // cin >> r >> c;
        scanf("%lld %lld", &r, &c);
        p[i] = {r, c};
    }
    p[n] = {h, w};
    sort(p, p + n);
    REP (i, n + 1) {
        r = p[i].first;
        c = p[i].second;
        dp[i] = getWays(r - 1, c - 1);
        // BUG(dp[i]);
        REP (j, i) if(p[j].first <= r && p[j].second <= c) {
            dp[i] -= dp[j] * getWays(r - p[j].first, c - p[j].second);
            dp[i] %= mod;
            dp[i] = (dp[i] + mod) % mod;
        }
        // BUG(dp[i]);
    }
    // cout << dp[n];
    printf("%lld", dp[n]);
}