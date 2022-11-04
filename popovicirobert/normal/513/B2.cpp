#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = 50;

ll dp[MAXN + 1][MAXN + 1];
int sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, j;
    ll m;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> m;
    for(i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }
    for(int len = 1; len <= n; len++) {
        for(i = 1; i + len <= n; i++) {
            dp[i][i + len] = dp[i + 1][i + len] + dp[i][i + len - 1];
            dp[i][i + len] = min(dp[i][i + len], INF);
        }
    }
    int l = 1, r = n;
    int cur = 1;
    while(l != r) {
        if(m > dp[l + 1][r]) {
            m -= dp[l + 1][r];
            sol[r] = cur;
            r--;
        }
        else {
            sol[l] = cur;
            l++;
        }
        cur++;
    }
    for(i = 1; i <= n; i++) {
        if(sol[i] == 0) {
            cout << n << " ";
        }
        else {
            cout << sol[i] << " ";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}