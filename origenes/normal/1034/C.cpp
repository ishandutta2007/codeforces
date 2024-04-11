#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234567;
const int MOD = 1e9 + 7;

ll a[maxn], dp[maxn];
int p[maxn], cnt[maxn], n;

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%lld", &a[i]);
    FOR(i, 2, n) scanf("%d", &p[i]);
    ROF(i, n, 2) a[p[i]] += a[i];
    FOR(i, 1, n) {
        ll now = a[1] / __gcd(a[i], a[1]);
        if (now <= n) cnt[now]++;
    }
    ROF(i, n, 1) for (int j = 2 * i; j <= n; j += i) cnt[j] += cnt[i];
    ll ans = 0;
    dp[1] = 1;
    FOR(i, 1, n) {
        if (cnt[i] != i) continue;
        ans = (ans + dp[i]) % MOD;
        for (int j = 2 * i; j <= n; j += i) if (cnt[j] == j)
                dp[j] = (dp[i] + dp[j]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}