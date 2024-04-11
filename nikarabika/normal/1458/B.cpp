#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

const int maxn = 100 + 10,
      maxn2 = 110 * 110,
      INF = 1e9;
int dp[2][maxn][maxn2];
int a[maxn],
    b[maxn],
    n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int sumb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sumb += b[i];
    }
    for (int j = 0; j < maxn; j++)
        for (int k = 0; k < maxn2; k++)
            dp[0][j][k] = -INF;
    dp[0][0][0] = 0;
    int cur = 0,
        nxt = 1;
    for (int i = 0; i < n; i++, swap(cur, nxt)) {
        memcpy(dp[nxt], dp[cur], sizeof dp[cur]);
        for (int j = 0; j < maxn; j++)
            for (int k = 0; k < maxn2; k++)
                if (j + 1 < maxn and k + a[i] < maxn2)
                    smax(dp[nxt][j + 1][k + a[i]], dp[cur][j][k] + b[i]);
    }
    cout.precision(12);
    for (int j = 1; j <= n; j++) {
        LD best = 0;
        for (int k = 0; k < maxn2; k++) {
            LD curval = min(2 * k, dp[cur][j][k] + sumb) / 2.;
            smax(best, curval);
        }
        cout << fixed << best << ' ';
    }
    cout << '\n';
    return 0;
}