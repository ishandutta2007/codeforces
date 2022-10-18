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

const int maxx = 2e5;

int n, x;
ll ans[maxx + 123];
vector<pii> G[maxx + 123];

int main() {
    FOR(i, 1, maxx) {
        if (i * 2 + 1 > maxx) break;
        for (ll j = i + 1; sqr(j) - sqr(ll(i)) <= maxx; j++)
            G[sqr(j) - sqr(ll(i))].pb(mp(i, int(j)));
    }
    scanf("%d", &n);
    FOR(_i, 1, n / 2) {
        scanf("%d", &x);
        int i = _i << 1;
        for (auto it : G[x]) if (ans[i - 2] < it._1) {
                ans[i - 1] = it._1;
                ans[i] = it._2;
                break;
            }
        if (!ans[i - 1]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    FOR(i, 1, n) printf("%lld ", sqr(ans[i]) - sqr(ans[i - 1]));
}