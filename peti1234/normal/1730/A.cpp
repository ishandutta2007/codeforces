#include <bits/stdc++.h>

using namespace std;
map<int, int> m;
void solve() {
    int n, k, ans=0;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    for (auto p:m) {
        ans+=min(p.second, k);
    }
    cout << ans << "\n";
    m.clear();
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