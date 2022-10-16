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

ll n, m;

int main() {
    scanf("%lld%lld", &n, &m);
    ll mmax = 0;
    FOR(i, 1, n) {
        ll now = ll(i) * (i - 1) / 2;
        if (now >= m) {
            mmax = i;
            if (mmax == 1) mmax = 0;
            break;
        }
    }
    printf("%lld %lld\n", max(n - 2 * m, 0LL), n - mmax);
    return 0;
}