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

const int maxn = 112345;

int n, m;
int a[maxn], c[maxn];

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", a + i);
    set<pii> lis;
    FOR(i, 1, n) {
        scanf("%d", c + i);
        lis.insert(mp(c[i], i));
    }
    while (m--) {
        int t, d;
        scanf("%d%d", &t, &d);
        ll ans = 0;
        if (a[t] >= d) {
            a[t] -= d;
            ans = ll(c[t]) * d;
            printf("%lld\n", ans);
            continue;
        }
        d -= a[t];
        ans = ll(c[t]) * a[t];
        a[t] = 0;
        while (!lis.empty() && d) {
            auto now = *lis.begin();
            if (a[now._2] <= d) {
                ans += ll(c[now._2]) * a[now._2];
                d -= a[now._2];
                a[now._2] = 0;
                lis.erase(now);
            } else {
                a[now._2] -= d;
                ans += ll(c[now._2]) * d;
                d = 0;
                break;
            }
        }
        if (d > 0) puts("0");
        else printf("%lld\n", ans);
    }
}