#include <bits/stdc++.h>

using namespace std;
int n, p, x=1e9, y, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        x=min(x, max(a, b));
        y=max(y, min(a, b));
    }
    if (x<y) {
        cout << -1 << "\n";
    } else {
        if (y<=p && p<=x) {
            cout << 0 << "\n";
        } else {
            cout << min(abs(p-x), abs(p-y)) << "\n";
        }
    }
    return 0;
}