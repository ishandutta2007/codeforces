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

const int maxn = 112345;
const int maxp = 17;

int G[maxp][maxp], tot[1 << maxp], cnt[maxp];
bool dp[maxp][maxp][1 << maxp], no[1 << maxp], dp2[1 << maxp];
int n, p;
char s[maxn];

int main() {
    scanf("%d%d", &n, &p);
    scanf("%s", s + 1);
    FOR(i, 1, n) cnt[s[i] - 'a']++;
    REP(i, p) REP(j, p) scanf("%d", &G[i][j]);
    REP(mask, 1 << p) REP(i, p) if (mask & (1 << i))
                tot[mask] += cnt[i];
    REP(i, p) FOR(j, i, p - 1) if (!G[i][j]) {
                int pre = -1, mask = 0;
                REP(k, n) {
                    if (s[k] == i + 'a') {
                        if (pre == -1) pre = i;
                        else if (pre == j) {
                            pre = i;
                            dp[i][j][mask] = true;
                        }
                        mask = 0;
                    } else if (s[k] == j + 'a') {
                        if (pre == -1) pre = j;
                        else if (pre == i) {
                            pre = j;
                            dp[i][j][mask] = true;
                        }
                        mask = 0;
                    } else mask |= 1 << s[k] - 'a';
                }
            }
    REP(i, p) FOR(j, i, p - 1) FOR(mask, 1, (1 << p) - 1) if (!(mask & ((1 << i) | (1 << j)))) {
                    REP(k, p) if (mask & (1 << k)) dp[i][j][mask] |= dp[i][j][mask ^ (1 << k)];
                    if (dp[i][j][mask]) no[mask] = true;
                }
    int ans = 0;
    queue<int> q;
    dp2[0] = true;
    q.push(0);
    while (!q.empty()) {
        int mask = q.front(); q.pop();
        chkmax(ans, tot[mask]);
        REP(i, p) if (!(mask & (1 << i))) {
                int nxt = mask | (1 << i);
                if (!no[nxt] && !dp2[nxt]) {
                    dp2[nxt] = true;
                    q.push(nxt);
                }
            }
    }
    printf("%d", n - ans);
}