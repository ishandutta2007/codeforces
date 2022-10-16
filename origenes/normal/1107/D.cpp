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

const int maxn = 5212;

char tbl[maxn];
bool mat[maxn][maxn];
int n, s[maxn][maxn];
unordered_map<char, int> rec;

int main() {
    scanf("%d", &n);
    REP(i, 10) rec[i + '0'] = i;
    REP(i, 6) rec[i + 'A'] = i + 10;
    FOR(i, 1, n) {
        scanf("%s", tbl + 1);
        FOR(j, 1, n >> 2) {
            int now = rec[tbl[j]];
            REP(k, 4) mat[i][(j - 1) * 4 + 4 - k] = bool((now >> k) & 1);
        }
        FOR(j, 1, n) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i][j];
    }
    int ans = 1;
    FOR(x, 1, n) if (n % x == 0) {
            int inc = n / x;
            FOR(i, 1, inc) FOR(j, 1, inc) {
                    int now = s[i * x][j * x] - s[i * x][(j - 1) * x] - s[(i - 1) * x][j * x] + s[(i - 1)* x][(j - 1) * x];
                    if (!now || now == x * x) continue;
                    else goto label;
                }
            ans = x;
            label:;
        }
    printf("%d", ans);
}