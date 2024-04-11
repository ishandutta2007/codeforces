#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5 + 5;

char str[MAXN + 1];

int dp1[MAXN + 1][2], dp2[MAXN + 1][2];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> str + 1;
    int n = strlen(str + 1);
    for(i = 1; i <= n; i++) {
        if(str[i] == 'b')
            dp1[i][0] = dp1[i - 1][1] + 1;
        else
            dp1[i][1] = dp1[i - 1][0] + 1;
    }
    for(i = n; i >= 1; i--) {
        if(str[i] == 'b')
            dp2[i][0] = dp2[i + 1][1] + 1;
        else
            dp2[i][1] = dp2[i + 1][0] + 1;
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        ans = max(ans, max(dp1[i][0], dp1[i][1]));
    }
    if(str[1] != str[n]) {
        ans = max(ans, max(dp2[1][0] + dp1[n][1], dp2[1][1] + dp1[n][0]));
    }
    ans = min(ans, n);
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}