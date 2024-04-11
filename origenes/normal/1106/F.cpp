#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const ll p = 998244353;
const ll g = 3;
const ll maxk = 123;

void mul(ll dist[maxk][maxk], int n, ll a[maxk][maxk], ll b[maxk][maxk]) {
    FOR(i, 1, n) FOR(j, 1, n) dist[i][j] = 0;
    FOR(i, 1, n) FOR(j, 1, n) FOR(k, 1, n)
                dist[i][j] = (dist[i][j] + a[i][k] * b[k][j]) % (p - 1);
}

void pow_mat(ll dist[maxk][maxk], int n, ll k, ll a[maxk][maxk]) {
    FOR(i, 1, n) FOR(j, 1, n) dist[i][j] = 0;
    FOR(i, 1, n) dist[i][i] = 1;
    while (k) {
        if (k & 1) {
            ll tmp[maxk][maxk];
            mul(tmp, n, dist, a);
            FOR(i, 1, n) FOR(j, 1, n) dist[i][j] = tmp[i][j];
        }
        ll tmp[maxk][maxk];
        mul(tmp, n, a, a);
        FOR(i, 1, n) FOR(j, 1, n) a[i][j] = tmp[i][j];
        k >>= 1;
    }
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll now = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return now;
}

ll pow_mod(ll a, ll k, ll mod) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return ret;
}

ll inv(ll a, ll mod) {
    return pow_mod(a, mod - 2, mod);
}

ll log_mod(ll a, ll b, ll n) {
    ll m = sqrt(n + 0.5), v = inv(pow_mod(a, m, n), n), e = 1;
    map<ll, int> x;
    x[1] = 0;
    FOR(i, 1, m - 1) {
        e = e * a % n;
        if (!x.count(e)) x[e] = i;
    }
    REP(i, m) {
        if (x.count(b)) return i * m + x[b];
        b = b * v % n;
    }
}

ll solve(ll a, ll b, ll c) {
    if (!c) return 0;
    ll d = __gcd(a, b);
    if (c % d) return -1;
    a /= d, b /= d, c /= d;
    ll ret, tmp;
    exgcd(a, b, ret, tmp);
    ret = ret * c % b;
    if (ret < 0) ret += b;
    return ret;
}

ll A[maxk][maxk], b[maxk], tmp[maxk][maxk];

int k;
ll n, m;

int main() {
    scanf("%d", &k);
    FOR(i, 1, k) {
        scanf("%lld", b + i);
        b[i] %= (p - 1);
    }
    scanf("%lld%lld", &n, &m);
    FOR(i, 1, k) A[1][i] = b[i];
    FOR(i, 2, k) A[i][i - 1] = 1;
    pow_mat(tmp, k, n - k, A);
    ll now = solve(tmp[1][1], p - 1, log_mod(g, m, p));
    printf("%lld", now >= 0 ? pow_mod(g, now, p) : -1);
}