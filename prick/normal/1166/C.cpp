#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(a.begin(), a.end());
    
    int p = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (p < i && a[p] * 2 < a[i]) ++p;
        ans += i - p;
    }
    cout << ans << '\n';
}