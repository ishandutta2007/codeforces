#include <bits/stdc++.h>

using namespace std;
int n;
string q;
long long t[101];
long long dp[101][101][101];
long long solve(int s, int f, int p)
{
    if (s>f) {
        return 0;
    }
    if (s==f) {
        return t[p];
    }
    long long ans=dp[s][f][p];
    if (ans!=0) {
        return ans;
    }
    ans=t[p]+solve(s+1, f, 1);
    for (int i=s+1; i<=f; i++) {
        if (q[s-1]==q[i-1]) {
            ans=max(ans, solve(s+1, i-1, 1)+solve(i, f, p+1));
        }
    }
    dp[s][f][p]=ans;
    return ans;
}
int main()
{
    cin >> n;
    cin >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    cout << solve(1, n, 1);
    return 0;
}