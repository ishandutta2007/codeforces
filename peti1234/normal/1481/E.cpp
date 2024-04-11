#include <bits/stdc++.h>

using namespace std;
const int c=500002;
int n, t[c], db[c], pos[c], ut[c], dp[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pos[i]=db[t[i]];
        db[t[i]]++;
        ut[t[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        dp[i]=max(dp[i], dp[i-1]);
        int ert=dp[i]+db[t[i]]-pos[i];
        if (pos[i]) {
            dp[n+1]=max(dp[n+1], ert);
        } else {
            dp[ut[t[i]]+1]=max(dp[ut[t[i]]+1], dp[i]+db[t[i]]-pos[i]);
        }
    }
    cout << n-dp[n+1] << "\n";
    return 0;
}