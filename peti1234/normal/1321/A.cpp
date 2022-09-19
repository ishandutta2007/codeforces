#include <bits/stdc++.h>

using namespace std;
int n, t[102], x, y;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        int p;
        cin >> p;
        if (t[i]!=p) {
            if (t[i]) {
                x++;
            } else {
                y++;
            }
        }
    }
    if (!x) {
        cout << -1 << "\n";
    } else {
        for (int i=1; i<=n; i++) {
            if (x*i>y) {
                cout << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}