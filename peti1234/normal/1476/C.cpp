#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long w, n, dp[c], h[c], a[c], b[c], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, maxi=0;
        for (int i=1; i<=n; i++) {
            cin >> h[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
        }
        maxi=dp[2]=h[2]+1+abs(a[2]-b[2]);
        for (int i=3; i<=n; i++) {
            if (a[i]==b[i]) {
                dp[i]=h[i]+1;
            } else {
                dp[i]=max(h[i]+1+dp[i-1]-(abs(a[i]-b[i])), h[i]+1+abs(a[i]-b[i]));
            }
            maxi=max(maxi, dp[i]);
            //cout << dp[i] << " ";
        }
        cout << maxi << "\n";
    }
    return 0;
}
/*
1
3
3 5 2
-1 1 1
-1 3 5
*/