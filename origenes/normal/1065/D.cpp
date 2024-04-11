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

const int maxn = 12;
const int maxm = 123;
const int inf = 0x3f3f3f3f;

pii dp[maxn][maxn][maxm][3];
int n, mat[maxn][maxn];
set<pair<pii, pair<pii, pii>>> s;
pii st, ed;

pii operator + (const pii &lhs, const pii &rhs) {
    return mp(lhs._1 + rhs._1, lhs._2 + rhs._2);
}

inline bool inside(pii& pos) {
    if (pos._1 < 1 || pos._1 > n) return false;
    if (pos._2 < 1 || pos._2 > n) return false;
    return true;
}

inline void upd(int x, int y, int now, int type, pii val) {
    if (dp[x][y][now][type] > val) {
        dp[x][y][now][type] = val;
        s.insert(mp(val, mp(mp(x, y), mp(now, type))));
    }
}

void move_knight(int x, int y, int now) {
    const static pii dir[] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {2, -1}, {1, -2}};
    pii pos = mp(x, y);
    for (auto it : dir) {
        pii nxt = pos + it;
        if (inside(nxt)) {
            if (mat[nxt._1][nxt._2] == now + 1) upd(nxt._1, nxt._2, now + 1, 0, dp[x][y][now][0] + mp(1, 0));
            else upd(nxt._1, nxt._2, now, 0, dp[x][y][now][0] + mp(1, 0));
        }
    }
}

void move_bishop(int x, int y, int now) {
    const static pii dir[] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    pii pos = mp(x, y);
    for (auto it : dir) {
        pii nxt = pos;
        while(inside(nxt = nxt + it)) {
            if (mat[nxt._1][nxt._2] == now + 1) upd(nxt._1, nxt._2, now + 1, 1, dp[x][y][now][1] + mp(1, 0));
            else upd(nxt._1, nxt._2, now, 1, dp[x][y][now][1] + mp(1, 0));
        }
    }
}

void move_rook(int x, int y, int now) {
    const static pii dir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    pii pos = mp(x, y);
    for (auto it : dir) {
        pii nxt = pos;
        while(inside(nxt = nxt + it)) {
            if (mat[nxt._1][nxt._2] == now + 1) upd(nxt._1, nxt._2, now + 1, 2, dp[x][y][now][2] + mp(1, 0));
            else upd(nxt._1, nxt._2, now, 2, dp[x][y][now][2] + mp(1, 0));
        }
    }
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) FOR(j, 1, n) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 1) st = mp(i, j);
            else if (mat[i][j] == n * n) ed = mp(i, j);
        }
    reset(dp, 0x3f);
    reset(dp[st._1][st._2][1], 0);
    REP(i, 3) s.insert(mp(mp(0, 0), mp(mp(st._1, st._2), mp(1, i))));
    pii ans = mp(inf, inf);
    while (!s.empty()) {
        auto u = *(s.begin());
        s.erase(u);
        pii val = u._1;
        int x = u._2._1._1, y = u._2._1._2;
        int now = u._2._2._1, type = u._2._2._2;
        if (val >= ans) break;
        if (dp[x][y][now][type] != val) continue;
        if (now == n * n) {
            ans = min(ans, val);
            continue;
        }

        switch (type) {
            case 0:
                move_knight(x, y, now);
                upd(x, y, now, 1, val + mp(1, 1));
                upd(x, y, now, 2, val + mp(1, 1));
                break;
            case 1:
                move_bishop(x, y, now);
                upd(x, y, now, 0, val + mp(1, 1));
                upd(x, y, now, 2, val + mp(1, 1));
                break;
            case 2:
                move_rook(x, y, now);
                upd(x, y, now, 0, val + mp(1, 1));
                upd(x, y, now, 1, val + mp(1, 1));
                break;
        }
    }
    printf("%d %d\n", ans._1, ans._2);
    return 0;
}