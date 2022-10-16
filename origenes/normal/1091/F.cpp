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

int n;
ll l[maxn];
char op[maxn];

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%lld", l + i);
    scanf("%s", op + 1);
    bool ww = false;
    ll t = 0, e = 0, g2 = 0;
    FOR(i, 1, n) {
        if (op[i] == 'L') {
            t += l[i];
            e -= l[i];
            if (e < 0) {
                t -= e * (ww ? 3 : 5);
                e = 0;
            }
        } else if (op[i] == 'W') {
            ww = true;
            e += l[i];
            t += 3 * l[i];
        } else {
            e += l[i];
            t += 5 * l[i];
            g2 += 2 * l[i];
        }
        g2 = min(g2, e);
    }
    if (e > 0) {
        t -= 4 * g2 / 2;
        t -= 2 * (e - g2) / 2;
    }
    printf("%lld", t);
}