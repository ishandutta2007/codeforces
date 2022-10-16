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

bool vis[maxn];
set<int> s[maxn];
int q;

void get(int &ret, const set<int> &s, int pos, int need, const set<int>::iterator &lo, const set<int>::iterator &hi) {
    ret |= need << pos;
    auto it = s.lower_bound(ret);
//    cout << pos << ' ' << need << ' ' << ret << ' ';
    if (it == s.end() || (hi != s.end() && *it >= *hi)) goto label;
    if (*lo > *it) goto label;
    if (!need && (ret >> pos) < (*it >> pos)) goto label;
//    cout << ret << '\n';
    return;
    label:
    ret ^= 1 << pos;
//    cout << ret << '\n';
}

int main() {
    scanf("%d", &q);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int u;
            scanf("%d", &u);
            if (vis[u]) continue;
            vis[u] = true;
            int upp = sqrt(u) + 0.5;
            FOR(i, 1, upp) if (u % i == 0) {
                    s[i].insert(u);
                    s[u / i].insert(u);
                }
        } else {
            int x, k, lim;
            scanf("%d%d%d", &x, &k, &lim);
            if (x % k || s[k].empty()) {
                puts("-1");
                continue;
            }
            auto hi = s[k].upper_bound(lim - x);
            if (hi == s[k].begin()) {
                puts("-1");
                continue;
            }
            auto lo = s[k].begin();
            int ret = 0;
            ROF(i, 16, 0) {
                int cur = (x >> i) & 1;
                get(ret, s[k], i, 1 - cur, lo, hi);
                hi = s[k].upper_bound(min(lim - x, ret + (1 << i) - 1));
                lo = s[k].lower_bound(ret);
            }
            ret = *lo;
            assert(ret > 0);
            printf("%d\n", ret);
        }
    }
}