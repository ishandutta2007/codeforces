#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for(int i = 1;i < n;i += 2) {
        ans += a[i] - a[i - 1];
    }
    cout << ans;
}