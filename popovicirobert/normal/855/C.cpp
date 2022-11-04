#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 1e5;
const int MOD = (int) 1e9 + 7;

vector <int> g[MAXN + 1];

ll dp[MAXN + 1][11][3];
// nod, nr. k, val < sau > sau == k
int m, k, x;

void dfs(int nod, int par) {
    int nrson = 0;
    for(auto it : g[nod]) {
        if(par != it) {
            nrson++;
            dfs(it, nod);
        }
    }
    if(nrson == 0) {
        dp[nod][0][0] = k - 1;
        dp[nod][1][1] = 1;
        dp[nod][0][2] = m - k;
        return ;
    }
    vector <ll> dp0(11, 0); // < k
    vector <ll> dp1(11, 0); // != k
    vector <ll> dp2(11, 0); // > k
    nrson = 0;
    for(auto it : g[nod]) {
        if(it != par) {
            nrson++;
            if(nrson == 1) {
                for(int i = x; i >= 0; i--) {
                    dp0[i] = (dp[it][i][0] + dp[it][i][1] + dp[it][i][2]) % MOD;
                    dp1[i] = dp[it][i][0];
                    dp2[i] = (dp[it][i][0] + dp[it][i][2]) % MOD;
                }
            }
            else {
                for(int i = x; i >= 0; i--) {
                    for(int j = 0; j <= i; j++) {
                        dp0[i] = (dp0[i] * (j > 0) + dp0[i - j] * (dp[it][j][0] + dp[it][j][1] + dp[it][j][2])) % MOD;
                        dp1[i] = (dp1[i] * (j > 0) + dp1[i - j] * dp[it][j][0]) % MOD;
                        dp2[i] = (dp2[i] * (j > 0) + dp2[i - j] * (dp[it][j][0] + dp[it][j][2])) % MOD;
                    }
                }
            }
        }
    }
    for(int i = 0; i <= x; i++) {
        dp[nod][i][0] = (dp0[i] * (k - 1)) % MOD;
        if(i < x)
            dp[nod][i + 1][1] = dp1[i];
        dp[nod][i][2] = (dp2[i] * (m - k)) % MOD;
    }
}


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> k >> x;
    dfs(1, 0);
    int ans = 0;
    for(i = 0; i <= x; i++) {
        ans = (1LL * ans + dp[1][i][0] + dp[1][i][1] + dp[1][i][2]) % MOD;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}