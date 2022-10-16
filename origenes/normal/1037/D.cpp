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

const int maxn = 212345;

vector<int> G[maxn];
set<int> child[maxn];
int p[maxn], n;
bool done[maxn];

void dfs(int u, int f) {
    for (int v : G[u]) {
        if (v == f) continue;
        child[u].insert(v);
        dfs(v, u);
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1, -1);
    child[0].insert(1);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int sz = child[u].size();
        while (sz--) {
            int now;
            scanf("%d", &now);
            if (!child[u].count(now)) {
                puts("No");
                return 0;
            }
            q.push(now);
        }
    }
    puts("Yes");
    return 0;
}