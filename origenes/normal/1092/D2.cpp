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

const int maxn = 212345;

int a[maxn], p[maxn], l[maxn], r[maxn];
int n;

int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}

void Union(int u, int v) {
    int fu = Find(u), fv = Find(v);
    if (fu == fv) return;
    if (a[fu] < a[fv]) swap(fu, fv);
    p[fv] = fu;
    l[fu] = min(l[fu], l[fv]);
    r[fu] = max(r[fu], r[fv]);
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", a + i);
        p[i] = l[i] = r[i] = i;
    }
    FOR(i, 1, n) if (a[i] == a[i - 1]) Union(i, i - 1);
    set<pii> s;
    FOR(i, 1, n) s.insert(mp(a[i], Find(i)));
    while (!s.empty()) {
        auto now = *s.begin(); s.erase(s.begin());
        int h = now._1, u = now._2, pu = Find(u);
        if (pu != u) continue;
        if (r[pu] - l[pu] + 1 == n) {
            puts("YES");
            return 0;
        }
        if ((r[pu] - l[pu] + 1) & 1) {
            puts("NO");
            return 0;
        }
        vector<int> idx;
        if (l[pu] > 1) idx.eb(Find(l[pu] - 1));
        if (r[pu] < n) idx.eb(Find(r[pu] + 1));
        int v = idx[0];
        if (idx.size() > 1) {
            if (a[idx[1]] == a[v]) {
                Union(v, pu);
                Union(v, idx[1]);
            } else v = idx[1];
        }
        Union(v, pu);
        int par = Find(pu);
        s.insert(mp(a[par], par));
    }
}