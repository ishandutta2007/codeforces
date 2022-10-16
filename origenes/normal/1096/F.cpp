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

const int maxn = 212345;
const ll MOD = 998244353;

int C[maxn], n, a[maxn];
bool vis[maxn];
ll ans;

inline int lowbit(int x) {
    return x & -x;
}

void add(int x, int d) {
    while (x <= n) {
        C[x] += d;
        x += lowbit(x);
    }
}

ll inv(ll a) {
    ll k = MOD - 2, ret = 1;
    while (k) {
        if (k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

int sum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    int cnt = 0;
    FOR(i, 1, n) {
        scanf("%d", a + i);
        if (a[i] == -1) continue;
        int now = cnt - sum(a[i]);
        add(a[i], 1);
        vis[a[i]] = true;
        cnt++;
        ans += now;
    }
    ans %= MOD;
    reset(C, 0);
    FOR(i, 1, n) if (!vis[i]) add(i, 1);
    int len = n - cnt;
    cnt = 0;
    ll res = 0;
    FOR(i, 1, n) {
        if (a[i] == -1) cnt++;
        else {
            int p = sum(a[i]);
            res = (res + ll(len - p) * cnt + ll(len - cnt) * p) % MOD;
        }
    }
    ans = (ans + res * inv(len)) % MOD;
    ans = (ans + ll(len - 1) * len % MOD * inv(4)) % MOD;
    printf("%lld", ans);
}