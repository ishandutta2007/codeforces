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

const int maxn = 1123456;

typedef pair<ll, ll> pll;

vector<pll> q;

pair<pll, ll> rect[maxn];
int n;
ll dp[maxn], ans;

pll operator - (pll a, pll b) {
    return mp(a._1 - b._1, a._2 - b._2);
}

inline bool check(pll c, pll a, pll b) {
    a = a - c, b = b - c;
    return a._1 * double(b._2) - a._2 * double(b._1) <= 0;
}

void add(pll now) {
    int R = q.size();
    while (R >= 2 && check(q[R - 2], q[R - 1], now)) {
        R--;
        q.pop_back();
    }
    q.pb(now);
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%lld%lld%lld", &rect[i]._1._1, &rect[i]._1._2, &rect[i]._2);
    sort(rect + 1, rect + n + 1);
    int L = 0;
    FOR(i, 1, n) {
        add(mp(dp[i - 1], rect[i - 1]._1._1));
        L = min(L, int(q.size()) - 1);
        while (L < int(q.size()) - 1 && q[L + 1]._1 - q[L + 1]._2 * rect[i]._1._2 >= q[L]._1 - q[L]._2 * rect[i]._1._2)
            L++;
        dp[i] = q[L]._1 + rect[i]._1._2 * (rect[i]._1._1 - q[L]._2) - rect[i]._2;
        ans = max(ans, dp[i]);
    }
    printf("%lld", ans);
}