#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int n, a, b, ans[c], dp[c][c];
string s;
int main()
{
    cin >> n >> a >> b >> s;
    for (int i=1; i<=n; i++) {
        ans[i]=ans[i-1]+a;
        for (int j=1; j<i; j++) {
            if (s[i-1]==s[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            ans[i]=min(ans[i], ans[max(j, i-dp[i][j])]+b);
        }
    }
    cout << ans[n] << "\n";
    return 0;
}