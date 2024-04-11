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

const int maxn = 1234;
const ll MOD = 1e9 + 7;

ll C[maxn][maxn];

int main() {
    C[0][0] = 1;
    FOR(i, 1, 1000) {
        C[i][0] = 1;
        FOR(j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (2 * k > n - 1 || 2 * k > m - 1) {
        puts("0");
        return 0;
    }
    printf("%lld\n", C[n - 1][2 * k] * C[m - 1][2 * k] % MOD);
    return 0;
}