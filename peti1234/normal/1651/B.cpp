#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        if (n>19) cout << "NO\n";
        else {
            cout << "YES\n";
            int ert=1;
            for (int i=1; i<=n; i++) {
                cout << ert << " ";
                ert*=3;
            }
            cout << "\n";
        }
    }
    return 0;
}