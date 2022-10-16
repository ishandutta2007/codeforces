#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123456;

int n, a[maxn * 2];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", &a[2 * i], &a[2 * i + 1]);
    sort(a, a + 2 * n);
    int d1 = a[n - 1] - a[0], d2 = a[2 * n - 1] - a[n];
    ll ans = ll(d1) * d2;
    FOR(i, 1, n - 1) ans = min(ans, ll(a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
    printf("%lld\n", ans);
    return 0;
}