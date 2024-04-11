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

const int maxn = 2123;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll a[maxn], b[maxn], mmina[maxn], mminb[maxn], x;
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        a[i] = a[i - 1] + a[i];
    }
    FOR(i, 1, m) {
        scanf("%lld", &b[i]);
        b[i] = b[i - 1] + b[i];
    }
    scanf("%lld", &x);
    FOR(i, 1, n) {
        mmina[i] = inf;
        FOR(j, i, n) mmina[i] = min(mmina[i], a[j] - a[j - i]);
    }
    FOR(i, 1, m) {
        mminb[i] = inf;
        FOR(j, i, m) mminb[i] = min(mminb[i], b[j] - b[j - i]);
    }
    int ans = 0;
    FOR(i, 1, n) FOR(j, 1, m) {
            if (mmina[i] * mminb[j] <= x) ans = max(ans, i * j);
        }
    printf("%d\n", ans);
    return 0;
}