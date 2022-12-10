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

const int maxn = 1000 * 1000;
const int maxval = 1000 * 1000;
const int levels = 6;
const LL INF = 1000000LL * 1000000LL * 1000000LL * 2;
LL dp[levels][maxn];

void deqadd(deque<pll> &dq, LL idx, LL val) {
    while (sz(dq) and dq.back().R <= val)
        dq.pop_back();
    dq.push_back(MP(idx, val));
}

void deqrem(deque<pll> &dq, LL idx) {
    while (sz(dq) and dq.front().L <= idx)
        dq.pop_front();
}

inline LL deqget(deque<pll> &dq) {
    return sz(dq) ? dq.front().R : -INF;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    LL k;
    LL F[6];
    cin >> k;
    for (int i = 0; i < 6; i++)
        cin >> F[i];

    for (int j = 0; j <= 9 * (k - 1); j++)
        if (j < maxval)
            dp[0][j] = j / 3 * F[0];
    for (int j = 9 * (k - 1) + 1; j <= 9 * k; j++)
        if (j < maxval)
            if (j % 3 == 0)
                dp[0][j] = j / 3 * F[0];
            else
                dp[0][j] = dp[0][9 * (k - 1)];
    for (int j = 9 * k + 1; j < maxval; j++)
        dp[0][j] = -INF;

    LL mod = 3;
    deque<pll> dq[3];
    for (int i = 1; i < levels; i++) {
        mod *= 10;
        for (int start = 0; start < mod; start++) {
            for (int _ = 0; _ < 3; _++)
                dq[_].clear();
            for (LL j = start, step = 0; j < maxval; j += mod, step++) {
                //dq0
                LL addidx = j;
                deqadd(dq[0], addidx, dp[i - 1][addidx] - step * F[i]);
                LL remidx = j - (3 * (k - 1) + 1) * mod;
                deqrem(dq[0], remidx);
                //if (i == 1)
                //    cerr << "#0 " << deqget(dq[0]) << '\n';

                //dq1
                addidx = j - mod / 3;
                if (addidx >= 0)
                    deqadd(dq[1], addidx, dp[i - 1][addidx] - step * F[i]);
                remidx += mod - mod / 3;
                deqrem(dq[1], remidx);
                //if (i == 1)
                //    cerr << "#1 " << deqget(dq[1]) << '\n';

                //dq2
                addidx = j - mod / 3 * 2;
                if (addidx >= 0)
                    deqadd(dq[2], addidx, dp[i - 1][addidx] - step * F[i]);
                remidx -= mod / 3;
                deqrem(dq[2], remidx);
                //if (i == 1)
                //    cerr << "#2 " << deqget(dq[2]) << '\n';
                
                dp[i][j] = step * F[i] + max(max(deqget(dq[0]), deqget(dq[1])), deqget(dq[2]));

                // using more than 9 * (k - 1)
                for (LL t = 9 * (k - 1) + 1; t <= 9 * k and t * (mod / 3) <= j; t++) {
                    LL curscore = dp[i - 1][j - t * (mod / 3)];
                    curscore += 3 * (k - 1) * F[i];
                    if (t % 9 == 3)
                        curscore += F[i];
                    if (t % 9 == 6)
                        curscore += F[i] + F[i];
                    if (t % 9 == 0)
                        curscore += F[i] + F[i] + F[i];
                    smax(dp[i][j], curscore);
                }
            }
        }
    }
//    for (int i = 0; i < levels; i++, cout << endl)
//        for (int j = 0; j <= 10; j++)
//            cout << dp[i][j] << ' ';
    int q;
    cin >> q;
    int x, y;
    while (q--) {
        int n;
        cin >> n;
        cout << max(0LL, dp[5][n]) << '\n';
    }
	return 0;
}