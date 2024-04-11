#include <bits/stdc++.h>

using namespace std;
const int c=202;
int n, m, a[c], b[c];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> b[i];
    for (int k=0; ; k++) {
        int x=0, y=0;
        for (int i=1; i<=n; i++) {
            y=0;
            for (int j=1; j<=m; j++) if ((k|(a[i]&b[j]))==k) y++;
            if (!y) x++;
        }
        if (!x) {
            cout << k << "\n";
            return 0;
        }
    }
    return 0;
}