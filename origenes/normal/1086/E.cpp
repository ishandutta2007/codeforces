#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

const int maxn = 2123;
const ll MOD = 998244353;

ll fac[maxn], dp[maxn][maxn], ans, D[maxn];
int n, a[maxn][maxn];
pii way[maxn][maxn];

int main() {
    scanf("%d", &n);
    fac[0] = 1;
    FOR(i, 1, n) fac[i] = fac[i - 1] * i % MOD;
    dp[0][0] = 1;
    FOR(i, 1, n) {
        dp[i][0] = fac[i];
        FOR(j, 1, i) {
            dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - 1]) % MOD;
            if (dp[i][j] < 0) dp[i][j] += MOD;
        }
    }
    D[0] = 1;
    FOR(i, 1, n) D[i] = D[i - 1] * dp[n][n] % MOD;
    FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &a[i][j]);
    FOR(i, 1, n) {
        ordered_set<int> s[2];
        FOR(j, 1, n) s[1].insert(j);
        FOR(j, 1, n) {
            way[i][j]._1 = s[0].order_of_key(a[i][j]);
            if (a[i - 1][j] < a[i][j] && s[0].find(a[i - 1][j]) != s[0].end()) way[i][j]._1--;
            way[i][j]._2 = s[1].order_of_key(a[i][j]);
            if (a[i - 1][j] < a[i][j] && s[1].find(a[i - 1][j]) != s[1].end()) way[i][j]._2--;
            s[0].erase(a[i][j]), s[1].erase(a[i][j]);
            if (s[1].find(a[i - 1][j]) != s[1].end()) {
                s[1].erase(a[i - 1][j]);
                s[0].insert(a[i - 1][j]);
            }
        }
    }
    FOR(i, 1, n)
        ans = (ans + way[1][i]._2 * fac[n - i] % MOD * D[n - 1]) % MOD;
    FOR(i, 2, n) {
        unordered_map<int, int> m;
        FOR(j, 1, n) {
            m[a[i - 1][j]]++;
            int cnt = 2 * j - 1 - m.size();
            ans = (ans + way[i][j]._1 * dp[n - j][n - 2 * j + cnt + 1] % MOD * D[n - i]) % MOD;
            ans = (ans + way[i][j]._2 * dp[n - j][n - 2 * j + cnt] % MOD * D[n - i]) % MOD;
            m[a[i][j]]++;
        }
    }
    printf("%lld", ans);
}