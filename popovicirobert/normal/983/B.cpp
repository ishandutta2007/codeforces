#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = 5005;

int arr[MAXN + 1];

int dp[MAXN + 1][MAXN + 1];
int mx[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, q;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][i] = arr[i];
    }
    for(int len = 2; len <= n; len++) {
        for(i = 1; i + len <= n + 1; i++) {
            dp[i][i + len - 1] = (dp[i][i + len - 2] ^ dp[i + 1][i + len - 1]);
        }
    }
    for(i = n; i >= 1; i--) {
        for(j = i; j <= n; j++) {
            mx[i][j] = max(dp[i][j], max(mx[i + 1][j], mx[i][j - 1]));
        }
    }
    cin >> q;
    while(q > 0) {
        q--;
        int l, r;
        cin >> l >> r;
        cout << mx[l][r] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}