#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    if (n>m || (n%2==0 && m%2)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        if (n%2) {
            for (int i=1; i<n; i++) cout << 1 << " ";
            cout << m-n+1 << "\n";
        } else {
            for (int i=1; i<=n-2; i++) cout << 1 << " ";
            int x=(m-(n-2))/2;
            cout << x << " " << x << "\n";
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