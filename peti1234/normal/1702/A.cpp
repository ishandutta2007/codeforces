#include <bits/stdc++.h>

using namespace std;
void solve() {
    int x;
    cin >> x;
    int ert=1;
    while (10*ert<=x) ert*=10;
    cout << x-ert << "\n";
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