#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long w, n, t[c], dp[c], o=0;
long long s(int a) {
    return max(o, max(t[a-1], t[a+1])-t[a]+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        dp[2]=s(2);
        for (int i=3; i<n; i++) {
            dp[i]=dp[i-2]+s(i);
            if (i%2) dp[i]=min(dp[i], dp[i-3]+s(i));
        }
        long long ans=dp[n-1];
        if (n%2==0) {
            ans=min(ans, dp[n-2]);
        }
        cout << ans << "\n";
        for (int i=1; i<=n; i++) {
            t[i]=0, dp[i]=0;
        }
    }
    return 0;
}
/*
1
8
1 10 11 1 10 11 10 1
*/