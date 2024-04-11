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

const int maxn = 123;

ll n, b[2];
int q;

int main() {
    scanf("%lld%d", &n, &q);
    b[0] = 0;
    b[1] = (n * n + 1) / 2;
    while (q--) {
        ll x, y, ans = 0;
        scanf("%lld%lld", &x, &y);
        if ((x + y) & 1) ans = b[1];
        ans += (x - 1) / 2 * n;
        if (x & 1) {
            if (y & 1) ans += (y + 1) / 2;
            else ans += y / 2;
        } else {
            ans += ((x + y) & 1) ? n / 2 : (n + 1) / 2;
            if (y & 1) ans += (y + 1) / 2;
            else ans += y / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}