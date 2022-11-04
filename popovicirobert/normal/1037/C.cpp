#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

char a[MAXN + 1], b[MAXN + 1];

int dp[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> a + 1 >> b + 1;
    dp[1] = (a[1] != b[1]);
    for(i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + (a[i] != b[i]);
        if(a[i] == b[i - 1] && b[i] == a[i - 1]) {
            dp[i] = min(dp[i], dp[i - 2] + 1);
        }
    }
    cout << dp[n];
    //cin.close();
    //cout.close();
    return 0;
}