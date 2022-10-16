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

const int maxn = 212345;
typedef pair<ll, ll> pll;

int n;
pll s[maxn * 2], a[maxn * 2];
ll ans[maxn];

int main() {
    scanf("%d", &n);
    REP(i, n) {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        a[2 * i] = {u, 1};
        a[2 * i + 1] = {v + 1, -1};
    }
    sort(a, a + 2 * n);
    int m = 0;
    s[0] = mp(-1, 0);
    REP(i, 2 * n) {
        if (s[m]._1 != a[i]._1) {
            s[++m]._1 = a[i]._1;
            s[m]._2 = s[m - 1]._2;
        }
        s[m]._2 += a[i]._2;
    }
    REP(i, m) {
        if (s[i]._2 > n) continue;
        ans[s[i]._2] += s[i + 1]._1 - s[i]._1;
    }
    FOR(i, 1, n) printf("%lld ", ans[i]);
    return 0;
}