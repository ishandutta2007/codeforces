#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, t[c];
set<int> s;
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    int ans=0;
    for (int i=n; i>=1; i--) {
        if (s.find(t[i])!=s.end()) {
            ans=i;
            break;
        }
        s.insert(t[i]);
    }
    s.clear();
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