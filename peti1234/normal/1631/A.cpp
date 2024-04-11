#include <bits/stdc++.h>

using namespace std;
int w, n, a[105], b[105], x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
        }
        for (int i=1; i<=n; i++) {
            x=max(x, max(a[i], b[i]));
            y=max(y, min(a[i], b[i]));
        }
        cout << x*y << "\n";
        x=0, y=0;
    }
    return 0;
}