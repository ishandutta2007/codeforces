// Author: Origenes
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

const int maxn = 1123456;

ll pow_mod(ll x, ll k, ll p) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return ret;
}

ll ans, a, b, p, x, ia, pw[maxn], inv[maxn];

int main() {
    scanf("%lld%lld%lld%lld", &a, &b, &p, &x);
    ia = pow_mod(a, p - 2, p);
    pw[0] = inv[0] = 1;
    FOR(i, 1, p - 1) {
        pw[i] = pw[i - 1] * a % p;
        inv[i] = inv[i - 1] * ia % p;
    }
    REP(i, p - 1) {
        ll step = ((i - b * inv[i]) % p + p) % p;
        if (step * (p - 1) + i > x) continue;
        ll now = x - (step * (p - 1) + i);
        ans += now / (p * (p - 1)) + (step * (p - 1) + i != 0);
    }
    printf("%lld", ans);
}