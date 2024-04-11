#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;

const ll INF = 1e18;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector < vector <int> > h(2, vector <int>(n + 1));
    for(i = 0; i < 2; i++) {
        for(j = 1; j <= n; j++) {
            cin >> h[i][j];
        }
    }

    vector < vector <ll> > dp(n + 1, vector <ll>(2, -INF));
    dp[0][0] = dp[0][1] = 0;

    for(i = 1; i <= n; i++) {
        for(j = 0; j < 2; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j ^ 1] + h[j][i]);
            if(i > 1) {
                dp[i][j] = max(dp[i][j], dp[i - 2][j] + h[j][i]);
            }
        }
        for(j = 0; j < 2; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    cout << max(dp[n][0], dp[n][1]);

    return 0;
}