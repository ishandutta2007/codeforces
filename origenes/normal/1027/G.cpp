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
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 55;

ll m, x, ans;
vector<pair<ll, int>> fac;
vector<ll> G[maxn];

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

inline ll add(ll a, ll b, ll p) {
    return (a += b) < p ? a : a - p;
}

ll mul(ll a, ll b, ll p) {
    ll ret = 0, now = a;
    while (b) {
        if (b & 1) ret = add(ret, now, p);
        now = add(now, now, p);
        b >>= 1;
    }
    return ret;
}

bool fast_pow(ll x, ll b, ll p) {
    ll ret = 1, now = x;
    while (b) {
        if (b & 1) ret = mul(ret, now, p);
        now = mul(now, now, p);
        b >>= 1;
    }
    return ret == 1;
}

void dfs(int u, ll now, ll g) {
    if (u == fac.size()) {
        ans += now / g;
        return;
    }
    dfs(u + 1, now, g);
    ll cur = fac[u]._1;
    now *= (cur - 1);
    dfs(u + 1, now, lcm(G[u][1], g));
    FOR(i, 2, fac[u]._2) {
        now *= cur;
        dfs(u + 1, now, lcm(G[u][i], g));
    }
}

int main() {
    scanf("%lld%lld", &m, &x);
    for (ll i = 2; i * i <= m; i++) if (m % i == 0) {
            int cnt = 0;
            while (m % i == 0) {
                m /= i;
                cnt++;
            }
            fac.pb(mp(i, cnt));
        }
    if (m > 1) fac.pb(mp(m, 1));
    REP(i, fac.size()) {
        ll num = fac[i]._1, cnt = fac[i]._2;
        G[i].resize(cnt + 1);
        ll xnow = x % num, cur = 1;
        bool flag = false;
        for (; cur * cur <= num - 1; cur++) if ((num - 1) % cur == 0) {
                if (fast_pow(xnow, cur, num)) {
                    G[i][1] = cur;
                    flag = true;
                    break;
                }
            }
        if (!flag) {
            for (; cur >= 1; cur--) if ((num - 1) % cur == 0) {
                    if (fast_pow(xnow, (num - 1) / cur, num)) {
                        G[i][1] = (num - 1) / cur;
                        break;
                    }
                }
        }
        ll mod = num;
        FOR(j, 2, cnt) {
            mod *= num;
            if (fast_pow(x % mod, G[i][j - 1], mod)) G[i][j] = G[i][j - 1];
            else G[i][j] = G[i][j - 1] * num;
        }
    }
    dfs(0, 1, 1);
    printf("%lld\n", ans);
    return 0;
}