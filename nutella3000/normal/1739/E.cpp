#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 2e5 + 3;

int n;
int dp[N][2][2];

void run() {
    string tmp[2];
    cin >> n >> tmp[0] >> tmp[1];
    vector s(n, vector<int>(2));
    int count = 0;
    for (int i = 0; i < n; ++i) {
        s[i][0] = tmp[0][i] - '0';
        s[i][1] = tmp[1][i] - '0';
        count += s[i][0] + s[i][1];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j][0] = dp[i][j][1] = inf;
        }
    }
    dp[0][0][0] = 0;

    for (int x = 1; x < n; ++x) {
        for (int y = 0; y < 2; ++y) {
            dp[x][y][0] = min(dp[x-1][y][s[x-1][y^1]], dp[x-1][y][0] + 1);

            if (s[x-1][y]) {
                if (!s[x][y^1]) {
                    chmin(dp[x][y][0], dp[x-1][y^1][0]);
                } else {
                    dp[x][y][1] = dp[x-1][y^1][0] + s[x][y^1];
                }
            }
        }
    }

    int r = inf;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            chmin(r, dp[n-1][i][j]);
    cout << count - r << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}