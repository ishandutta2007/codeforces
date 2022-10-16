#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) FOR(i, 0, (n) - 1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
using LL = long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 2123456;
const int INF = int(1e9);

int a[N];
int n;
int cnt[N];
int tmp[N], sz;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            ++cnt[a[i]];
        }

        sz = 0;
        int minm = INF;
        for (int i = 1; i <= n; ++i) {
            if (cnt[a[i]]) {
                tmp[sz++] = cnt[a[i]];
                minm = min(minm, cnt[a[i]]);
                cnt[a[i]] = 0;
            }
        }

        int ans = n;

        //cout << minm << endl;
        for (int i = 2; i <= minm + 1; ++i) {
            int tot = 0;
            for (int j = 0; j < sz; ++j) {
                int md = tmp[j] % i;
                int dv = tmp[j] / i;
                if (md == 0 || dv >= i - 1 - md) {
                    tot += dv + (md > 0);
                } else {
                    tot = -1;
                    break;
                }
            }
            if (tot > -1) {
                //BUG(i);
                ans = tot;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}