#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
    }
    n=10-n;
    cout << n*(n-1)*3 << endl;
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