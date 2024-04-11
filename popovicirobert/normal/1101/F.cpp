#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = 400;
const int MAXM = 250000;
const int INF = 1e9;

int arr[MAXN + 1];

struct Query {
    int c, r;
};

vector < Query > qry[MAXN + 1][MAXN + 1];

int dp[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(i = 1; i <= m; i++) {
        int s, f, c, r;
        cin >> s >> f >> c >> r;
        qry[s][f].push_back({c, r + 1});
    }
    ll ans = 0;
    for(int a = 1; a <= n; a++) {
        for(i = 0; i <= n; i++) {
            for(j = a; j <= n; j++) {
                dp[i][j] = INF;
            }
        }
        dp[0][a] = 0;
        for(i = 1; i <= n + 1; i++) {
            int pos = a;
            for(j = a; j <= n; j++) {
                while(pos < j && max(dp[i - 1][pos], arr[j] - arr[pos]) >= max(dp[i - 1][pos + 1], arr[j] - arr[pos + 1])) {
                    pos++;
                }
                dp[i][j] = max(dp[i - 1][pos], arr[j] - arr[pos]);
            }
        }
        for(i = a; i <= n; i++) {
            for(auto it : qry[a][i]) {
                ans = max(ans, 1LL * dp[it.r][i] * it.c);
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}