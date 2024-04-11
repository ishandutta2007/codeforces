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

const int maxn = 2123;

char mat[maxn][maxn];
int dp[maxn][maxn], n, k;

inline bool inside(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= n;
}

int main() {
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) scanf("%s", mat[i] + 1);
    dp[1][1] = (mat[1][1] > 'a');
    FOR(i, 2, n) {
        dp[1][i] = dp[1][i - 1] + (mat[1][i] > 'a');
        dp[i][1] = dp[i - 1][1] + (mat[i][1] > 'a');
    }
    FOR(i, 2, n) FOR(j, 2, n) dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (mat[i][j] > 'a');
    set<pii> ans;
    ans.insert(mp(0, 1));
    int now = 0;
    FOR(i, 1, n) FOR(j, 1, n) {
            if (dp[i][j] > k) continue;
            if (i + j - 1 == now) ans.insert(mp(i, j));
            else if (i + j - 1 > now) {
                ans.clear();
                ans.insert(mp(i, j));
                now = i + j - 1;
            }
        }
    REP(i, now) putchar('a');
    if (now == 2 * n - 1) return 0;
    REP(i, 2 * n - 1 - now) {
        set<pii> cur;
        char tmp = 'z' + 1;
        for (auto it : ans) {
            int x = it._1, y = it._2;
            if (inside(x + 1, y)) {
                if (mat[x + 1][y] < tmp) {
                    tmp = mat[x + 1][y];
                    cur.clear();
                    cur.insert(mp(x + 1, y));
                } else if (mat[x + 1][y] == tmp)
                    cur.insert(mp(x + 1, y));
            }
            if (inside(x, y + 1)) {
                if (mat[x][y + 1] < tmp) {
                    tmp = mat[x][y + 1];
                    cur.clear();
                    cur.insert(mp(x, y + 1));
                } else if (mat[x][y + 1] == tmp)
                    cur.insert(mp(x, y + 1));
            }
        }
        putchar(tmp);
        swap(ans, cur);
    }
    return 0;
}