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

const int maxn = 123456;

int l[maxn], r[maxn];
int n;

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d%d", &l[i], &r[i]);
    sort(l + 1, l + n + 1);
    sort(r + 1, r + n + 1);
    ll ans = 0;
    FOR(i, 1, n) ans += max(l[i], r[i]);
    ans += n;
    printf("%lld\n", ans);
    return 0;
}