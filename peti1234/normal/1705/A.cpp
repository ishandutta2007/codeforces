#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, x;
    vector<int> sz;
    cin >> n >> x;
    for (int i=0; i<2*n; i++) {
        int s;
        cin >> s;
        sz.push_back(s);
    }
    sort(sz.begin(), sz.end());
    bool jo=1;
    for (int i=0; i<n; i++) {
        if (sz[i]+x>sz[i+n]) jo=0;
    }
    cout << (jo ? "YES" : "NO") << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}