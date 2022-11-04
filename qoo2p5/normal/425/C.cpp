#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()

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

const int N = (int) 1e5 + 123;
const int K = 303;

int n, m, s, e;
int a[N], b[N];
int dp[N][K];

vector<int> pos[N];

void run() {
    cin >> n >> m >> s >> e;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        pos[b[i]].push_back(i);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            dp[i][j] = INF;
        }
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = -1;
    }
    
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < K; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            int p = dp[i - 1][j - 1];
            auto it = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), p);
            if (it != pos[a[i]].end()) {
                int q = *it;
                dp[i][j] = min(dp[i][j], q);
            }
            
            if (i + dp[i][j] + j * e <= s) {
                ans = max(ans, j);
            }
        }
    }
    
    cout << ans << "\n";
}