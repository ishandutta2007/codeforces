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

int n;
ll T, a[maxn];
bool vis[maxn];

int main() {
    scanf("%d%lld", &n, &T);
    int tot = n;
    ll cost = 0, ans = 0;
    FOR(i, 1, n) {
        scanf("%lld", a + i);
        cost += a[i];
    }
    while (tot) {
        ll cnt = T / cost;
        ans += cnt * tot;
        T -= cnt * cost;
        FOR(i, 1, n) if (!vis[i]) {
                if (a[i] <= T) {
                    T -= a[i];
                    ans++;
                } else {
                    vis[i] = true;
                    tot--;
                    cost -= a[i];
                }
            }
    }
    printf("%lld\n", ans);
    return 0;
}