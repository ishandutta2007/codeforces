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

int cnt[maxn], t, tmp[maxn];

int main() {
    scanf("%d", &t);
    REP(i, t) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }
    if (cnt[0] != 1) {
        puts("-1");
        return 0;
    }
    int mmax = 0;
    REP(i, t) if (cnt[i]) mmax = i;
    if (!mmax) {
        puts(t == 1 ? "1 1\n1 1" : "-1");
        return 0;
    }
    ll tot = 0;
    REP(i, t) tot += ll(i) * cnt[i];
    int upp = sqrt(t) + 0.5;
    FOR(n, 1, upp) if (t % n == 0) {
            int m = t / n;
            FOR(x, 1, n + 1 >> 1) {
                int y = n + m - x - mmax;
                if (y < 1 || y > (m + 1) / 2) continue;
                ll now = m * (ll(x) * x - (n + 1) * ll(x) + ll(n) * (n + 1) / 2) + n * (ll(y) * y - (m + 1) * ll(y) + ll(m) * (m + 1) / 2);
                if (now != tot) continue;
                reset(tmp, 0);
                FOR(i, 1, n) FOR(j, 1, m) tmp[abs(x - i) + abs(y - j)]++;
                REP(i, t) if (cnt[i] != tmp[i]) goto label;
                printf("%d %d\n%d %d", n, m, x, y);
                return 0;
                label:;
            }
        }
    puts("-1");
}