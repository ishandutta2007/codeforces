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

int n, a[maxn], b[maxn];
map<int, pii> cnt;

int main() {
    scanf("%d", &n);
    int now = 1;
    FOR(i, 1, n) {
        scanf("%d", a + i);
        int to = n - a[i];
        if (cnt.count(to)) {
            b[i] = cnt[to]._1;
            cnt[to]._2--;
            if (!cnt[to]._2) cnt.erase(to);
        } else {
            b[i] = now++;
            if (to - 1) cnt[to] = mp(b[i], to - 1);
        }
    }
    if (cnt.empty()) {
        puts("Possible");
        FOR(i, 1, n) printf("%d ", b[i]);
    } else puts("Impossible");
}