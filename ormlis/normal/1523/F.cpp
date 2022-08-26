#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int n, m;
int xa[14], ya[14];
int xb[100], yb[100];
int ts[100];

//vector<pair<int, int>> gmask[1 << 14];
int dp1[1 << 14][100];
int dp2[1 << 14][101];
int dist1[14][1 << 14];
int dist2[100][1 << 14];

void solve() {
    cin >> n >> m;
    range(i, n) cin >> xa[i] >> ya[i];
    range(i, m) cin >> xb[i] >> yb[i] >> ts[i];
    vector<int> ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &i, const int &j) {
        return ts[i] < ts[j];
    });
    int fl = 1 << n;
    range(i, n) {
        range(mask, fl) {
            dist1[i][mask] = INFi;
            range(j, n) {
                if ((1 << j) & mask) {
                    dist1[i][mask] = min(dist1[i][mask], abs(xa[i] - xa[j]) + abs(ya[i] - ya[j]));
                }
            }
        }
    }
    range(i, m) {
        range(mask, fl) {
            dist2[i][mask] = INFi;
            range(j, n) {
                if ((1 << j) & mask) {
                    dist2[i][mask] = min(dist2[i][mask], abs(xb[i] - xa[j]) + abs(yb[i] - ya[j]));
                }
            }
        }
    }
    /*
    range(start, fl) {
        dist[start] = 0;
        int m2 = start ^ (fl - 1);
        vector<int> was;
        for(int mask2 = m2; mask2 > 0; mask2 = ((mask2 - 1) & m2)) {
            was.push_back(mask2);
        }
        was.push_back(start);
        reverse(all(was));
        for(auto &mask : was) {
            int d = dist[mask];
            dist[mask] = INFi;
            range(i, n) {
                if ((1 << i) & mask) continue;
                int mask2 = mask ^ (1 << i);
                dist[mask2] = min(dist[mask2], d + dist1[i][mask]);
            }
            gmask[start].emplace_back(mask, d);
        }
    }*/
    range(i, fl) range(j, m) dp1[i][j] = -INFi;
    range(i, fl) range(j, m + 1) dp2[i][j] = INFi;
    range(i, m) {
        dp1[0][i] = 1;
    }
    range(i, n) {
        dp2[1 << i][0] = 0;
    }
    int answer = 1;
    range(mask, fl) {
        for(int i = m - 1; i >= 0; --i) dp2[mask][i] = min(dp2[mask][i], dp2[mask][i + 1]);
        int i2 = 0;
        auto check = [&] (int tm) {
            while(i2 < m && ts[ord[i2]] <= dp2[mask][tm]) {
                int i = ord[i2++];
                if (dp1[mask][i] == -INFi) continue;
                int cnt = dp1[mask][i];
                dp2[mask][cnt] = min(dp2[mask][cnt], ts[i]);
                range(j, m) {
                    if (i == j) continue;
                    int d = abs(xb[i] - xb[j]) + abs(yb[i] - yb[j]);
                    if (ts[i] + d > ts[j]) continue;
                    dp1[mask][j] = max(dp1[mask][j], cnt + 1);
                    answer = max(answer, cnt + 1);
                }
                range(j, n) {
                    if ((1 << j) & mask) continue;
                    dp2[mask ^ (1 << j)][cnt] = min(dp2[mask ^ (1 << j)][cnt], ts[i] + abs(xa[j] - xb[i]) + abs(ya[j] - yb[i]));
                }
            }
        };
        range(i, m + 1) {
            check(i);
            int t = dp2[mask][i];
            if (dp2[mask][i] == INFi) continue;
            range(j, n) {
                if ((1 << j) & mask) continue;
                if (dist1[j][mask] == INFi) continue;
                dp2[mask^(1<<j)][i] = min(dp2[mask^(1<<j)][i], dp2[mask][i] + dist1[j][mask]);
            }
            range(j, m) {
                if (dist2[j][mask] == INFi) continue;
                int tm = t + dist2[j][mask];
                if (tm > ts[j]) continue;
                dp1[mask][j] = max(dp1[mask][j], i + 1);
                answer = max(answer, i + 1);
            }
        }
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}