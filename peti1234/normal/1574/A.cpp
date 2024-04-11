#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<n; j++) {
                cout << "(";
            }
            for (int j=1; j<=n; j++) {
                if (i==j) {
                    cout << "(";
                }
                cout << ")";
            }
            cout << "\n";
        }
    }
    return 0;
}