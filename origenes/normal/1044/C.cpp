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

const int maxn = 312345;

int x[maxn], y[maxn], n;

inline int dis(pii a, pii b) {
    return abs(a._1 - b._1) + abs(a._2 - b._2);
}

int main() {
    scanf("%d", &n);
    int xmx = -1e9, xmn = 1e9, ymx = -1e9, ymn = 1e9;
    int r[4];
    FOR(i, 1, n) {
        scanf("%d%d", x + i, y + i);
        if (x[i] > xmx) {
            r[0] = i;
            xmx = x[i];
        }
        if (x[i] < xmn) {
            r[1] = i;
            xmn = x[i];
        }
        if (y[i] > ymx) {
            r[2] = i;
            ymx = y[i];
        }
        if (y[i] < ymn) {
            r[3] = i;
            ymn = y[i];
        }
    }
    int ans = 0;
    REP(i, 4) FOR(j, i + 1, 3) {
            pii p[2] = {{x[r[i]], y[r[i]]}, {x[r[j]], y[r[j]]}};
            FOR(k, 1, n) {
                if (k == r[i] || k == r[j]) continue;
                pii now = {x[k], y[k]};
                ans = max(ans, dis(now, p[0]) + dis(now, p[1]) + dis(p[0], p[1]));
            }
        }
    printf("%d ", ans);
    FOR(i, 4, n) printf("%d ", 2 * (xmx - xmn + ymx - ymn));
}