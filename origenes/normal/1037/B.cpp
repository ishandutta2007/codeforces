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

int n, a[maxn], s;

int main() {
    scanf("%d%d", &n, &s);
    FOR(i, 1, n) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    ll ans = 0;
    if (a[n / 2 + 1] > s) {
        ans = a[n / 2 + 1] - s;
        ROF(i, n / 2, 1) {
            if (a[i] <= s) break;
            ans += a[i] - s;
        }
    } else if (a[n / 2 + 1] < s) {
        ans = s - a[n / 2 + 1];
        FOR(i, n / 2 + 2, n) {
            if (a[i] >= s) break;
            ans += s - a[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}