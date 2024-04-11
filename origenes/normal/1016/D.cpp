#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123;

int n, m, a[maxn], b[maxn], ans[maxn][maxn];

int main() {
    scanf("%d%d", &n, &m);
    int check = 0;
    REP(i, n) {
        scanf("%d", &a[i]);
        check ^= a[i];
    }
    REP(i, m) {
        scanf("%d", &b[i]);
        check ^= b[i];
    }
    if (check) {
        puts("NO");
        return 0;
    }
    puts("YES");
    int now = 0;
    FOR(i, 1, m - 1) now ^= b[i];
    now ^= a[0];
    printf("%d ", now);
    FOR(i, 1, m - 1) printf("%d ", b[i]);
    puts("");
    FOR(i, 1, n - 1) {
        printf("%d ", a[i]);
        FOR(j, 1, m - 1) printf("0 ");
        puts("");
    }
    return 0;
}