#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n, a[c], dp[c];
void solve() {
    cin >> n;
    int ans=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        int maxi=0;
        for (int j=max(0, i-512); j<i; j++) {
            //cout << "fontos " << i << " " << j << " " << (a[i]^j) << " " << (a[j]^i) << "\n";
            if ((a[i]^j)>(a[j]^i)) {
                //cout << "lep " << j << " " << i << "\n";
                maxi=max(maxi, dp[j]);
            }
        }
        dp[i]=maxi+1;
        ans=max(ans, dp[i]);
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
5
5 2 4 3 1
*/