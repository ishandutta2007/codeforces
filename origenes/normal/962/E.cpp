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
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 212345;
int n, x[maxn];
char s[maxn][5];
vector<int> vec;

int main() {
    scanf("%d", &n);
    int mnr = 1e9 + 10, mxr = -1e9 - 10, mnb = 1e9 + 10, mxb = -1e9 - 10;
    REP(i, n) {
        scanf("%d%s", x + i, s[i]);
        if (s[i][0] == 'P') vec.eb(i);
        else if (s[i][0] == 'R') {
            chkmin(mnr, x[i]);
            chkmax(mxr, x[i]);
        } else {
            chkmin(mnb, x[i]);
            chkmax(mxb, x[i]);
        }
    }
    if (vec.empty()) {
        printf("%lld", ll(max(mxr - mnr, 0)) + max(mxb - mnb, 0));
        return 0;
    }
    ll ans = max(x[vec[0]] - mnr, 0);
    ans += max(x[vec[0]] - mnb, 0);
    ans += max(mxr - x[vec.back()], 0);
    ans += max(mxb - x[vec.back()], 0);
    REP(i, int(vec.size()) - 1) {
        int u = vec[i], v = vec[i + 1];
        ans += x[v] -x[u];
        ll way[2] = {};
        way[0] = x[v] - x[u];
        int sr = x[u], sb = x[u], nowr = 0, nowb = 0;
        FOR(j, u + 1, v - 1) {
            if (s[j][0] == 'R') {
                chkmax(nowr, x[j] - sr);
                sr = x[j];
            } else {
                chkmax(nowb, x[j] - sb);
                sb = x[j];
            }
        }
        chkmax(nowr, x[v] - sr);
        chkmax(nowb, x[v] - sb);
        way[1] = ll(x[v]) * 2 - x[u] * 2 - nowr - nowb;
        ans += min(way[0], way[1]);
    }
    printf("%lld", ans);
}