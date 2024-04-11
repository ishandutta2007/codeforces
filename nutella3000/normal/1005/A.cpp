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
    int a[n + 1];
    for(int i = 0;i < n;i++) cin >> a[i];
    a[n] = -1;
    vector<int> ans;
    for(int i = 1;i <= n;i++) {
        if (a[i] != a[i - 1] + 1) ans.emplace_back(a[i - 1]);
    }
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << " ";
}