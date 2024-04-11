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

const int maxn = 312345;

vector<int> G[maxn];
int pos[maxn], n, m;
struct Person {
    int x, y;
    int diff, id;
    bool operator < (const Person &rhs) const {
        return diff < rhs.diff;
    }
} p[maxn];

ll ans[maxn], sx, sy;

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].id = i;
        p[i].diff = p[i].x - p[i].y;
        sy += p[i].y;
    }
    sort(p + 1, p + n + 1);
    FOR(i, 1, n) pos[p[i].id] = i;
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        int id1 = pos[u], id2 = pos[v];
        G[id1].pb(id2);
        G[id2].pb(id1);
    }
    FOR(i, 1, n) {
        int cntx = i - 1, cnty = n - i;
        sx += p[i - 1].x, sy -= p[i].y;
        ll nowx = sx, nowy = sy;
        for (int j : G[i]) {
            if (j > i) {
                cnty--;
                nowy -= p[j].y;
            } else {
                cntx--;
                nowx -= p[j].x;
            }
        }
        ans[p[i].id] = nowx + ll(cntx) * p[i].y + nowy + ll(cnty) * p[i].x;
    }
    FOR(i, 1, n) printf("%lld ", ans[i]);
}