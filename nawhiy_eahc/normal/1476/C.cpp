#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[100002], b[100002], c[100002], dp[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) cin >> c[i];
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        a[n+1] = b[n+1] = c[n+1] = 0;

        ll ans = 0;
        dp[1] = abs(b[2] - a[2]) + 1;

        for(int i=2;i<=n;i++){
            ans = max(ans, dp[i-1] + c[i]);

            if(a[i+1] == b[i+1]) dp[i] = 1;
            else dp[i] = max(dp[i-1] + c[i] - abs(a[i+1] - b[i+1]) + 1, abs(a[i+1] - b[i+1]) + 1);
        }

        cout << ans << "\n";
    }
}