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

const int maxn = 15;

int n, m;
pii a[maxn], b[maxn];
vector<int> G[2][maxn];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) {
        scanf("%d%d", &a[i]._1, &a[i]._2);
        G[0][a[i]._1].pb(a[i]._2);
        G[0][a[i]._2].pb(a[i]._1);
    }
    REP(i, m) {
        scanf("%d%d", &b[i]._1, &b[i]._2);
        if (b[i]._1 > b[i]._2) swap(b[i]._1, b[i]._2);
        G[1][b[i]._1].pb(b[i]._2);
        G[1][b[i]._2].pb(b[i]._1);
    }
    int cnt[10] = {0};
    REP(i, n) {
        int now = 0;
        int sz = G[1][a[i]._1].size();
        if (!sz || (sz == 1 && G[1][a[i]._1][0] == a[i]._2));
        else {
            now++;
            cnt[a[i]._1] = 1;
        }
        sz = G[1][a[i]._2].size();
        if (!sz || (sz == 1 && G[1][a[i]._2][0] == a[i]._1));
        else {
            now++;
            cnt[a[i]._2] = 1;
        }
        if (now == 2) {
            puts("-1");
            return 0;
        }
    }
    REP(i, m) {
        int now = 0;
        int sz = G[0][b[i]._1].size();
        if (!sz || (sz == 1 && G[0][b[i]._1][0] == b[i]._2));
        else {
            now++;
            cnt[b[i]._1] = 1;
        }
        sz = G[0][b[i]._2].size();
        if (!sz || (sz == 1 && G[0][b[i]._2][0] == b[i]._1));
        else {
            now++;
            cnt[b[i]._2] = 1;
        }
        if (now == 2) {
            puts("-1");
            return 0;
        }
    }
    int tot = 0, n;
    FOR(i, 1, 9) {
        if (cnt[i]) {
            n = i;
            tot++;
        }
    }
    if (tot == 1) printf("%d\n", n);
    else puts("0");
    return 0;
}