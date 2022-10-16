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

int a[maxn], n, k, A, B;

ll solve(int l, int r) {
    int lo = lower_bound(a + 1, a + k + 1, l) - a, hi = upper_bound(a + 1, a + k + 1, r) - a - 1;
    if (lo > hi) return A;
    int cnt = hi - lo + 1;
    if (l == r) return B * ll(cnt);
    ll ret = B * ll(cnt) * (r - l + 1);
    int m = l + (r - l >> 1);
    return min(ret, solve(l, m) + solve(m + 1, r));
}

int main() {
    scanf("%d%d%d%d", &n, &k, &A, &B);
    FOR(i, 1, k) scanf("%d", a + i);
    sort(a + 1, a + k + 1);
    printf("%lld", solve(1, 1 << n));
}