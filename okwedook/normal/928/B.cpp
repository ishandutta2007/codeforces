#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1, 0);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    for (int i = 1; i <= n; ++i) {
        int left = max(1, i - k), right = min(n, i + k);
        int pright = arr[i] ? min(n, arr[i] + k) + 1 : 0;
        if (pright > left) left = pright;
        dp[i] = dp[arr[i]] + right - left + 1;
    }
    for (int i = 1; i <= n; ++i) cout << dp[i] << ' ';
    return 0;
}