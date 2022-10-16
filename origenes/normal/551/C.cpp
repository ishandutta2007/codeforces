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

int n, m, a[maxn];

bool check(ll k) {
    ll rem = 0, tot = 0;
    ROF(i, n, 1) {
        if (a[i] <= rem) {
            rem -= a[i];
            continue;
        }
        if (k <= i) return false;
        ll need = (a[i] - rem + (k - i - 1)) / (k - i);
        rem = (k - i) * need - (a[i] - rem);
        tot += need;
        if (tot > m) return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", a + i);
    ll l = 0, r = 1e15;
    while (l < r) {
        ll m = l + r >> 1;
        if (check(m)) r = m;
        else l = m + 1;
    }
    printf("%lld", l);
}