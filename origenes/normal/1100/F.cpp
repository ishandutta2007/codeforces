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

const int maxn = 512345;

int n, q, p[maxn][20], b[maxn][20];

void go(int a, int u, int pos) {
    ROF(i, 19, 0) if (a & (1 << i)) {
            if (!b[pos][i]) {
                b[pos][i] = a;
                p[pos][i] = u;
                return;
            }
            if (p[pos][i] < u) {
                swap(p[pos][i], u);
                swap(a, b[pos][i]);
            }
            a ^= b[pos][i];
        }
}

int query(int l, int r) {
    int ret = 0;
    ROF(i, 19, 0) if (p[r][i] >= l) ret = max(ret ^ b[r][i], ret);
    return ret;
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        int a;
        scanf("%d", &a);
        memcpy(b[i], b[i - 1], sizeof(b[i]));
        memcpy(p[i], p[i - 1], sizeof(p[i]));
        go(a, i, i);
    }
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
}