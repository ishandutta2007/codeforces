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

const int maxn = 412345;

vector<pii> e;
int n, d, k;
int to[maxn];

void dfs(int u, int dep, int &cur) {
    while (to[u]) {
        if (e.size() == n - 1) return;
        e.eb(u, cur);
        to[cur] = k - 1;
        int v = cur++;
        if (dep - 1 > 0) dfs(v, dep - 1, cur);
        to[u]--;
    }
}

int main() {
    scanf("%d%d%d", &n, &d, &k);
    if (n == 1) {
        puts("NO");
        return 0;
    }
    if (n == 2) {
        puts(d == 1? "YES\n1 2" : "NO");
        return 0;
    }
    if (k == 1 || d > n - 1) {
        puts("NO");
        return 0;
    }
    FOR(i, 1, d) e.eb(i, i + 1);
    FOR(i, 2, d) to[i] = k - 2;
    int now = d + 2;
    FOR(i, 2, d) dfs(i, min(i - 1, d + 1 - i), now);
    if (e.size() == n - 1) {
        puts("YES");
        for (auto it : e) printf("%d %d\n", it._1, it._2);
    } else puts("NO");
}