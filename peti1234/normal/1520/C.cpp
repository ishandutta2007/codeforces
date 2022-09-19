#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        if (n==2) {
            cout << -1 << "\n";
            continue;
        }
        int ert=1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << ert << " ";
                ert+=2;
                if (ert>n*n) {
                    ert=2;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}