#include <bits/stdc++.h>

using namespace std;
int n, x, y, t[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        bool jo=1;
        for (int j=max(1, i-x); j<i; j++) {
            if (t[j]<t[i]) {
                jo=0;
            }
        }
        for (int j=i+1; j<=min(n, i+y); j++) {
            if (t[j]<t[i]) {
                jo=0;
            }
        }
        if (jo) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}