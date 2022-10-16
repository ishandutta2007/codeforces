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

const int maxn = 512345;
const ll MOD = 1e9 + 7;

int n, m, k, p[maxn], rk[maxn], cnt;
ll c[maxn];
pair<ll, pii> e[maxn];
vector<int> s;

ll pow_mod(ll p) {
    ll ret = 1, base = 2;
    while (p) {
        if (p & 1) ret = ret * base % MOD;
        base = base * base % MOD;
        p >>= 1;
    }
    return ret;
}

int query(int x) {
    return p[x] == x ? x : p[x] = query(p[x]);
}

void merge(int u, int v) {
    int ru = query(u), rv = query(v);
    if (ru == rv) return;
    if (rk[ru] >= rk[rv]) {
        p[rv] = ru;
        rk[ru] = max(rk[ru], rk[rv] + 1);
        s.pb(rv);
    } else {
        p[ru] = rv;
        rk[rv] = max(rk[rv], rk[ru] + 1);
        s.pb(ru);
    }
    cnt++;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, n) scanf("%lld", c + i);
    FOR(i, 1, m) {
        scanf("%d%d", &e[i]._2._1, &e[i]._2._2);
        e[i]._1 = c[e[i]._2._1] ^ c[e[i]._2._2];
    }
    sort(e + 1, e + m + 1);
    FOR(i, 1, n) p[i] = i, rk[i] = 1;
    ll now = 0, ans = 0;
    FOR(i, 1, m) {
        if (e[i]._1 != now) {
            ans = (ans + pow_mod(n - cnt)) % MOD;
            cnt = 0;
            ans = (ans + (e[i]._1 - now - 1) % MOD * pow_mod(n) % MOD) % MOD;
            for (int it : s) p[it] = it, rk[it] = 1;
            s.clear();
            now = e[i]._1;
        }
        merge(e[i]._2._1, e[i]._2._2);
    }
    ans = (ans + pow_mod(n - cnt)) % MOD;
    ans = (ans + ((1LL << k) - now - 1) % MOD * pow_mod(n)) % MOD;
    printf("%lld\n", ans);
    return 0;
}