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

const int maxn = 112345;
const int maxm = 11;

int a[maxm][maxn], n, m, pos[maxm][maxn];
int ans[maxn];
bool vis[maxn];

bool check(const int *cur, int now) {
    FOR(i, 1, m) {
        if (cur[i] == n + 1) return false;
        if (a[i][cur[i]] != now) return false;
    }
    return true;
}

void go(int *cur, int now) {
    int cnt = 0;
    while (check(cur, now)) {
        vis[now] = true;
        FOR(i, 1, m) cur[i]++;
        now = a[1][cur[1]];
        cnt++;
    }
    ans[cnt]++;
}

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) FOR(j, 1, n) {
            scanf("%d", &a[i][j]);
            pos[i][a[i][j]] = j;
        }
    FOR(j, 1, n) {
        int now = a[1][j];
        if (!vis[now]) {
            int cur[11] = {};
            FOR(i, 1, m) cur[i] = pos[i][now];
            go(cur, now);
        }
    }
    ll res = 0;
    FOR(i, 1, n) res += ll(i) * (i + 1) / 2 * ans[i];
    printf("%lld\n", res);
}