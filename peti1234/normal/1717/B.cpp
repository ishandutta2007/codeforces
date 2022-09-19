#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << ((r-i+j-c)%k==0 ? "X" : ".");
        }
        cout << "\n";
    }
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