#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = 998244353;
const int MAXN = 5000;

inline void add(int &x, int y) {
    x += y;
    if(x >= MOD)
        x -= MOD;
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

int dp[MAXN + 1][MAXN + 1];
int fr[MAXN + 1], inv[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> arr(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        fr[arr[i]]++;
        inv[i] = lgput(i, MOD - 2);
    }

    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());

    int sz = (int) arr.size() - 1;
    fr[0] = 1;

    for(i = 1; i <= n; i++) {
        int sum = 0;
        for(j = sz; j >= 0; j--) {
            dp[i][j] = (max(fr[arr[j]] - 1, 0) + sum) % MOD;
            mul(dp[i][j], inv[i]);

            add(sum, (1LL * fr[arr[j]] * dp[i - 1][j]) % MOD);
        }
    }

    cout << dp[n][0];

    //cin.close();
    //cout.close();
    return 0;
}