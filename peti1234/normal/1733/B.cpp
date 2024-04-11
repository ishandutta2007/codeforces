#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if (x>y) swap(x, y);
    if (x>0 || y==0 ||(n-1)%y) cout << -1 << "\n";
    else {
        int ert=2;
        for (int i=1; i<n; i++) {
            cout << ert << " ";
            if (i%y==0) ert+=y;
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