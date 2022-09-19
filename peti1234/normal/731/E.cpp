#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, t[c], pref[c], dp[c], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pref[i]=pref[i-1]+t[i];
    }
    maxi=pref[n];
    for (int i=n-1; i>=1; i--) {
        dp[i]=maxi;
        maxi=max(maxi, pref[i]-dp[i]);
    }
    cout << dp[1] << "\n";
    return 0;
}