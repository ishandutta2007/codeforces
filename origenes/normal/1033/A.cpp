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

const int maxn = 1234;
bool vis[maxn][maxn], no[maxn][maxn];

pii a, b, c;
int n;

int main() {
    scanf("%d", &n);
    scanf("%d%d%d%d%d%d", &a._1, &a._2, &b._1, &b._2, &c._1, &c._2);
    REP(i, n + 2) no[0][i] = no[n + 1][i] = no[i][0] = no[i][n + 1] = true;
    FOR(i, 1, n) no[a._1][i] = no[i][a._2] = true;
    FOR(i, 1, n) {
        if (a._1 - i > 0) {
            if (a._2 - i > 0) no[a._1 - i][a._2 - i] = true;
            if (a._2 + i <= n) no[a._1 - i][a._2 + i] = true;
        }
        if (a._1 + i <= n) {
            if (a._2 - i > 0) no[a._1 + i][a._2 - i] = true;
            if (a._2 + i <= n) no[a._1 + i][a._2 + i] = true;
        }
    }
    queue<pii> q;
    q.push(b);
    vis[b._1][b._2] = true;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        FOR(i, -1, 1) FOR(j, -1, 1) if (!vis[u._1 + i][u._2 + j] && !no[u._1 + i][u._2 + j]) {
                    vis[u._1 + i][u._2 + j] = true;
                    q.push({u._1 + i, u._2 + j});
                }
    }
    puts(vis[c._1][c._2] ? "YES" : "NO");
    return 0;
}