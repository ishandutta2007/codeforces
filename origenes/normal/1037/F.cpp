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

const int maxn = 1234567;
const int MOD = 1e9 + 7;
using pli = pair<ll, int>;

inline ll add(ll a, ll b) {
    return (a += b) > MOD ? a - MOD : a;
}

inline ll sub(ll a, ll b) {
    return (a -= b) < 0 ? a + MOD : a;
}

inline ll mul(ll a, ll b) {
    return a * b % MOD;
}

int n, k;
pli a[maxn];
ll s[maxn], l[maxn], r[maxn];
bool vis[maxn];

ll solve(int u) {
    vis[u] = true;
    ll L = 0, R = 0;
    if (u > 0 && vis[u - 1]) L = u - l[u - 1];
    if (u + 1 < n && vis[u + 1]) R = r[u + 1] - u;
    r[u - L] = u + R;
    l[u + R] = u - L;
    return sub(s[L + R + 1], add(s[L], s[R]));
}

int main() {
    scanf("%d%d", &n, &k);
    k--;
    FOR(i, 1, n) s[i] = add(s[i - 1], (i - 1) / k);
    REP(i, n) {
        scanf("%lld", &a[i]._1);
        a[i]._2 = i;
    }
    sort(a, a + n);
    ll ans = 0;
    REP(i, n) ans = add(ans, mul(a[i]._1, solve(a[i]._2)));
    printf("%lld\n", ans);
    return 0;
}