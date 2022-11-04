#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int INF = 1e9;
const int MAXN = 500;

string str;
vector <int> v[MAXN + 1];

int best[MAXN + 1][MAXN + 1];

int dp[2][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m, k;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) {
        cin >> str;
        for(j = 0; j < str.size(); j++) {
            if(str[j] == '1')
                v[i].push_back(j);
        }
    }
    for(i = 1; i <= n; i++) {
        int sz = v[i].size();
        for(j = 0; j < sz; j++)
            best[i][j] = INF;
        for(int a = 0; a < sz; a++) {
            for(int b = a; b < sz; b++) {
                best[i][sz - (b - a + 1)] = min(best[i][sz - (b - a + 1)], v[i][b] - v[i][a] + 1);
            }
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= k; j++) {
            dp[i & 1][j] = INF;
        }
        for(j = 0; j <= k; j++) {
            for(int a = 0; a <= j; a++) {
                dp[i & 1][j] = min(dp[i & 1][j], dp[1 - i & 1][j - a] + best[i][a]);
            }
        }
    }
    int ans = INF;
    for(i = 0; i <= k; i++)
        ans = min(ans, dp[n & 1][i]);
    cout << dp[n & 1][k];
    //cin.close();
    //cout.close();
    return 0;
}