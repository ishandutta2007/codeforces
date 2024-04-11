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

const int maxn = 5123;

int n, c[maxn], l[maxn], r[maxn];
int dp[maxn][maxn];

int main() {
    reset(dp, 0x3f);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", c + i);
    int nowl = 1;
    FOR(i, 1, n) {
        if (c[i] == c[nowl]) l[i] = nowl;
        else {
            l[i] = i;
            nowl = i;
        }
    }
    int nowr = n;
    ROF(i, n, 1) {
        if (c[i] == c[nowr]) r[i] = nowr;
        else {
            r[i] = i;
            nowr = i;
        }
    }
    FOR(i, 1, n) dp[l[i]][r[i]] = 0;
    REP(dif, n) FOR(i, 1, n - dif) {
            int L = i, R = i + dif;
            if (L > 1 && R < n && c[L - 1] == c[R + 1]) {
                dp[l[L - 1]][r[R + 1]] = min(dp[l[L - 1]][r[R + 1]], dp[L][R] + 1);
                continue;
            }
            if (L > 1) dp[l[L - 1]][R] = min(dp[l[L - 1]][R], dp[L][R] + 1);
            if (R < n) dp[L][r[R + 1]] = min(dp[L][r[R + 1]], dp[L][R] + 1);
        }
    printf("%d", dp[1][n]);
}