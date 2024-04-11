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
typedef tuple<int, int, int> ti;
#define mt make_tuple

const int maxn = 55;
const ll inf = 1e13;

struct Task {
    ll w, balance;
    int c;

    void init(ll K) {
        balance = K * c - w * 1000;
    }

    bool operator < (const Task &rhs) const {
        return w > rhs.w;
    }
};

Task t[maxn], a[maxn], b[maxn];
ll dp[maxn][maxn][maxn];

int N, n1, n2;

pii moves(int &p, ll w) {
    int m1 = 0, m2 = 0;
    while (b[p].w > w) {
        m1++;
        p++;
    }
    while (b[p].w == w) {
        m2++;
        p++;
    }
    return {m1, m2};
}

bool check(ll K) {
    FOR(i, 1, N) t[i].init(K);
    reset(a, 0);
    reset(b, 0);
    reset(dp, -1);
    n1 = n2 = 0;
    FOR(i, 1, N) t[i].balance >= 0 ? b[++n2] = t[i] : a[++n1] = t[i];
    sort(a + 1, a + n1 + 1);
    sort(b + 1, b + n2 + 1);
    dp[0][0][0] = 0;
    FOR(i, 1, n2) dp[0][0][0] += b[i].balance;
    int p = 1;
    REP(i, n1) {
        bool flag = (a[i].w == a[i + 1].w);
        pii mvs = moves(p, a[i + 1].w);
        REP(j, N) REP(k, N) {
                if (dp[i][j][k] < 0) continue;
                if (flag) {
                    dp[i + 1][j][k + 1] = max(dp[i][j][k] + a[i + 1].balance, dp[i + 1][j][k + 1]);
                    if (j) dp[i + 1][j - 1][k] = max(dp[i + 1][j - 1][k], dp[i][j][k]);
                } else {
                    dp[i + 1][j + k + mvs._1][mvs._2 + 1] = max(dp[i + 1][j + k + mvs._1][mvs._2 + 1], dp[i][j][k] + a[i + 1].balance);
                    if (j + k + mvs._1)
                        dp[i + 1][j + k + mvs._1 - 1][mvs._2] = max(dp[i + 1][j + k + mvs._1 - 1][mvs._2], dp[i][j][k]);
                }
            }
    }
    REP(j, N + 1) REP(k, N + 1) if (dp[n1][j][k] >= 0) return true;
    return false;
}

int main() {
    scanf("%d", &N);
    FOR(i, 1, N) scanf("%lld", &t[i].w);
    FOR(i, 1, N) scanf("%d", &t[i].c);
    ll L = 1, R = inf;
    while (L < R) {
        ll M = L + R >> 1;
        if (check(M)) R = M;
        else L = M + 1;
    }
    printf("%lld\n", L);
    return 0;
}