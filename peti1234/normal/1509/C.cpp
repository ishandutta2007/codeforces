#include <bits/stdc++.h>

using namespace std;
const int c=2002;
long long n, bal, jobb, t[c], dp[c][c];
bool v[c][c];
long long solve(int a, int b) {
    if (a==b) {
        return 0;
    }
    if (!v[a][b]) {
        dp[a][b]+=t[b]-t[a];
        dp[a][b]+=min(solve(a+1, b), solve(a, b-1));
        v[a][b]=1;
    }
    return dp[a][b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    cout << solve(1, n) << "\n";
    return 0;
}