#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, p[105];
    cin >> n;
    for (int i=1; i<=n; i++) {
        p[i]=i;
    }
    cout << n << "\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << p[j] << " ";
        }
        cout << "\n";
        if (i<n) {
            swap(p[i], p[i+1]);
        }
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