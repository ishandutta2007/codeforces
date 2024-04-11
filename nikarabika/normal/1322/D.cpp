//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2000 + 20,
      maxm = 2048,
      maxl = 11;
const LL INF = 1e18;
LL dp[maxn][maxm],
   pd[maxn][maxm];
LL sum[maxn + maxm],
   prof[maxn + maxm],
   cost[maxn],
   lev[maxn],
   mx[maxn];
int n, m;

LL profof(int l1, int l2, int mask) {
    LL cur = prof[l1];
    if (l1 < l2)
        return cur;
    int nmask = mask + 1;
    int len = __builtin_ctz(nmask);
    cur = sum[l1 + len + 1] - sum[l1];
    return cur;
}

int go(int l1, int l2, int mask) {
    if (l2 - l1 > maxl)
        return 1;
    return ((mask << (l2 - l1)) + 1) & (maxm - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> lev[i], lev[i]--;
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n + m; i++)
        cin >> prof[i];
    for (int i = 0; i + 1 < maxn + maxm; i++)
        sum[i + 1] = sum[i] + prof[i];

    for (int i = 0; i < maxn; i++) {
        pd[i][0] = prof[i + maxl];
        for (int j = 1; j < maxm; j++) {
            dp[i][j] = -INF;
            pd[i][j] = -INF;
        }
    }

    for (int i = 0; i < n; i++) {
        LL ndp[maxm], npd[maxm];
        int row = lev[i];
        LL single_prof = prof[row] - cost[i];
        memcpy(ndp, dp[row], sizeof ndp);
        memcpy(npd, pd[row], sizeof npd);
        for (int ii = row + maxl + 1; ii < maxn; ii++) {
            smax(ndp[1], mx[ii] + single_prof);
            smax(npd[1], mx[ii] + single_prof + prof[row + maxl]);
        }
        for (int ii = row; ii <= row + maxl and ii < maxn; ii++)
            for (int j = 0; j < maxm; j++) {
                int dl = ii - row;
                int nmask = (j << dl) + 1;
                if (dl == 0) {
                    if (nmask < maxm) {
                        int len = __builtin_ctz(nmask);
                        LL curprof = single_prof + sum[row + len + 1] - sum[row + 1];
                        nmask &= maxm - 1;
                        smax(ndp[nmask], dp[ii][j] + curprof);
                        smax(npd[nmask], pd[ii][j] + curprof);
                    }
                    else {
                        LL rprof = sum[row + maxl] - sum[row + 1];
                        nmask &= maxm - 1;
                        smax(ndp[nmask], pd[ii][j] + rprof + single_prof);
                        smax(npd[nmask], pd[ii][j] + rprof + prof[row + maxl] + single_prof);
                    }
                }
                else {
                    int out = nmask >> maxl;
                    nmask &= maxm - 1;
                    int len = __builtin_ctz(out + 1);
                    smax(ndp[nmask], dp[ii][j] + single_prof);
                    if (out + 1 != (1 << dl)) {
                        LL pdmore = sum[row + maxl + len + 1] - sum[row + maxl];
                        smax(npd[nmask], dp[ii][j] + pdmore + single_prof);
                    }
                    else {
                        LL pdmore = sum[row + maxl + dl] - sum[row + maxl];
                        smax(npd[nmask], pd[ii][j] + pdmore + single_prof);
                    }
                }
            }
        memcpy(dp[row], ndp, sizeof ndp);
        memcpy(pd[row], npd, sizeof npd);
        mx[row] = *max_element(ndp, ndp + maxm);
    }
//    for (int i = 0; i < 3; i++, cout << endl)
//        for (int j = 0; j < maxm; j++)
//            cout << dp[i][j] << ' ';
    cout << *max_element(mx, mx + maxn) << '\n';
	return 0;
}