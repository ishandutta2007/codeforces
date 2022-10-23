#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, ans=1e9;
    vector<int> sz;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
    }
    sort(sz.begin(), sz.end());
    for (int i=2; i<n; i++) {
        ans=min(ans, sz[i]-sz[i-2]);
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}