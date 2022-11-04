#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 5e5;
const int MAXK = 5005;
const int INF = (int) 1e9;

int t[MAXN + 1];
int gap[MAXN + 1];

bool cmp(int a, int b) {
    return t[a + 1] - t[a] < t[b + 1] - t[b];
}

int dp[2 * MAXK + 1][MAXK + 1];
int v[2 * MAXK + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, k;
    ios::sync_with_stdio(false);
    cin >> k >> n;
    for(i = 1; i <= n; i++) {
        cin >> t[i];
    }
    sort(t + 1, t + n + 1);
    for(i = 1; i < n; i++) {
        gap[i] = i;
    }
    sort(gap + 1, gap + n, cmp);
    n = min(n - 1, 2 * k + 5);
    for(i = 1; i <= n; i++) {
        v[i] = gap[i];
    }
    sort(v + 1, v + n + 1);
    for(j = 1; j <= k; j++) {
        dp[0][j] = INF;
    }
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j > 0) {
                if(v[i] > v[i - 1] + 1 || i == 1) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + t[v[i] + 1] - t[v[i]]);
                }
                else if(i > 1) {
                    dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + t[v[i] + 1] - t[v[i]]);
                }
            }
        }
    }
    cout << dp[n][k];
    //cin.close();
    //cout.close();
    return 0;
}