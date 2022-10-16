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

const int inf = 2e9;

int t, n, d, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        int ans = inf;
        cin >> n >> x >> y >> d;
        if (y == 1 || y == n) {
            ans = min(ans, abs(x - y) / d + (abs(x - y) % d > 0));
            cout << ans << '\n';
            continue;
        }
        if (abs(x - y) % d == 0) ans = min(ans, abs(x - y) / d);
        if ((y - 1) % d == 0) ans = min(ans, (y - 1) / d + (x - 1) / d + ((x - 1) % d > 0));
        if ((n - y) % d == 0) ans = min(ans, (n - y) / d + (n - x) / d + ((n - x) % d > 0));
        if (ans == inf) ans = -1;
        cout << ans << '\n';
    }
}