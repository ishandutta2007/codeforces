#include <bits/stdc++.h>

using namespace std;
int w, n, t[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        bool jo=1;
        for (int i=1; i<n; i++) {
            if (t[i]>t[i+1]) {
                jo=0;
            }
        }
        if (jo) {
            cout << 0 << "\n";
            continue;
        }
        if (t[n]<t[n-1] || t[n]<0) {
            cout << -1 << "\n";
            continue;
        }
        cout << n-2 << "\n";
        for (int i=1; i<=n-2; i++) {
            cout << i << " " << n-1 << " " << n << "\n";
        }
    }
    return 0;
}