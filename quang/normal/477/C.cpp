#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

string s, p;
int dp[2010][2010], m, n;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> s;
    cin >> p;
    n = s.size();
    m = p.size();
    dp[0][0] = 0;
    s = "Q" + s;
    p = "Q" + p;
    for(int i = 1; i <= n; i++) dp[0][i] = -123456789;
    for(int i = 1; i <= n; i++) {
        int pos1 = i, pos2 = m;
        while(pos1 && pos2) {
            if(s[pos1] == p[pos2]) pos2--;
            pos1--;
        }
        for(int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            if(!pos2 && j >= i - pos1 - m)
                dp[i][j] = max(dp[i][j], dp[pos1][j - (i - pos1 - m)] + 1);
        }
    }
    for(int i = 0; i <= n; i++) cout << dp[n][i] << " ";
    return 0;
}