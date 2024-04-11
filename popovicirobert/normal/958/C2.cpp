#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 20000;
const int MAXK = 51;
const int MAXP = 100;

int v[MAXN + 1], sp[MAXN + 1];

int dp1[2][MAXK + 1][MAXP + 1];
int dp2[2][MAXK + 1][MAXP + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, k, p;
    ios::sync_with_stdio(false);
    cin >> n >> k >> p;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        sp[i] = (sp[i - 1] + v[i]) % p;
    }
    for(i = 0; i <= k; i++) {
        for(j = 0; j <= p; j++) {
            if(i != 0)
                dp1[0][i][j] = -MAXN;
            if(!(i == 0 && j == 0))
                dp2[0][i][j] = -MAXN;
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= k; j++) {
            for(int r = 0; r <= p; r++) {
                dp1[i & 1][j][r] = dp2[i & 1][j][r] = -MAXN;
            }
        }
        for(j = 0; j <= k; j++) {
            if(j > 0) {
                dp1[i & 1][j][sp[i]] = max(dp1[1 - i & 1][j - 1][sp[i]] + sp[i], dp2[1 - i & 1][j - 1][sp[i] + 1] + sp[i] + p) - sp[i];
                dp2[i & 1][j][sp[i]] = dp1[i & 1][j][sp[i]];
            }
            if(i == n && j == k) {
                cout << dp1[n & 1][k][sp[i]] + sp[i];
                return 0;
            }
            for(int r = 0; r < p; r++) {
                dp1[i & 1][j][r] = max(dp1[i & 1][j][r], dp1[1 - i & 1][j][r]);
                if(r > 0)
                    dp1[i & 1][j][r] = max(dp1[i & 1][j][r], dp1[i & 1][j][r - 1]);
            }
            for(int r = p - 1; r >= 0; r--) {
                dp2[i & 1][j][r] = max(dp2[i & 1][j][r], dp2[1 - i & 1][j][r]);
                if(r < p - 1)
                    dp2[i & 1][j][r] = max(dp2[i & 1][j][r], dp2[i & 1][j][r + 1]);
            }
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}