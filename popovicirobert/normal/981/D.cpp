#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = 100;

bool dp[MAXN + 1][MAXN + 1];
ll arr[MAXN + 1];

inline bool check(ll mask, int n, int k) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            for(int p = i - 1; p >= 0; p--) {
                if(((arr[i] - arr[p]) & mask) == mask && dp[p][j - 1]) {
                    dp[i][j] = 1;
                    break;
                }
            }
        }
    }
    return dp[n][k];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    ll mask = 0;
    for(int bit = 60; bit >= 0; bit--) {
        if(check(mask | (1LL << bit), n, k))
            mask |= (1LL << bit);
    }
    cout << mask;
    //cin.close();
    //cout.close();
    return 0;
}