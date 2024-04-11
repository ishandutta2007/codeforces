#include <bits/stdc++.h>

using namespace std;
int n, k, t[105], db;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        if (t[i]<=k) {
            db++;
        } else {
            break;
        }
    }
    if (db!=n) {
        for (int i=n; i>=1; i--) {
            if (t[i]<=k) {
                db++;
            } else {
                break;
            }
        }
    }
    cout << db << "\n";
    return 0;
}