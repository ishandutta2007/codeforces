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

const int maxn = 123456;

int a[maxn], s[maxn], n, m, ans;

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &a[i]);
    n++;
    if (n & 1) a[n++] = m;
    ROF(i, n - 2, 0) {
        s[i] = s[i + 1];
        if (i & 1 ^ 1) s[i] += a[i + 1] - a[i];
    }
    ans = s[0];
    REP(i, n) {
        if (i & 1 ^ 1) continue;
        if (a[i - 1] != a[i] - 1) ans = max(s[0] + (m - (a[i] - 1)) - 2 * (s[i] + 1), ans);
        if (i + 1 >= n || a[i + 1] != a[i] + 1) ans = max(s[0] + (m - (a[i] + 1)) - 2 * s[i], ans);
    }
    printf("%d\n", ans);
    return 0;
}