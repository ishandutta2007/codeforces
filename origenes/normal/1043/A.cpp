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

const int maxn = 123;

int n, a[maxn];

int main() {
    scanf("%d", &n);
    int st = 0;
    FOR(i, 1, n) {
        scanf("%d", a + i);
        st = max(st, a[i]);
    }
    FOR(k, st, 100000) {
        int tot = 0;
        FOR(i, 1, n) {
            tot -= a[i];
            tot += k - a[i];
        }
        if (tot > 0) {
            printf("%d\n", k);
            return 0;
        }
    }
}