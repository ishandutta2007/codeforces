#include<bits/stdc++.h>

using namespace std;
#define int long long
const int max_n = 104;
bool used[max_n];
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int n, k;
    cin >> n;
    int l[n], r[n];
    for(int i = 0;i < n;i++) cin >> l[i] >> r[i];
    cin >> k;
    int ans = 0;
    for(int i = 0;i < n;i++) {
        if (r[i] >= k) ans++;
    }
    cout << ans;
}