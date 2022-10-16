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

const int maxn = 12345;

int T, n, a;

map<int, int> cnt;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cnt.clear();
        REP(i, n) {
            scanf("%d", &a);
            cnt[a]++;
        }
        int p = -1;
        pii ans = mp(maxn, 1);
        for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
            if (it->_2 >= 4) {
                printf("%d %d %d %d\n", it->_1, it->_1, it->_1, it->_1);
                goto label;
            }
            if (it->_2 < 2) continue;
            if (p != -1) if (ans._1 * it->_1 > ans._2 * p) ans = mp(p, it->_1);
            p = it->_1;
        }
        printf("%d %d %d %d\n", ans._1, ans._1, ans._2, ans._2);
        label:;
    }
    return 0;
}