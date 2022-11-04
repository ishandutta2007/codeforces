#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

int dp[101];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, i, j, x;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(i = 1; i <= 100; i++) {
        for(j = 2; j <= 7; j++) {
            if(i >= j && dp[i - j] > -1) {
                dp[i] = dp[i - j] + 1;
            }
        }
    }
    while(t > 0) {
        t--;
        cin >> x;
        cout << dp[x] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}