#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int N = 1060;
const int K = 55;
const short SINF = 2000;

int n, p, k;
bool a[N], b[N];

short cnt[N][2];
short pre[N][N];
short dp[N][N][K][2];

void go(short &x, short y) {
    x = max(x, y);
}

void run() {
    cin >> n >> p >> k;
    int cc;
    cin >> cc;
    for (int i = 0; i < cc; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    cin >> cc;
    for (int i = 0; i < cc; i++) {
        int x;
        cin >> x;
        b[x] = 1;
    }
    
    for (int i = 0; i <= n; i++) {
        for (int t = 0; t < k; t++) {
            if (a[i + t]) cnt[i][0]++;
            if (b[i + t]) cnt[i][1]++;
        }
            
        for (int j = 0; j <= n; j++) {
            int l = max(i, j);
            int r = min(i + k, j + k) - 1;
            if (l <= r) {
                for (int t = l; t <= r; t++) {
                    if (a[t] && b[t]) pre[i][j]++;
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int t = 0; t < K; t++) {
                dp[i][j][t][0] = dp[i][j][t][1] = -SINF;
            }
        }
    }
    
    dp[0][0][k][0] = 0;
    dp[0][0][k][1] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= p; j++) {
            for (int t = 1; t < k; t++) {
                for (int q = 0; q < 2; q++) {
                    if (dp[i][j][t][q] == -SINF) continue;
                    
                    go(dp[i + 1][j][t + 1][q], dp[i][j][t][q]); // do nothing
                    
                    int l1 = i + 1 - t;
                    int r1 = l1 + k - 1;
                    int l2 = i + 1;
                    
                    go(dp[r1][j + 1][r1 + 1 - l2][!q], dp[i][j][t][q] + cnt[l2][!q] - pre[l1][l2]); // add !q
                }
            }
            
            {
                go(dp[i][j][k][0], dp[i][j][k][1]); // just update
                if (dp[i][j][k][0] != -SINF) {
                    go(dp[i + 1][j][k][0], dp[i][j][k][0]);
                    go(dp[i + k][j + 2][k][0], dp[i][j][k][0] + cnt[i + 1][0] + cnt[i + 1][1] - pre[i + 1][i + 1]); // add both
                    go(dp[i + 1][j + 1][1][0], dp[i][j][k][0] + cnt[i + 1][0]); // add 0
                    go(dp[i + 1][j + 1][1][1], dp[i][j][k][0] + cnt[i + 1][1]); // add 1
                }
            }
        }
    }
    
    short ans = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= p; j++) {
            for (int t = 0; t < K; t++) {
                for (int q = 0; q < 2; q++) {
                    go(ans, dp[i][j][t][q]);
                }
            }
        }
    }
    
    cout << ans << "\n";
}