#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, t[c][2], dp[c][2];
void solve() {
    cin >> n;
    for (int j=0; j<2; j++) {
        for (int i=1; i<=n; i++) {
            cin >> t[i][j];
            t[i][j]++;
        }
    }
    dp[n][0]=max({t[n][0]+2, t[n][1]+1, t[n-1][1]});
    dp[n][1]=max({t[n][1]+2, t[n][0]+1, t[n-1][0]});
    for (int i=n-1; i>=2; i--) {
        for (int j=0; j<2; j++) {
            dp[i][j]=max({dp[i+1][j]+1, t[i][j]+2*(n-i+1), t[i-1][1-j]});
        }
    }
    long long ans=1e10, ert=0;
    int s=1, o=0, cnt=1;
    while (cnt<2*n) {
        if (s+1<=n) {
            ans=min(ans, max(ert+2*n-cnt, dp[s+1][o]));
        }
        cnt++, ert++;
        if ((s+o)%2) {
            o=1-o;
        } else {
            s++;
        }
        ert=max(ert, t[s][o]);
    }
    ans=min(ans, ert);
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}