#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 1e2 + 5;
int a[maxn], b[maxn], dp[10010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n; i++) {
            if(a[i] > b[i]) swap(a[i], b[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++) sum += b[i]-a[i];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = sum/2; j >= b[i]-a[i]; j--) dp[j] = max(dp[j], dp[j-(b[i]-a[i])]);
        }
        long long ans = 0, s = 0;
        for(int i = 0; i < n; i++) s += a[i];
        for(int i = 0; i < n; i++) {
            ans += (n-2) * a[i] * a[i] + (n-2) * b[i] * b[i];
        }
        int x = sum/2;
        while(dp[x] == 0) x--;
        ans += (s+x) * (s+x) + (s+sum-x) * (s+sum-x);
        cout << ans << endl;
    }
    return 0;
}