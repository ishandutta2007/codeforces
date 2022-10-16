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

int main() {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    if (n > m) swap(n, m);
    ll ans = 0;
    if (n == 1) {
        switch (m % 6) {
            case 0:
                break;
            case 1:
            case 5:
                ans--;
                break;
            case 2:
            case 4:
                ans -= 2;
                break;
            case 3:
                ans -= 3;
                break;
        }
    } else if (n == 2) {
        if (m == 2) ans = -4;
        else if (m == 1 || m == 3 || m == 7) ans = -2;
    } else if((n * m) & 1) ans--;
    ans += n * m;
    printf("%lld\n", ans);
    return 0;
}