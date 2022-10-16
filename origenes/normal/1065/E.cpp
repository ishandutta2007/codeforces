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

const int maxn = 212345;
const ll MOD = 998244353;

ll pow_mod(ll a, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

ll n, a, b[maxn];
int m;

ll cal(ll u) {
    ll b = pow_mod(a, u);
    return (b * b % MOD + b) % MOD * ((MOD + 1) / 2) % MOD;
}

int main() {
    scanf("%lld%d%lld", &n, &m, &a);
    REP(i, m) scanf("%lld", b + i);
    ll ans = pow_mod(a, n - 2 * b[m - 1]);
    ans = ans * cal(b[0]) % MOD;
    REP(i, m - 1) ans = ans * cal(b[i + 1] - b[i]) % MOD;
    printf("%lld\n", ans);
    return 0;
}