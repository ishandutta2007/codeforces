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

int deg[maxn], n, cnt;
double s;

int main() {
    scanf("%d%lf", &n, &s);
    FOR(i, 1, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        deg[u]++, deg[v]++;
    }
    FOR(i, 1, n) if (deg[i] == 1) cnt++;
    printf("%.10lf", 2 * s / cnt);
}