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

int n, ans;
char s[maxn];
vector<pii> segs;

int main() {
    scanf("%d%s", &n, s + 1);
    s[n + 1] = 'S';
    int pre = 0;
    FOR(i, 1, n + 1) {
        if (s[i] == 'G') {
            if (!pre) pre = i;
        } else {
            if (pre) segs.pb(mp(pre, i - 1));
            pre = 0;
        }
    }
    if (!segs.size()) puts("0");
    else if (segs.size() == 1) printf("%d", segs[0]._2 - segs[0]._1 + 1);
    else if (segs.size() == 2) {
        if (segs[0]._2 + 2 == segs[1]._1) ans = segs[0]._2 - segs[0]._1 + segs[1]._2 - segs[1]._1 + 2;
        else ans = max(segs[0]._2 - segs[0]._1, segs[1]._2 - segs[1]._1) + 2;
        printf("%d", ans);
    } else {
        REP(i, int(segs.size()) - 1) {
            if (segs[i]._2 + 2 == segs[i + 1]._1) ans = max(ans, segs[i]._2 - segs[i]._1 + segs[i + 1]._2 - segs[i + 1]._1 + 3);
            else ans = max(ans, segs[i]._2 - segs[i]._1 + 2);
        }
        ans = max(ans, segs.back()._2 - segs.back()._1 + 2);
        printf("%d", ans);
    }
}