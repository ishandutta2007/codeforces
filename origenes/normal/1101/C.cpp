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

int T, n;
vector<pair<pii, int>> v;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        v.clear();
        REP(i, n) {
            int l, r;
            scanf("%d%d", &l, &r);
            v.eb(mp(l, r), i);
        }
        sort(all(v));
        vector<pii> ans;
        int e = v[0]._1._2;
        ans.eb(v[0]._2, 1);
        bool ok = false;
        FOR(i, 1, n - 1) {
            if (ok) {
                ans.eb(v[i]._2, 2);
                continue;
            }
            if (v[i]._1._1 > e) {
                ans.eb(v[i]._2, 2);
                ok = true;
            } else {
                ans.eb(v[i]._2, 1);
                e = max(e, v[i]._1._2);
            }
        }
        if (ans.back()._2 == 1) puts("-1");
        else {
            sort(all(ans));
            for (auto now : ans) printf("%d ", now._2);
            putchar('\n');
        }
    }
}