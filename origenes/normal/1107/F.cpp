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

const int maxn = 503;
const ll inf = 1e18;

int n;  // number of vertices on each side (tot = 2 * n)
ll W[maxn][maxn];  // weight of the edges
ll Lx[maxn], Ly[maxn];     // potential of each point, indexing from 1 onwards
int lft[maxn];     // lft[v] = the index of the vertex which vertex v of the right is matching to
ll slack[maxn];    // if v is not in T and u is in S, slack[v] = min(Lx[u] + Ly[v] - w[u][v])
bool S[maxn], T[maxn];  // Whether vertex is in an alternating path

inline bool match(int u) {
    S[u] = true;
    FOR(v, 1, n) if (!T[v]) {
            if (Lx[u] + Ly[v] == W[u][v]) {
                T[v] = true;
                if (!lft[v] || match(lft[v])) {
                    lft[v] = u;
                    return true;
                }
            } else {
                slack[v] = min(slack[v], Lx[u] + Ly[v] - W[u][v]);
            }
        }
    return false;
}

inline void update() {
    ll a = inf;
    FOR(i, 1, n) if (!T[i]) a = min(a, slack[i]);
    FOR(i, 1, n) {
        if (S[i]) Lx[i] -= a;
        if (T[i]) Ly[i] += a;
    }
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        ll a, b, k;
        scanf("%lld%lld%lld", &a, &b, &k);
        REP(j, n) W[i][j + 1] = max(0LL, a - b * min(k, ll(j)));
    }
    FOR(i, 1, n) {
        lft[i] = Lx[i] = Ly[i] = 0;
        FOR(j, 1, n) Lx[i] = max(Lx[i], W[i][j]);
    }
    FOR(i, 1, n) {
        FOR(j, 1, n) slack[j] = inf;
        for (;;) {
            FOR(j, 1, n) S[j] = T[j] = false;
            if (match(i)) break;
            update();
        }
    }
    ll ans = 0;
    FOR(i, 1, n) ans += Lx[i] + Ly[i];
    printf("%lld", ans);
}