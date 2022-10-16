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

int n, m, k, b[maxn];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, n) scanf("%d", b + i);
    int ans = b[n] - b[1] + 1;
    vector<int> dis;
    FOR(i, 2, n) dis.eb(b[i] - b[i - 1] - 1);
    sort(all(dis), greater<int>());
    REP(i, k - 1) ans -= dis[i];
    printf("%d", ans);
}