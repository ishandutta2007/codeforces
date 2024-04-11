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

const int maxn = 1234;
const ll MOD = 1e9 + 7;

ll pow_mod(ll a, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

ll inv(ll x) {
    return pow_mod(x, MOD - 2);
}

ll n, m, k, ans;
ll C[maxn][maxn], ck[maxn], cn[maxn], cnm[maxn], CK[maxn][maxn];

void init() {
    if (m == 1) return;
    C[0][0] = 1;
    FOR(i, 1, 1000) {
        C[i][0] = 1;
        FOR(j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    ck[0] = 1;
    FOR(i, 1, min(1000LL, k)) ck[i] = ck[i - 1] * (k - i + 1) % MOD * inv(i) % MOD;
    int st = int(min(1000LL, k));
    CK[st][0] = 1;
    FOR(i, 1, min(1000LL, k - st)) CK[st][i] = CK[st][i - 1] * (k - st - i + 1) % MOD * inv(i) % MOD;
    ROF(i, st - 1, 0) {
        CK[i][0] = 1;
        FOR(j, 1, min(k - i, 1000LL)) CK[i][j] = (CK[i + 1][j] + CK[i + 1][j - 1]) % MOD;
    }
    cn[1] = cnm[1] = 1;
    FOR(i, 2, 1000) REP(j, i) {
            if (j & 1) {
                cn[i] = (cn[i] - C[i][j] * pow_mod(i - j, n)) % MOD;
                cnm[i] = (cnm[i] - C[i][j] * pow_mod(i - j, n * (m - 2))) % MOD;
                if (cn[i] < 0) cn[i] += MOD;
                if (cnm[i] < 0) cnm[i] += MOD;
            } else {
                cn[i] = (cn[i] + C[i][j] * pow_mod(i - j, n)) % MOD;
                cnm[i] = (cnm[i] + C[i][j] * pow_mod(i - j, n * (m - 2))) % MOD;
            }
        }
}

int main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    init();
    if (m == 1) {
        ans = pow_mod(k, n);
    } else if (m == 2) {
        FOR(i, 1, min(n, k)) {
            ll now = ck[i] * cn[i] % MOD;
            now = now * now % MOD;
            ans = (ans + now) % MOD;
        }
    } else {
        FOR(i, 1, min(k, n * (m - 2))) {
            ll now = ck[i] * cnm[i] % MOD, cur = 0;
            REP(j, min(n, k) - i + 1) {
                ll tmp = CK[i][j] * cn[i + j] % MOD;
                cur = (cur + tmp * tmp % MOD) % MOD;
            }
            ans = (ans + now * cur) % MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}