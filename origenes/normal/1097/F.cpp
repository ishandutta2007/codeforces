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

const int maxn = 112345;
const int maxv = 7123;

bool vis[maxv];
bitset<7001> bs[maxn], q1[maxv], q4[maxv];
int n, q;

int main() {
    FOR(i, 1, 7000) for (int j = 2; j * j <= i; j++) if (i % (j * j) == 0) {
                vis[i] = true;
                break;
            }
    FOR(i, 1, 7000) FOR(j, 1, i) if (i % j == 0) {
                q1[i].set(j);
                if (!vis[i / j]) q4[j].set(i);
            }
    scanf("%d%d", &n, &q);
    while (q--) {
        int op, x, y, z, v;
        scanf("%d", &op);
        switch (op) {
            case 1: {
                scanf("%d%d", &x, &v);
                bs[x] = q1[v];
                break;
            }
            case 2: {
                scanf("%d%d%d", &x, &y, &z);
                bs[x] = bs[y] ^ bs[z];
                break;
            }
            case 3: {
                scanf("%d%d%d", &x, &y, &z);
                bs[x] = bs[y] & bs[z];
                break;
            }
            case 4: {
                scanf("%d%d", &x, &v);
                printf("%d", (bs[x] & q4[v]).count() & 1);
                break;
            }
            default:
                assert(false);
        }
    }
}