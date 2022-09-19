#include <bits/stdc++.h>

using namespace std;
int w, n, k;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> k;
        if (n%2 && k>1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int ert=1;
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=k; j++) {
                    cout << ert << " ";
                    ert+=2;
                    if (ert>n*k) ert=2;
                }
                cout << "\n";
            }
        }
    }
    return 0;
}